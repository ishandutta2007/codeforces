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

template<int K = 26, char offset = 'a'>
struct SuffixAutomaton
{
    struct State
    {
        int link, len, minlen, idx;
        int nxt[K];
        bool terminal = false, clone = false;
        State(int link = -1, int len = 0) : link(link), len(len) { fill(all(nxt), -1); }
    };
    vector<State> state = { State() };

    int last = 0, total_size = 0;
    void extend(char c)
    {
        int cur = size(state), u = last, len = state[last].len + 1, ch = c - offset;

        for (;u != -1 && state[u].nxt[ch] == -1; u = state[u].link)
            state[u].nxt[ch] = cur;

        last = cur;

        if (u == -1)
        {
            state.emplace_back(0, len);
        }
        else if (int v = state[u].nxt[ch]; state[u].len + 1 == state[v].len)
        {
            state.emplace_back(v, len);
        }
        else
        {
            int clone = cur + 1;
            state.emplace_back(clone, len);
            state.push_back(state[v]);

            state[clone].len = state[u].len + 1, state[clone].clone = true;
            state[v].link = clone, state[v].minlen = state[clone].len + 1;

            for (int p = u; p != -1 && state[p].nxt[ch] == v; p = state[p].link)
                state[p].nxt[ch] = clone;
        }

        state[cur].minlen = state[state[cur].link].len + 1;
        state[cur].idx = total_size++;
    }

    SuffixAutomaton(const string& s)
    {
        for (auto c : s) extend(c);
        for (int v = last; v != -1; v = state[v].link)
            state[v].terminal = true;
    }

    int go(int u, char c) const
    {
        return state[u].nxt[c - offset];
    }
};

void solve()
{
    int n, k; cin >> n >> k;

    string s; cin >> s;

    for (int i = 0; i < n; ++i) s[i] = char('0' + ('1' - s[i]));

    SuffixAutomaton<2, '0'> aut(s);

    const auto& st = aut.state;

    int m = size(st);

    vector<int> V(m); iota(all(V), 0);
    sort(all(V), [&st](int u, int v){ return st[u].len > st[v].len; });

    vector<int> dp(m, INF);

    for (auto u : V)
    {
        for (char ch = '0'; ch <= '1'; ++ch)
        {
            int v = aut.go(u, ch);
            dp[u] = v == -1 ? 1 : min(dp[u], dp[v] + 1);
        }
    }

    if (dp[0] > k)
    {
        cout << "NO" << endl;
    }
    else
    {
        string ans;
        for (int u = 0; u != -1;)
        {
            for (char ch = '0'; ch <= '1'; ++ch)
            {
                int v = aut.go(u, ch);
                if (v == -1 || size(ans) + dp[v] + 1 <= k)
                {
                    ans += ch, u = v;
                    break;
                }
            }
        }
        ans += string(k - size(ans), '0');
        cout << "YES" << endl;
        cout << ans << endl;
    }
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}