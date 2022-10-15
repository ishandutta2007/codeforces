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
        bool clone = false;
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
    }

    int go(int u, char c) const
    {
        return state[u].nxt[c - offset];
    }
};

int main()
{ _
    string s;
    cin >> s;

    SuffixAutomaton aut(s);
    const auto& st = aut.state;
    int m = size(st);

    vector<int> V(m - 1, 0);
    iota(all(V), 1);
    sort(all(V), [&st](int u, int v){ return st[u].len > st[v].len; });

    vector<int> dp(m, 0);
    for (auto u : V)
    {
        dp[u] += not st[u].clone;
        int v = st[u].link;
        dp[v] += dp[u];
    }

    int q;
    cin >> q;

    for (int z = 0; z < q; ++z)
    {
        string t;
        cin >> t;
        int n = size(t);

        set<int> S;
        for (int j = 0, u = 0, len = 0; j < 2 * n - 1; ++j)
        {
            while (u != 0 && aut.go(u, t[j % n]) == -1) u = st[u].link, len = st[u].len;
            int v = aut.go(u, t[j % n]);
            if (v != -1) u = v, len += 1;
            while (u != 0 && st[st[u].link].len >= n) u = st[u].link, len = st[u].len;
            if (len >= n) S.insert(u);
        }

        int res = 0;
        for (auto u : S) res += dp[u];

        cout << res << endl;
    }

    exit(0);
}