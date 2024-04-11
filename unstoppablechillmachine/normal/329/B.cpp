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

const int N = 1010;
bool used[N][N];
char arr[N][N];
int dist[N][N];

_ void source() {
    int n, m;
    cin >> n >> m;
    pair<int, int> start, finish;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') {
                start = {i, j};
            }
            if (arr[i][j] == 'E') {
                finish = {i, j};
            }
        }
    }
    queue<pair<int, int> > q;
    q.push(finish);
    used[finish.f][finish.sec] = true;
    vector<pair<int, int> > delta = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (auto it : delta) {
            pair<int, int> to = {cur.f + it.f, cur.sec + it.sec};
            if (to.f < 1 || to.sec < 1 || to.f > n || to.sec > m || arr[to.f][to.sec] == 'T') {
                continue;
            }
            if (!used[to.f][to.sec]) {
                used[to.f][to.sec] = true;
                dist[to.f][to.sec] = dist[cur.f][cur.sec] + 1;
                q.push(to);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] >= '0' && arr[i][j] <= '9' && dist[i][j] <= dist[start.f][start.sec] && used[i][j]) {
                ans += arr[i][j] - '0';
            }
        }
    }
    cout << ans;
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