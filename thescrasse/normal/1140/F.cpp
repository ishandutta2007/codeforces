#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (int)1e9
#define mod 998244353
#define maxn 300010
#define maxs 1048586
#define ub 300010

int i, i1, j, k, k1, t, n, m, flag[10], a, b, x[maxn];
int y[maxn], pr[maxn], sz[maxn], sr[maxn], sc[maxn];
ll res, rs[maxn];
map<array<int, 2>, int> nc;
vector<int> st[maxs], rp[maxn];
stack<int> rd[maxn], cd[maxn];
stack<array<int, 4>> rb;

int find(int x) {
    if (pr[x] == x) return x;
    return find(pr[x]);
}

bool same(int a, int b) {
    return (find(a) == find(b));
}

void onion(int a, int b, int ty, int p) {
    // cout << "onion " << a _ b _ ty _ p << nf;
    a = find(a); b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    pr[b] = a; sz[a] += sz[b];
    if (ty != 2) res -= ((ll)sr[a] * sc[a] + sr[b] * sc[b]);
    sr[a] += sr[b]; sc[a] += sc[b];
    if (ty != 1) sr[a]--;
    if (ty != 0) sc[a]--;
    if (ty != 2) res += ((ll)sr[a] * sc[a]);
    rb.push({p, a, b, ty});
    // cout << "res, sr, sc = " << res _ sr[a] _ sc[a] _ sr[b] _ sc[b] << nl;
}

void unonion(int a, int b, int ty) {
    // cout << "unonion " << a _ b _ ty << nf;
    pr[b] = b; sz[a] -= sz[b];
    if (ty != 2) res -= ((ll)sr[a] * sc[a]);
    if (ty != 1) sr[a]++;
    if (ty != 0) sc[a]++;
    sr[a] -= sr[b]; sc[a] -= sc[b];
    if (ty != 2) res += ((ll)sr[a] * sc[a] + sr[b] * sc[b]);
    // cout << "res = " << res << nl;
}

void ins(int p, int tl, int tr, int l, int r, int x) {
    // cout << "ins " << p _ tl _ tr _ l _ r _ x << nf;
    if (l > r) return;
    if (tl == l && tr == r) {
        st[p].pb(x); return;
    }
    int tm = (tl + tr) / 2;
    ins(2 * p, tl, tm, l, min(r, tm), x);
    ins(2 * p + 1, tm + 1, tr, max(l, tm + 1), r, x);
}

void dfs(int p, int tl, int tr) {
    int a, b, ri = 0;

    // if (!st[p].empty()) cout << "dfs " << p _ tl _ tr << nf;

    for (auto u : st[p]) {
        a = rd[x[u]].top(); b = cd[y[u]].top();
        // cout << "u, a, b = " << u _ a _ b << nl;
        /* for (auto u : rd[x[u]]) cout << u << ' ';
        cout << nl;
        for (auto u : cd[y[u]]) cout << u << ' ';
        cout << nl; */
        if (a == INF && b == INF) {
            res++; ri++;
        } else if (a == INF) {
            onion(u, b, 1, p); res++; ri++;
        } else if (b == INF) {
            onion(u, a, 0, p); res++; ri++;
        } else if (!same(a, b)) {
            // cout << "find = " << a _ b _ find(a) _ find(b) << nl;
            onion(u, a, 0, p); onion(u, b, 1, p); res++; ri++;
        } else {
            onion(u, a, 2, p);
        }
        rd[x[u]].push(u); cd[y[u]].push(u);
    }

    if (tl < tr) {
        int tm = (tl + tr) / 2;
        dfs(2 * p, tl, tm);
        dfs(2 * p + 1, tm + 1, tr);
    }

    if (tl == tr && tl >= 1 && tl <= n) rs[tl] = res;

    while (!rb.empty()) {
        array<int, 4> o = rb.top();
        if (o[0] != p) break;
        rb.pop();
        unonion(o[1], o[2], o[3]);
    }
    res -= ri;

    for (auto u : st[p]) {
        rd[x[u]].pop(); cd[y[u]].pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        if (nc[{x[i], y[i]}] == 0) nc[{x[i], y[i]}] = i;
    }

    for (i = 1; i <= n; i++) {
        pr[i] = i; sz[i] = 1; sr[i] = 1; sc[i] = 1;
        rd[x[i]].push(INF); cd[y[i]].push(INF);
        rp[nc[{x[i], y[i]}]].pb(i);
    }

    for (i = 1; i <= n; i++) {
        if (rp[i].size() % 2) rp[i].pb(n + 1);
        for (j = 0; j < rp[i].size(); j += 2) {
            // cout << "ins init " << rp[i][j] _ rp[i][j + 1] - 1 _ i << nf;
            ins(1, 0, ub, rp[i][j], rp[i][j + 1] - 1, i);
        }
    }

    dfs(1, 0, ub);

    for (i = 1; i <= n; i++) cout << rs[i] << ' ';
    cout << nl;

    return 0;
}