#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

//const int MAX_MEM = 1e8; int mpos = 0; char mem[MAX_MEM]; inline void * operator new ( size_t n ) { char *res = mem + mpos; mpos += n; assert(mpos <= MAX_MEM); return (void *)res; } inline void operator delete ( void * ) { }

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

const int N = 1010;
char arr[N][N];
int used[N][N], mn[4][N][N];
vector<pair<int, int> > delta = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
vector<pair<int, int> > have[4];
queue<pair<int, int> > q;

bool check(int a, int b) {
    for (auto it : delta) {
        int a2 = a + it.f, b2 = b + it.sec;
        if (arr[a2][b2] == '.') {
            return true;
        }
    }
    return false;
}

void dfs(int a, int b, int cnt) {
    used[a][b] = true;
    if (check(a, b)) have[cnt].pb({a, b});
    for (auto it : delta) {
        int a2 = a + it.f, b2 = b + it.sec;
        if (arr[a2][b2] >= '1' && arr[a2][b2] <= '3' && !used[a2][b2]) {
            dfs(a2, b2, cnt);
        }
    }
}

_ void source() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] >= '1' && arr[i][j] <= '3' && !used[i][j]) {
                cnt++;
                dfs(i, j, cnt);
            }
        }
    }
    if (cnt == 1) {
        cout << 0;
        exit(0);
    }
    for (int cur_comp = 1; cur_comp <= cnt; cur_comp++) {
        random_shuffle(all(have[cur_comp]));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                mn[cur_comp][i][j] = INF;
                used[i][j] = 0;
            }
        }
        int timer = 0;
        for (auto it : have[cur_comp]) {
            timer++;
            mn[cur_comp][it.f][it.sec] = 0;
            used[it.f][it.sec] = timer;
            q.push(it);
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                for (auto it : delta) {
                    pair<int, int> to = {cur.f + it.f, cur.sec + it.sec};
                    if (used[to.f][to.sec] < timer && (arr[to.f][to.sec] == '.' || (arr[to.f][to.sec] >= '1' && arr[to.f][to.sec] <= '3')) && mn[cur_comp][cur.f][cur.sec] + 1 < mn[cur_comp][to.f][to.sec]) {
                        mn[cur_comp][to.f][to.sec] = mn[cur_comp][cur.f][cur.sec] + 1;
                        used[to.f][to.sec] = timer;
                        if (arr[to.f][to.sec] == '.') q.push(to);
                    }
                }
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            bool t = true;
            int sum = 0;
            for (int k = 1; k <= cnt; k++) {
                if (mn[k][i][j] >= INF) {
                    t = false;
                    break;
                }
                sum += mn[k][i][j];
            }
            if (t) {
                ans = min(ans, sum - cnt + 1);
            }
        }
    }
    for (int cur_comp = 1; cur_comp <= cnt; cur_comp++) {
        int sum = 0;
        for (int i = 1; i <= cnt; i++) {
            if (cur_comp == i) {
                continue;
            }
            int cmn = INF;
            for (auto it : have[i]) {
                cmn = min(cmn, mn[cur_comp][it.f][it.sec]);
            }
            if (cmn == INF) {
                sum = INF;
                break;
            }
            sum += cmn - 1;
        }
        ans = min(ans, sum);
    }
    cout << (ans >= 1e9 ? -1 : ans);
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