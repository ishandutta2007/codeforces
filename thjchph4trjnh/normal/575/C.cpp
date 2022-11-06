#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#define maxn 21
#define inf 1000000000
struct Hungary {
    int nx, ny, cost[maxn][maxn], fx[maxn], fy[maxn], maty[maxn], which[maxn], dist[maxn];
    bool used[maxn];
    void init(int _nx, int _ny) {
        nx = _nx; ny = _ny; memset(fx, 0, sizeof(fx)); memset(fy, 0, sizeof(fy)); memset(maty, 0, sizeof(maty)); memset(which, 0, sizeof(which));
        for (int i = 0; i <= nx; i++) for (int j = 0; j <= ny; j++) cost[i][j] = inf;
    }
    void add(int x, int y, int c) {cost[x][y] = c;}
    void update(int x) {
        int y0 = 0; maty[0] = x;
        for (int y = 0; y <= ny; y++) {dist[y] = inf + 1; used[y] = false;}
        do {
            used[y0] = true;
            int x0 = maty[y0], delta = inf + 1, y1;
            for (int y = 1; y <= ny; y++) if (!used[y]) {
                int curdist = cost[x0][y] - fx[x0] - fy[y];
                if (curdist < dist[y]) {
                    dist[y] = curdist;
                    which[y] = y0;
                }
                if (dist[y] < delta) {
                    delta = dist[y];
                    y1 = y;
                }
            }
            for (int y = 0; y <= ny; y++) if (used[y]) {
                fx[maty[y]] += delta;
                fy[y] -= delta;
            }
            else dist[y] -= delta;
            y0 = y1;
        }
        while (maty[y0] != 0);
        do {
            int y1 = which[y0];
            maty[y0] = maty[y1];
            y0 = y1;
        }
        while (y0);
    }
    Hungary operator = (const Hungary& tmp) {
        nx = tmp.nx; ny = tmp.ny;
        FOR(i, 0, maxn) {
            fx[i] = tmp.fx[i];
            fy[i] = tmp.fy[i];
            maty[i] = tmp.maty[i];
        }
        return tmp;
    }
} hungary;

int n;
int a[maxn][maxn];
int b[maxn][maxn];
int ans;

void go(int pos, int bit, int cnt) {
    Hungary tmp = hungary;
    FOR(i, 0, n) if (!bit) hungary.add(pos + 1, i + 1, -a[pos][i]); else hungary.add(pos + 1, i + 1, -b[pos][i]);
    hungary.update(pos + 1);
    if (pos == n - 1) {
        if (cnt == n >> 1) {
            int tot = 0;
            for (int y = 1; y <= hungary.ny; y++) {
                int x = hungary.maty[y];
                if (hungary.cost[x][y] < inf) tot -= hungary.cost[x][y];
            }
            ans = max(ans, tot);
        }
        hungary = tmp; FOR(i, 0, n) hungary.add(pos + 1, i + 1, inf);
        return;
    }
    if (cnt + n - pos - 2 >= n >> 1) go(pos + 1, 0, cnt);
    if (cnt + 1 <= n >> 1) go(pos + 1, 1, cnt + 1);
    hungary = tmp;
    FOR(i, 0, n) hungary.add(pos + 1, i + 1, inf);
}

void solve() {
    scanf("%d", &n);
    FOR(i, 0, n) FOR(j, 0, n) scanf("%d", &a[i][j]);
    FOR(i, 0, n) FOR(j, 0, n) scanf("%d", &b[i][j]);
    ans = 0;
    hungary.init(n, n); FOR(i, 0, n) hungary.add(1, i + 1, -a[0][i]);
    go(0, 0, 0);
    hungary.init(n, n); FOR(i, 0, n) hungary.add(1, i + 1, -b[0][i]);
    go(0, 1, 1);
    printf("%d", ans);
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}