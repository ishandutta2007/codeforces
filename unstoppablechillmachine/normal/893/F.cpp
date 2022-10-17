#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
//#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define endl "\n"

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

struct segment_tree {
    vector<pair<int, int> > hs;
    vector<vector<int> > sparse;
};

const int N = 2e5 + 10;

segment_tree t[4 * N];
bool used[N];
int d[N], t_in[N], t_out[N], a[N], dp[N], timer = 0, mx = 0;
vector<pair<int, int> > arr[N];
vector<vector<int> > g;
_ void dfs(int v, int cur) {
    used[v] = true;
    d[v] = cur;
    mx = max(mx, cur);
    timer++;
    t_in[v] = timer;
    arr[cur].pb(mk(t_in[v], a[v]));
    for (auto u : g[v]) {
        if (!used[u]) {
            dfs(u, cur + 1);
        }
    }
    timer++;
    t_out[v] = timer;
}

_ vector<pair<int, int> > merge(vector<pair<int, int> > &a, vector<pair<int, int> > &b) {
    int j = 0, jj = 0, n1 = a.size(), n2 = b.size();
    vector<pair<int, int> > res;
    while (j < n1 && jj < n2) {
        if (a[j].f < b[jj].f) {
            res.pb(a[j]);
            j++;
        }
        else {
            res.pb(b[jj]);
            jj++;
        }
    }
    while (j < n1) {
        res.pb(a[j]);
        j++;
    }
    while (jj < n2) {
        res.pb(b[jj]);
        jj++;
    }
    return res;
}

_ vector<vector<int> > get_sparse(vector<pair<int, int> > &arr) {
    int n = arr.size(), l = dp[n];
    vector<vector<int> > res(n);
    for (int i = 0; i < n; i++) {
        res[i].rsz(l + 1);
        fill(all(res[i]), INF);
        res[i][0] = arr[i].sec;
    }
    for (int i = 1; i <= l; i++) {
        int cur = (1 << (i - 1)), lim = n - 2 * cur + 1;
        for (int j = 0; j < lim; j++) {
            res[j][i] = min(res[j][i - 1], res[j + cur][i - 1]);
        }
    }
    return res;
}

_ void relax(int v) {
    t[v].hs = merge(t[2 * v].hs, t[2 * v + 1].hs);
    t[v].sparse = get_sparse(t[v].hs);
}

_ void build(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
        return;
    }
    if (l == r) {
        t[v].hs = arr[l];
        t[v].sparse = get_sparse(arr[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid, a, b);
    build(2 * v + 1, mid + 1, r, a, b);
    relax(v);
}

int query(int v, int l, int r) {
    int kk = dp[r - l + 1];
    return min(t[v].sparse[l][kk], t[v].sparse[r - (1 << kk) + 1][kk]);
}

int get(int v, int l, int r, int a, int b, int pp) {
    if (l > b || r < a) {
        return INF;
    }
    if (l >= a && r <= b) {
        //cout << "QUERY " << l << " " << r << " ";
        int left = lower_bound(all(t[v].hs), mk(t_in[pp], 1)) - t[v].hs.begin(),
        right = lower_bound(all(t[v].hs), mk(t_out[pp] + 1, 1)) - t[v].hs.begin() - 1;
        //cout << left << ' ' << right << endl;
        if (left > right) {
            return INF;
        }
        return query(v, left, right);
    }
    int mid = (l + r) / 2;
    return min(get(2 * v, l, mid, a, b, pp), get(2 * v + 1, mid + 1, r, a, b, pp));
}

_ void source() {
    dp[1] = 0;
    for (int i = 2; i < N; i++) {
        dp[i] = dp[i / 2] + 1;
    }
    int n, root;
    cin >> n >> root;
    g.rsz(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        g[v].pb(u);
        g[u].pb(v);
    }
    dfs(root, 1);
    for (int i = 1; i <= mx; i++) {
        sort(all(arr[i]));
    }
    build(1, 1, n, 1, n);
    int m, ans = 0;
    cin >> m;
    vector<int> p(m + 1), q(m + 1);
    for (int i = 1; i <= m; i++) {
        //int vv, kkk;
        //cin >> vv >> kkk;
        cin >> p[i] >> q[i];
        int vv = (p[i] + ans) % n + 1, kkk = (q[i] + ans) % n;
        //cout << vv << " " << kkk << " " << d[vv] << " " << d[vv] + kkk << endl;
        ans = get(1, 1, n, d[vv], d[vv] + kkk, vv);
        ans = min(ans, a[vv]);
        cout << ans << endl;
    }
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    source();
    return 0;
}