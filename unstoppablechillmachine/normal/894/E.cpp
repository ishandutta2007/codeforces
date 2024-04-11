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
#define int ll
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

const int N = 1e6 + 10;

vector<int> arr;
bool used[N], was[N];
vector<vector<int> > g, rev_g;
vector<vector<pair<int, int> > > g_cost;
unordered_map<int, int> cond[N];
int comp[N], ans[N], sum[N], f[N];
_ void dfs1(int v) {
    used[v] = true;
    for (auto u : g[v]) {
        if (!used[u]) {
            dfs1(u);
        }
    }
    arr.pb(v);
}

_ void dfs2(int v, int now_comp) {
    comp[v] = now_comp;
    for (auto u : rev_g[v]) {
        if (!comp[u]) {
            dfs2(u, now_comp);
        }
    }
}

_ int solve(int v) {
    was[v] = true;
    ans[v] = sum[v];
    int cur = 0;
    for (auto u : cond[v]) {
        if (!was[u.f]) {
            cur = max(cur, solve(u.f) + u.sec);
        }
        else {
            cur = max(cur, ans[u.f] + u.sec);
        }
    }
    ans[v] += cur;
    return ans[v];
}

_ int get(int x) {
    int l = 1, r = 1e5;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (mid * (mid - 1) / 2 <= x) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    return x * l - f[l];
}

_ void source() {
    int add = 0;
    f[1] = 0;
    for (int i = 2; i <= 1e5; i++) {
        add += (i - 1);
        f[i] = f[i - 1] + add;
    }
    int n, m;
    cin >> n >> m;
    g.rsz(n + 1);
    rev_g.rsz(n + 1);
    g_cost.rsz(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        g_cost[a].pb(mk(b, cost));
        g[a].pb(b);
        rev_g[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    reverse(all(arr));
    int now_comp = 0;
    for (auto v : arr) {
        if (!comp[v]) {
            now_comp++;
            dfs2(v, now_comp);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto u : g_cost[i]) {
            if (comp[i] == comp[u.f]) {
                sum[comp[i]] += get(u.sec);
            }
            else {
                cond[comp[i]][comp[u.f]] = max(cond[comp[i]][comp[u.f]], u.sec);
            }
        }
    }
    int start;
    cin >> start;
    cout << solve(comp[start]);
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