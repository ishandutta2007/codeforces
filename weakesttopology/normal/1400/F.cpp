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

template<int K = 26, char d = 'a'>
struct AhoCorasick
{
    struct Node
    {
        int nxt[K], go[K];
        bool leaf = false;
        int p = -1, link = -1, leaflink = -1;
        char pc;
        Node(int p = -1, char pc = d - 1) : p(p), pc(pc)
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
            int v = trie[u].nxt[c - d];
            if (v == -1)
            {
                v = size(trie);
                trie.emplace_back(u, c);
            }
            u = trie[u].nxt[c - d] = v;
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
        int idx = c - d;
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

constexpr int N = 20;

bool isxprime(const string& s, int x)
{
    int prefix[N] = { 0 };

    for (int i = 0; i < size(s); ++i)
        prefix[i] = (s[i] - '0') + (i > 0 ? prefix[i - 1] : 0);

    auto query = [&](int l, int r)
    {
        if (l == 0) return prefix[r];
        else return prefix[r] - prefix[l - 1];
    };

    for (int i = 0; i < size(s); ++i)
        for (int j = i; j < size(s); ++j)
            if (x % query(i, j) == 0 && query(i, j) != x)
                return false;

    return true;
}

void generate(auto& aha, int x, string prefix = "", int sum = 0)
{
    if (x == sum)
    {
        if (isxprime(prefix, x)) aha.add(prefix);
        return;
    }
    for (int d = 1; d <= min(x - sum, 9); ++d)
        generate(aha, x, prefix + char('0' + d), sum + d);
}

bool chmin(auto& x, auto y) { return y < x ? x = y, true : false; }

int main()
{ _
    string s; cin >> s;

    int x; cin >> x;

    AhoCorasick<9, '1'> aha;

    generate(aha, x);

    int n = size(aha.trie);

    vector good(n, 0);

    for (int u = 0; u < n; ++u)
        good[u] = (aha.getleaf(u) == 0);

    vector dp(n, INF), dpnxt(n, INF);

    dp[0] = 0;

    for (auto c : s)
    {
        for (int u = 0; u < n; ++u) if (dp[u] < INF)
        {
            chmin(dpnxt[u], dp[u] + 1);

            int v = aha.go(u, c);

            if (good[v]) chmin(dpnxt[v], dp[u]);
        }

        fill(all(dp), INF);

        swap(dp, dpnxt);
    }

    int ans = INF;

    for (int u = 0; u < n; ++u) chmin(ans, dp[u]);

    cout << ans << endl;

    exit(0);
}