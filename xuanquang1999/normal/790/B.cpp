//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define X real()
#define Y imag()
#define maxN 200005
#define maxK 5
#define oo 2000000007
#define EPS 1e-9

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

int n, k;
ll sum[maxN], dp[2][maxN][maxK], extra[maxN], cnt[maxN][maxK], ans;
vector<int> g[maxN];

void DFS(int u, int p) {
    cnt[u][0] = 1;
    forit(it, g[u]) {
        int v = *it;
        if (v != p) {
            DFS(v, u);
            sum[u] += sum[v];
            fto(i, 0, k-1) {
                fto(j, 0, k-1) {
                    dp[1][u][(i+j+1)%k] += dp[0][u][i]*cnt[v][j]+dp[0][v][j]*cnt[u][i] + cnt[u][i]*cnt[v][j]*((i+j+1)/k);
                    if ((i+j+1)%k > 0) extra[u] += cnt[u][i]*cnt[v][j];
                }
            }
            //printf("u, v, extra[u]: %d %d %lld\n", u, v, extra[u]);
            fto(i, 0, k-1) {
                dp[0][u][(i+1)%k] += dp[0][v][i];
                cnt[u][(i+1)%k] += cnt[v][i];
                if (i == k-1) {
                    dp[0][u][(i+1)%k] += cnt[v][i];
                    //cnt[u][(i+1)%k] += cnt[v][i];
                }
            }
        }
    }

}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    DFS(1, -1);
//    debug(ans);
//    fto(u, 1, n) {
//        debug(u);
//        debug(extra[u]);
//        fto(i, 0, k-1) printf("%lld %lld %lld\n", cnt[u][i], dp[0][u][i], dp[1][u][i]);
//    }
    fto(u, 1, n) {
        ans += extra[u];
        fto(i, 0, k-1) ans += dp[1][u][i];
    }

    cout << ans;

    return 0;
}