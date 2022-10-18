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
#define X real()
#define Y imag()
#define maxN 200005
#define oo 1000000007
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

int n, dp[2][maxN], d[maxN], cnt[maxN];
vector<int> g[maxN];

void DFS(int u, int p) {
    if (n == 1 || (p != -1 && sz(g[u]) == 1)) {
        dp[0][u] = dp[1][u] = 1;
        cnt[u] = 1;
    } else {
        if (d[u]%2 == 1) dp[0][u] = 0, dp[1][u] = oo;
        else dp[0][u] = -oo, dp[1][u] = 0;
        for(int v: g[u]) {
            if (v == p) continue;
            d[v] = d[u]+1;
            DFS(v, u);
            cnt[u] += cnt[v];

            if (d[u]%2 == 1) {
                dp[0][u] += dp[0][v]-1;
                dp[1][u] = min(dp[1][u], dp[1][v]);
            } else {
                dp[0][u] = max(dp[0][u], dp[0][v]-cnt[v]);
                dp[1][u] += dp[1][v];
            }
        }
//        printf("%d %d\n", u, dp[0][u]);
        if (d[u]%2 == 0) dp[0][u] += cnt[u];
        else dp[0][u] += 1;
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    DFS(1, -1);

//    fto(u, 1, n) printf("%d %d %d\n", dp[0][u], dp[1][u], cnt[u]);

    printf("%d %d", dp[0][1], dp[1][1]);

    return 0;
}