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
struct AhoCorasick
{
    struct Node
    {
        int nxt[K], go[K];
        bool leaf = false;
        int p = -1, link = -1, leaflink = -1, ct = 0;
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
            }
            u = trie[u].nxt[c - offset] = v;
        }
        trie[u].leaf = true;
        trie[u].leaflink = u;
        trie[u].ct += 1;
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
    string t; cin >> t;
    int n = size(t);

    AhoCorasick aha_forward, aha_reversed;

    int m; cin >> m;

    for (int j = 0; j < m; ++j)
    {
        string s; cin >> s;
        aha_forward.add(s);
        reverse(all(s));
        aha_reversed.add(s);
    }

    vector<int> ct_forward(n, 0), ct_reversed(n, 0);

    for (int i = 0, u = 0; i < n; ++i)
    {
        auto& aha = aha_forward;
        u = aha.go(u, t[i]);
        for (int v = aha.getleaf(u); v > 0; v = aha.getleaf(aha.getlink(v)))
            ct_forward[i] += aha.trie[v].ct;
    }

    for (int i = n - 1, u = 0; i >= 0; --i)
    {
        auto& aha = aha_reversed;
        u = aha.go(u, t[i]);
        for (int v = aha.getleaf(u); v > 0; v = aha.getleaf(aha.getlink(v)))
            ct_reversed[i] += aha.trie[v].ct;
    }

    ll ans = 0LL;

    for (int i = 0; i + 1 < n; ++i)
        ans += 1LL * ct_forward[i] * ct_reversed[i + 1];

    cout << ans << endl;

    exit(0);
}