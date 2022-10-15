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

template<int K>
struct Node
{
    char c;
    int nxt[K];
    void reset() { fill(all(nxt), -1); }
    Node(char c = '*') : c(c) { reset(); } 
};

int main()
{ _
    int n;
    cin >> n;

    vector<int> c(n);
    for (auto& x : c) cin >> x;

    string s;
    cin >> s;

    vector<vector<int>> E(n);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<int> heavy(n, -1);
    auto find_heavy = [&](auto& self, int u, int p) -> int
    {
        int sum = 0, mx = 0;
        for (auto v : E[u]) if (v != p)
        {
            int cur = self(self, v, u);
            if (cur > mx) heavy[u] = v, mx = cur;
            sum += cur;
        }
        return sum + 1;
    };
    find_heavy(find_heavy, 0, -1);

    constexpr int K = 26;
    deque<Node<K>> trie(1, Node<K>('*'));

    auto add_char = [&](int rt, char c)
    {
        int& rtnxt = trie[rt].nxt[c - 'a'];
        if (rtnxt == -1)
        {
            rtnxt = size(trie);
            trie.emplace_back(c);
        }
        return rtnxt;
    };

    vector<int> cnt(n, 0);

    auto build_trie = [&](auto& self, int u, int p, int rt) -> void
    {
        int rtnxt = add_char(rt, s[u]);
        for (auto v : E[u]) if (v != p) self(self, v, u, rtnxt);
    };
    auto solve = [&](auto& self, int u, int p, int rt) -> void
    {
        int rtnxt = add_char(rt, s[u]);
        int m = size(trie);

        for (auto v : E[u]) if (v != p && v != heavy[u])
        {
            self(self, v, u, rtnxt);
            trie.resize(m);
            trie[m - 1].reset();
        }

        if (heavy[u] != -1) self(self, heavy[u], u, rtnxt);

        for (auto v : E[u]) if (v != p && v != heavy[u])
        {
            build_trie(build_trie, v, u, rtnxt);
        }

        cnt[u] = size(trie) - m + 1;
    };
    solve(solve, 0, -1, 0);

    int res = 0, ct = 0;

    for (int u = 0; u < n; ++u)
    {
        int cur = c[u] + cnt[u];
        if (cur > res) res = cur, ct = 0;
        ct += cur == res;
    }

    cout << res << endl << ct << endl;

    exit(0);
}