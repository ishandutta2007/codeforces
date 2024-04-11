#include <bits/stdc++.h>
#define LL long long
//#define pil pair <int, LL>
#define pll pair <LL, LL>
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 1100, M = 9000, mod = 100007;
const LL INF = 1LL << 61;

pll dp[N][M];
LL a[N];
pii pre[N][M];

vector <LL> g;
LL p[M], pp[100][100];
// ppn;
int b[M], bn, pn, gb[M][100];

struct hashmap {
    LL key[M];
    int val[M], tot, head[mod], nx[M];
    inline void init () {
        tot = 0;
        memset (head, -1, sizeof head);
    }
    inline void ins (LL x, int y) {
        int h = x % mod;
        key[tot] = x;
        val[tot] = y;
        nx[tot] = head[h];
        head[h] = tot++;
    }
    inline int query (LL x) {
        int h = x % mod;
        for (int i = head[h]; ~i; i = nx[i]) {
            if (key[i] == x) return val[i];
        }
        assert (1);
        return 0;
    }
} mp;

inline int getid (int x, int y) {
    LL r = 1;
    for (int i = 0; i < pn; i++) {
        r *= pp[i][min (b[i], gb[x][i] + gb[y][i])];
//        int c = 0;
//        while (x % p[i] == 0 && c < b[i]) c++, x /= p[i], r *= p[i];
//        while (y % p[i] == 0 && c < b[i]) c++, y /= p[i], r *= p[i];
    }
    return mp.query (r);
}

inline int getid2 (LL x, LL y) {
    LL r = 1;
    for (int i = 0; i < pn; i++) {
        int c = 0;
        while (x % p[i] == 0 && c < b[i]) c++, x /= p[i], r *= p[i];
        while (y % p[i] == 0 && c < b[i]) c++, y /= p[i], r *= p[i];
    }
    return lower_bound (g.begin(), g.end (), r) - g.begin();
}

int ppp[10] = {2, 3, 5, 7, 11, 13, 17, 19};

int main () {
//    cout << (sizeof (dp) + sizeof (pre)) / 1024 / 1024 << endl;
//    freopen ("in.txt", "r", stdin);
//    int mx = 0;
//    for (LL i = 9e11; i <= 1e12; i++) {
//        int c = 1;
//        LL t = i;
//        for (int j = 0; j < 8; j++) {
//            int cnt = 1;
//            while (t % ppp[j] == 0) t /= ppp[j], cnt++;
//            c *= cnt;
//        }
//        if (c > mx) {
//            mx = c;
//            cout << i << ' ' << c << endl;
//        }
//    }
    mp.init ();
    int n;
    LL k;
    cin >> n >> k;
    LL mn = 1e18, pos;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (mn > a[i]) mn = a[i], pos = i;
//        scanf ("%I64d\n", a[i]);
    }
    if (k == 1) { cout << 1 << endl << pos; return 0; }
    for (LL i = 1; i * i <= k; i++) {
        if (k % i == 0) g.push_back (i), g.push_back (k / i);
    }
    LL tmp = k;
    for (LL i = 2; i * i <= k; i++) if (k % i == 0) {
        p[pn++] = i;
        b[bn++] = 0;
        while (k % i == 0) {
            b[bn - 1]++;
            k /= i;
        }
    }
    if (k != 1) {
        p[pn++] = k;
        b[bn++] = 1;
    }
//    cout << g.size() << endl;
    k = tmp;
    sort (g.begin(), g.end());
    g.resize (unique (g.begin (), g.end ()) - g.begin ());
    assert (g.size() < M);
    for (int i = 0; i < g.size(); i++) {
        mp.ins (g[i], i);
        LL tmp = g[i];
        for (int j = 0; j < pn; j++) {
            int c = 0;
            while (tmp % p[j] == 0) tmp /= p[j], c++;
            gb[i][j] = c;
        }
    }
    for (int i = 0; i < pn; i++) {
//        pp[i].push_back (1);
        LL now = 1;
        for (int j = 0; j <= b[i]; j++) {
            pp[i][j] = now;
            now *= p[i];
        }
     }
//    for (int i = 0; i < p.size(); i++) cout << p[i] << ' ' << b[i] << endl;
//    for (int i = 0; i < g.size(); i++) {
////        cout << i << ' ' << g[i] << endl;
//        assert (mp.query(g[i]) == i);
//    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j < g.size(); j++) dp[i][j] = pll (INF, INF);
    dp[0][0] = pll (0, 0);
    for (int i = 1; i <= n; i++) {
//        for (int j = 0; j < g.size(); j++) if (dp[i - 1][j].xx != INF) {
//        }
        int id = lower_bound (g.begin(), g.end (), __gcd (k, a[i])) - g.begin();
//        assert (g[id] == __gcd (k, a[i]));
        for (int j = 0; j < g.size(); j++) if (dp[i - 1][j].xx != INF) {
            dp[i][j] = dp[i - 1][j];
            pre[i][j] = pre[i - 1][j];
        }
        for (int j = 0; j < g.size(); j++) if (dp[i - 1][j].xx != INF) {
//            dp[i][j] = dp[i - 1][j];
//            pre[i][j] = pre[i - 1][j];
//            cout << i << ' ' << id << ' ' << j << endl;
            int nx = getid (id, j);
//            assert (getid (id, j) == getid2 (g[id], g[j]));
            if (dp[i][nx].xx > dp[i - 1][j].xx + 1 || dp[i][nx].xx == dp[i - 1][j].xx + 1 && dp[i][nx].yy > dp[i - 1][j].yy + a[i]) {
                dp[i][nx] = pll (dp[i - 1][j].xx + 1, dp[i - 1][j].yy + a[i]);
                pre[i][nx] = pii (i, j);
//                cout << i << ' '<< nx << endl;
            }
        }
    }
//    cout << dp[n][g.size() - 1].yy << endl;
    if (dp[n][g.size() - 1].xx == INF) cout << -1;
    else {
        cout << dp[n][g.size() - 1].xx << endl;
        int nowx = n, nowy = g.size() - 1;
        while (nowx) {
//            cout << nowx << ' ' << nowy << endl;
            int p = pre[nowx][nowy].xx;
            if (!p) break;
            printf ("%d ", p);
            nowy = pre[nowx][nowy].yy;
            nowx = p - 1;
        }
    }
}