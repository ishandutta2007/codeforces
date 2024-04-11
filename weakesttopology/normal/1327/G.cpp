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

template<typename T>
bool chmax(T& x, T y) { return x < y ? (x = y, true) : false; }

template<int K = 26, char offset = 'a'>
struct AhoCorasick
{
    struct Node
    {
        int nxt[K], go[K];
        bool leaf = false;
        int p = -1, link = -1, leaflink = -1, len = 0;
        char pc;
        Node(int p = -1, char pc = offset - 1) : p(p), pc(pc)
        {
            fill(all(nxt), -1), fill(all(go), -1);
        }
    };
    vector<Node> trie;

    AhoCorasick() : trie(1) { }

    int add(const string& s)
    {
        int u = 0;
        for (auto c : s)
        {
            int v = trie[u].nxt[c - offset];
            if (v == -1)
            {
                v = size(trie);
                trie.emplace_back(u, c);
                trie[v].len = trie[u].len + 1;
            }
            u = trie[u].nxt[c - offset] = v;
        }
        trie[u].leaf = true;
        trie[u].leaflink = u;
        return u;
    }
    int getlink(int v)
    {
        if (trie[v].link == -1)
        {
            if (v == 0 || trie[v].p == 0) trie[v].link = 0;
            else trie[v].link = go(getlink(trie[v].p), trie[v].pc);
        }
        return trie[v].link;
    }
    int go(int v, char c)
    {
        int idx = c - offset;
        if (trie[v].go[idx] == -1)
        {
            if (trie[v].nxt[idx] != -1) trie[v].go[idx] = trie[v].nxt[idx];
            else trie[v].go[idx] = (v == 0 ? 0 : go(getlink(v), c));
        }
        return trie[v].go[idx];
    }
    int getleaf(int v) // inclusive
    {
        if (trie[v].leaflink == -1)
        {
            if (v == 0 || trie[v].leaf) trie[v].leaflink = v;
            else trie[v].leaflink = getleaf(getlink(v));
        }
        return trie[v].leaflink;
    }
};

int main()
{ _
    constexpr int K = 'n' - 'a' + 1;
    AhoCorasick<K> aho;

    int k;
    cin >> k;

    const int max_len = 1000, max_states = max_len + 1;

    vector<ll> cost(max_states, 0);

    for (int j = 0; j < k; ++j)
    {
        string s;
        cin >> s;
        int u = aho.add(s), c;
        cin >> c;
        cost[u] += c;
    }

    int m = size(aho.trie);
    vector<int> st(m);
    iota(all(st), 0);
    sort(all(st), [&](int u, int v){ return aho.trie[u].len < aho.trie[v].len; });

    for (auto u : st)
    {
        int v = aho.getleaf(aho.getlink(u));
        if (v != 0) cost[u] += cost[v];
    }

    vector<vector<int>> cl(K + 1);

    for (int mask = 0; mask < (1 << K); ++mask)
    {
        int x = __builtin_popcount(mask);
        cl[x].push_back(mask);
    }

    vector<ll> dp((1 << K) * m, -LINF), dpnxt((1 << K) * m, -LINF), add(m, 0);

    auto id = [&](int u, int mask) { return mask * m + u; };
    dp[id(0, 0)] = 0;

    vector<int> p(m, 0);
    iota(all(p), 0);

    auto advance = [&](int mask)
    {
        for (int u = 0; u < m; ++u)
        {
            int idx = id(u, mask);
            dp[idx] = -LINF;
            swap(dp[idx], dpnxt[idx]);
        }
    };

    string s;
    cin >> s;
    int n = size(s), qt = 0;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] != '?')
        {
            for (int u = 0; u < m; ++u)
            {
                int v = aho.go(p[u], s[i]);
                add[u] += cost[v], p[u] = v;
            }
        }
        else
        {
            for (auto mask : cl[qt])
            {
                for (int u = 0; u < m; ++u) if (dp[id(u, mask)] > -LINF)
                {
                    chmax(dpnxt[id(p[u], mask)], dp[id(u, mask)] + add[u]);
                }
                advance(mask);
            }
            fill(all(add), 0), iota(all(p), 0);
            for (auto mask : cl[qt])
            {
                for (int j = 0; j < K; ++j) if ((mask >> j & 1) == 0)
                {
                    int newmask = mask ^ (1 << j);
                    for (int u = 0; u < m; ++u) if (dp[id(u, mask)] > -LINF)
                    {
                        int v = aho.go(u, 'a' + j);
                        chmax(dp[id(v, newmask)], dp[id(u, mask)] + cost[v]);
                    }
                }
            }
            qt += 1;
        }
    }

    ll res = -LINF;

    for (auto mask : cl[qt])
    {
        for (int u = 0; u < m; ++u)
        {
            chmax(res, dp[id(u, mask)] + add[u]);
        }
    }

    cout << res << endl;

    exit(0);
}