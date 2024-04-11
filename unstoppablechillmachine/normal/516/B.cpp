#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 2010;
char arr[N][N];
pair<int, int> par[N * N];
int f[N][N], ans[N][N], sz[N][N];

_ void source() {
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '.') {
                cnt++;
                par[cnt] = {i, j};
                f[i][j] = cnt;
            }
        }
    }
    vector<pair<int16_t, int16_t> > have_l;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == '*') {
                continue;
            }
            if (i < n && arr[i + 1][j] == '.') {
                sz[i][j]++;
            }
            if (i > 1 && arr[i - 1][j] == '.') {
                sz[i][j]++;
            }
            if (j < m && arr[i][j + 1] == '.') {
                sz[i][j]++;
            }
            if (j > 1 && arr[i][j - 1] == '.') {
                sz[i][j]++;
            }
            if (sz[i][j] == 1) {
                have_l.pb({i, j});
            }
        }
    }
    int sum = 0;
    vector<pair<int, int> > delta = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    while (!have_l.empty()) {
        pair<int16_t, int16_t> cur = have_l.back();
        have_l.pop_back();
        if (sz[cur.f][cur.sec] != 1) {
            continue;
        }
        pair<int16_t, int16_t> u;
        for (auto it : delta) {
            pair<int16_t, int16_t> to = {cur.f + it.f, cur.sec + it.sec};
            if (!ans[to.f][to.sec] && arr[to.f][to.sec] == '.') {
                u = to;
                break;
            }
        }
        sum++;
        ans[cur.f][cur.sec] = ans[u.f][u.sec] = sum;
        sz[cur.f][cur.sec] = 0;
        sz[u.f][u.sec] = 0;
        for (auto it : delta) {
            pair<int16_t, int16_t> p = {u.f + it.f, u.sec + it.sec};
            sz[p.f][p.sec]--;
            if (sz[p.f][p.sec] == 1) {
                have_l.pb(p);
            }
        }
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }*/
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == '.' && !ans[i][j]) {
                cout << "Not unique";
                exit(0);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == '*') {
                cout << '*';
                continue;
            }
            if (ans[i][j] == ans[i + 1][j]) {
                cout << '^';
            }
            else if (ans[i][j] == ans[i - 1][j]) {
                cout << 'v';
            }
            else if (ans[i][j] == ans[i][j + 1]) {
                cout << '<';
            }
            else {
                cout << '>';
            }
        }
        cout << '\n';
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
    source();
    return 0;
}