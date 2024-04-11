#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    void clear() { *this = hash_map_t(mod); }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 2e5 + 5;

struct edge_t { int u, v, next; } G[N << 1];

int head[N], fa[N], siz[N], wson[N], d[N], endpoint[N], top[N];
int n, tot, dep;

inline void addedge(int u, int v) {
    G[++tot] = (edge_t) {u, v, head[u]}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v]}, head[v] = tot;
}

inline int query1(int u) {
    cout << "d" << " " << u << endl;
    int ans; cin >> ans; return ans;
}

inline int query2(int u) {
    cout << "s" << " " << u << endl;
    int ans; cin >> ans; return ans;
}

void dfs1(int u, int f) {
    siz[u] = 1;
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == f) continue;
        d[v] = d[u] + 1; fa[v] = u;
        dfs1(v, u); siz[u] += siz[v];
        if(siz[v] > siz[wson[u]]) wson[u] = v;
    }
}

void dfs2(int u, int tp) {
    top[u] = tp;
    if(!endpoint[tp]) endpoint[tp] = u;
    else if(d[u] > d[endpoint[tp]]) endpoint[tp] = u;
    if(wson[u]) dfs2(wson[u], tp);
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa[u] || v == wson[u]) continue;
        dfs2(v, v);
    }
}

int jump(int u, int cnt) {
    while(cnt) u = fa[u], --cnt;
    return u;
}

int ans = -1;
void query(int u) {
    int pt = endpoint[top[u]];
    int len = query1(pt);
    if(len == 0) { ans = pt; return; }
    if(d[pt] - len == dep) { ans = jump(pt, len); return; }
    int up = (len + d[pt] - dep) / 2;
    int det = (len - d[pt] + dep) / 2;
    pt = jump(pt, up);
    pt = query2(pt);
    if(det == 1) { ans = pt; return; }
    query(pt);
}

int main() {
    read(n);
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        addedge(u, v);
    }
    dfs1(1, 0); dfs2(1, 1);
    dep = query1(1);
    query(1);
    cout << "!" << " " << ans << endl;
    return 0;
}
// Sth Fun