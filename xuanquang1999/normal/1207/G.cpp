#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400005;
const int K = 26;

struct BIT {
private:
    vector<int> t;
public:
    BIT(int n) {t.assign(n+1, 0);}

    void update(int p, int x) {
        for(int i = p; i < t.size(); i += i & (-i))
            t[i] += x;
    }

    int query(int p) {
        int res = 0;
        for(int i = p; i > 0; i -= i & (-i))
            res += t[i];
        return res;
    }
};

struct Vertex {
    int nxt[K];
    int p;
    char pch;
    int go[K];
    int link = -1;
    int leaf = -1;

    Vertex(int p = -1, char ch = '$'): p(p), pch(ch) {
        fill(begin(nxt), end(nxt), -1);
        fill(begin(go), end(go), -1);
    }
};

int n, m, in[MAXN], out[MAXN], dfs_cnt, ans[MAXN];
vector<pair<int, char>> g[MAXN];
vector<int> linkG[MAXN];
vector<Vertex> t(1);
vector<pair<int, int>> query[MAXN];

int add_string(string s, int ind) {
    int v = 0;
    for(char ch: s) {
        int c = ch-'a';
        if (t[v].nxt[c] == -1) {
            t[v].nxt[c] = t.size();
            t.push_back(Vertex(v, c));
        }
        v = t[v].nxt[c];
    }
    t[v].leaf = ind;
    return v;
}

int go(int v, int c);

int get_link(int v) {
    int &res = t[v].link;
    if (res == -1) {
        if (v == 0 || t[v].p == 0) res = 0;
        else res = go(get_link(t[v].p), t[v].pch);
    }
    return res;
}

int go(int v, int c) {
    int &res = t[v].go[c];
    if (res == -1) {
        if (t[v].nxt[c] != -1) res = t[v].nxt[c];
        else if (v == 0) res = 0;
        else res = go(get_link(v), c);
    }
    return res;
}

void dfs_link(int u) {
    in[u] = ++dfs_cnt;
    for(int v: linkG[u])
        dfs_link(v);
    out[u] = dfs_cnt;
}

void dfs_g(int u, int at_u, BIT &bit) {
    for(pair<int, int> p: query[u])
        ans[p.first] = bit.query(out[p.second]) - bit.query(in[p.second] - 1);

    for(auto e: g[u]) {
        int v = e.first;
        int c = e.second - 'a';
        int at_v = go(at_u, c);

        bit.update(in[at_v], 1);
        dfs_g(v, at_v, bit);
        bit.update(in[at_v], -1);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        int t, j;
        char c;
        scanf("%d", &t);
        if (t == 1) {
            scanf(" %c", &c);
            g[0].push_back({i, c});
        } else {
            scanf("%d %c", &j, &c);
            g[j].push_back({i, c});
        }
    }

    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        int u;
        string s;
        cin >> u >> s;
        query[u].push_back({i, add_string(s, i)});
    }

    for(int i = 1; i < t.size(); ++i)
        linkG[get_link(i)].push_back(i);

    dfs_link(0);

    BIT bit(t.size());
    dfs_g(0, 0, bit);

    for(int i = 0; i < m; ++i)
        printf("%d\n", ans[i]);

    return 0;
}