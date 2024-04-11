#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;


mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const ll L = numeric_limits<char>::max() + 100LL, R = 1000000LL;
uniform_int_distribution<ll> random_base(L, R);

ll modpow(ll x, ll p, ll mod)
{
    ll res = 1LL;
    for (; p; p >>= 1, (x *= x) %= mod) if (p & 1) (res *= x) %= mod;
    return res;
}

template<ll mod>
struct StringHash
{
    inline static const ll base = random_base(rng) | 1;
    inline static vector<ll> power;

    static void extend(int n)
    {
        int m = size(power);
        if (m >= n) return;
        power.resize(n, 1LL);
        for (int i = max(m, 1); i < n; ++i) power[i] = power[i - 1] * base % mod;
    }

    vector<ll> h;

    StringHash(const string& s) : h(size(s))
    {
        extend(size(s));
        h[0] = s[0] + 1;
        for (int i = 1; i < size(s); ++i) h[i] = (base * h[i - 1] + s[i] + 1) % mod;
    }
    ll query(int i, int j) const
    {
        if (i == 0) return h[j];
        return (h[j] + (mod - (h[i - 1] * power[j - i + 1]) % mod)) % mod;
    }
    ll concat(ll prefix, int i, int j) const
    {
        return (prefix * power[j - i + 1] % mod + query(i, j)) % mod;
    }
    ll hashpow(ll hash, ll len, ll p)
    {
        ll res = 0LL, shift = modpow(base, len, mod);
        while (p > 0)
        {
            if (p & 1) res = (res * shift + hash) % mod;
            (hash *= (shift + 1)) %= mod, (shift *= shift) %= mod, p >>= 1;
        }
        return res;
    }
};

struct Cost
{
    int cnt, len;
    Cost(int cnt = 0, int len = 0) : cnt(cnt), len(len) { }
    bool operator<(const Cost& rhs) const
    {
        if (cnt != rhs.cnt) return cnt < rhs.cnt;
        else return len < rhs.len;
    }
};

// returns a vector scc where scc[u] == scc[v] iff
// u and v lie in the same strongly connected component
//
// these ids are already sorted topologically in reverse order
// i.e., scc's with 0 out-degree first
// it is guarenteed that 0 <= scc[u] < n for all u

auto tarjan(const auto& E)
{
    int timer = 0, ct = 0;

    enum State { unvisited = 0, active, visited };
    map<ll, State> state;

    map<ll, int> low, num, scc;
    stack<ll> stk;

    auto dfs = [&](auto& self, ll u) -> void
    {
        low[u] = num[u] = timer++, state[u] = active;
        stk.push(u);
        auto iter = E.find(u);
        if (iter != end(E)) for (auto v : iter->second)
        {
            if (state[v] == unvisited) self(self, v);
            if (state[v] == active) low[u] = min(low[u], low[v]);
        }
        if (low[u] == num[u])
        {
            do
            {
                ll v = stk.top(); stk.pop();
                scc[v] = ct, state[v] = visited;
            } while (not empty(stk) && num[stk.top()] >= num[u]);
            ++ct;
        }
    };

    for (const auto& [u, N] : E) if (not num.count(u)) dfs(dfs, u);

    return pair(scc, ct);
}

void fix_case(string& s)
{
    for (auto& c : s) c = (char)tolower(c);
}

int main()
{ _
    constexpr ll mod = 1e9 + 87;
    auto get_hash = [&](const string& s)
    {
        return StringHash<mod>(s).query(0, size(s) - 1);
    };

    int n;
    cin >> n;

    map<ll, vector<ll>> E;
    vector<ll> essay(n);
    map<ll, Cost> cost;

    auto add = [&](string& s)
    {
        fix_case(s);
        ll hash = get_hash(s);
        int cnt = 0;
        for (auto c : s) cnt += c == 'r';
        cost[hash] = Cost(cnt, size(s));
        E[hash];
        return hash;
    };

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        essay[i] = add(s);
    }

    int m;
    cin >> m;

    for (int j = 0; j < m; ++j)
    {
        string x, y;
        cin >> x >> y;
        ll hashx = add(x), hashy = add(y);
        E[hashx].push_back(hashy);
    }

    auto [scc, ctscc] = tarjan(E);

    vector<Cost> dp(n + 2 * m, Cost(INF, INF));
    vector<vector<int>> F(n + 2 * m);

    for (auto [hash, id] : scc)
    {
        dp[id] = min(dp[id], cost[hash]);
        for (auto v : E[hash]) F[id].push_back(scc[v]);
    }

    for (int u = 0; u < ctscc; ++u)
    {
        for (auto v : F[u]) dp[u] = min(dp[u], dp[v]);
    }

    ll cnt = 0, len = 0;

    for (int i = 0; i < n; ++i)
    {
        int id = scc[essay[i]];
        cnt += dp[id].cnt, len += dp[id].len;
    }

    cout << cnt << " " << len << endl;

    exit(0);
}