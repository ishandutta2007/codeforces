//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 100005
#define maxX 15
#define MOD 1000000007
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, k, x;
ll dp[2][maxN][3][maxX];
vector<int> g[maxN];

void add(ll &a, ll b) {a = (a+b)%MOD;}

void DFS(int u, int p) {
    dp[0][u][0][0] = k-1;
    dp[0][u][1][1] = 1;
    dp[0][u][2][0] = m-k;

    for(int v: g[u]) {
        if (v == p) continue;
        DFS(v, u);
        fdto(i, x, 0) {
            fdto(j, x-i, 0) {
                add(dp[1][u][0][j+i], dp[0][u][0][i]*(dp[0][v][0][j]+dp[0][v][1][j]+dp[0][v][2][j]));
                add(dp[1][u][1][j+i], dp[0][u][1][i]*dp[0][v][0][j]);
                add(dp[1][u][2][j+i], dp[0][u][2][i]*(dp[0][v][0][j]+dp[0][v][2][j]));
            }
        }
        fto(i, 0, 2) fto(j, 0, x) {
            dp[0][u][i][j] = dp[1][u][i][j];
            dp[1][u][i][j] = 0;
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }
    scanf("%d%d", &k, &x);

    DFS(1, -1);

//    fto(u, 1, n) {
//        fto(i, 0, 2) {
//            fto(j, 0, x) printf("%d %d %d %lld\n", u, i, j, dp[0][u][i][j]);
//        }
//    }

    ll ans = 0;
    fto(i, 0, 2) fto(j, 0, x) ans = (ans+dp[0][1][i][j])%MOD;
    cout << ans;

    return 0;
}