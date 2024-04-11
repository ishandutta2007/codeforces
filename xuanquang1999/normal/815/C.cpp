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
#define maxN 5005
#define oo 1000000000000000007LL
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

void minimize(ll &a, const ll &b) {a = min(a, b);}

int n, b, c[maxN], d[maxN], subSz[maxN], p[maxN];
ll dp[maxN][maxN][2];
vector<int> g[maxN];

int DFS(int u) {
    dp[u][1][1] = d[u];
    dp[u][0][0] = 0;
    dp[u][1][0] = c[u];
    subSz[u] = 1;
    forit(it, g[u]) {
        int v = *it;
        if (v != p[u]) {
            DFS(v);
            fdto(a, subSz[u], 0) {
                fdto(b, subSz[v], 0) {
                    minimize(dp[u][a+b][1], dp[u][a][1]+min(dp[v][b][0], dp[v][b][1]));
                    minimize(dp[u][a+b][0], dp[u][a][0]+dp[v][b][0]);
                }
            }
            subSz[u] += subSz[v];
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &b);
    fto(i, 1, n) {
        scanf("%d%d", &c[i], &d[i]);
        d[i] = c[i]-d[i];
        if (i > 1) {
            scanf("%d", &p[i]);
            g[p[i]].pb(i);
        }
    }

    fto(u, 1, n) fto(k, 0, n) fto(get, 0, 1) dp[u][k][get] = oo;
    DFS(1);

    int ans = 0;
    fto(k, 0, n) {
        if (min(dp[1][k][0], dp[1][k][1]) <= b) ans = k;
    }
    printf("%d", ans);

    return 0;
}