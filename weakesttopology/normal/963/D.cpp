#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<int K = 26>
struct AhoCorasick
{
    struct Node
    {
        int nxt[K], go[K];
        bool leaf = false;
        int p = -1, link = -1, leaflink = -1;
        char pc;
        Node(int p = -1, char pc = '$') : p(p), pc(pc)
        {
            fill(all(nxt), -1), fill(all(go), -1);
        }
    };
    vector<Node> trie;
    function<int(char)> getid = [](char c) { return c - 'a'; };

    AhoCorasick() : trie(1) { }
    AhoCorasick(auto getid) : trie(1), getid(getid) { }

    int add(const string& s)
    {
        int u = 0;
        for (auto c : s)
        {
            int v = trie[u].nxt[getid(c)];
            if (v == -1)
            {
                v = size(trie);
                trie.emplace_back(u, c);
            }
            u = trie[u].nxt[getid(c)] = v;
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
    int getleaf(int v)
    {
        if (trie[v].leaflink == -1)
        {
            if (v == 0 || trie[v].leaf) trie[v].leaflink = v;
            else trie[v].leaflink = getleaf(getlink(v));
        }
        return trie[v].leaflink;
    }
    int go(int v, char c)
    {
        int idx = getid(c);
        if (trie[v].go[idx] == -1)
        {
            if (trie[v].nxt[idx] != -1) trie[v].go[idx] = trie[v].nxt[idx];
            else trie[v].go[idx] = (v == 0 ? 0 : go(getlink(v), c));
        }
        return trie[v].go[idx];
    }
};

int main()
{ _
    string s; cin >> s;

    int q; cin >> q;

    vector Q(q, tuple(0, string(""), 0));

    AhoCorasick aha;

    for (auto& [k, m, v] : Q)
    {
        cin >> k >> m;
        v = aha.add(m);
    }

    vector I(size(aha.trie), vector(0, 0));

    for (int u = 0, i = 0; i < size(s); ++i)
    {
        u = aha.go(u, s[i]);

        for (int v = aha.getleaf(u); v > 0; v = aha.getleaf(aha.getlink(v)))
            I[v].push_back(i);
    }

    for (auto& [k, m, v] : Q)
    {
        int ans = INF;

        for (int j = k - 1; j < size(I[v]); ++j)
            ans = min(ans, I[v][j] - I[v][j - (k - 1)] + size(m));

        if (ans == INF) ans = -1;

        cout << ans << endl;
    }

    exit(0);
}