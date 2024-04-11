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

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const long double PI = acos(-1);

const int N = 3e5 + 10;
int used[N], p[N], f[N];
vector<vector<int> > g;

void dfs(int v, int prev) {
    used[v] = 1;
    p[v] = prev;
    for (auto u : g[v]) {
        if (!used[u]) {
            dfs(u, v);
        }
        else if (used[u] == 1 && u != prev) {
            int cur = v;
            int mn = min(u, v), mx = max(u, v);
            while (cur != u) {
                cur = p[cur];
                mn = min(mn, cur);
                mx = max(mx, cur);
            }
            f[mn] = mx;
        }
    }
    used[v] = 2;
}

_ void source() {
    int n, m;
    cin >> n >> m;
    g.rsz(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i, 0);
        }
    }
    vector<int> suf(n + 1, 0);
    if (f[n]) {
        suf[n] = n - 1;
    }
    else {
        suf[n] = n;
    }
    for (int i = n - 1; i >= 1; i--) {
        if (f[i]) {
            suf[i] = min(f[i] - 1, suf[i + 1]);
        }
        else {
            suf[i] = suf[i + 1];
        }
    }
    /*for (int i = 1; i <= n; i++) {
        cout << suf[i] << ' ';
    }
    cout << endl;*/
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + suf[i] - i + 1;
    }
    /*for (int i = 1; i <= n; i++) {
        cout << pref[i] << ' ';
    }
    cout << endl;*/
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        int ind = lower_bound(all(suf), r) - suf.begin();
        //cout << ind << endl;
        if (ind > r) {
            cout << pref[r] - pref[l - 1] << endl;
        }
        else if (l >= ind) {
            cout << (r - l + 1) * (r - l + 2) / 2 << endl;
        }
        else {
            cout << pref[ind - 1] - pref[l - 1] + (r - ind + 2) * (r - ind + 1) / 2 << endl;
        }
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