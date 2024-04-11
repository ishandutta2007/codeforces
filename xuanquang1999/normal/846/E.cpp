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
#define maxK 2005
#define maxN 100005
#define oo 1000000000000000007LL
#define MOD 1000003
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

bool overflow(ll a, ll b) {
    return (a > oo/b);
}

int n;
ll a[maxN], b[maxN], dp[maxN];
vector<ii> g[maxN];

void DFS(int u) {
    dp[u] = a[u]-b[u];
    for(ii p: g[u]) {
        int v = p.ff, k = p.ss;
        DFS(v);
        if (dp[v] > 0) dp[u] += dp[v];
        if (dp[v] < 0) {
            if (overflow(-dp[v], k) || dp[u]+dp[v]*k < -oo) {
                puts("NO");
                exit(0);
            }
            dp[u] += dp[v]*k;
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%lld", &a[i]);
    fto(i, 1, n) scanf("%lld", &b[i]);
    fto(i, 2, n) {
        int x, k;
        scanf("%d%d", &x, &k);
        g[x].pb(mp(i, k));
    }

    DFS(1);

    puts((dp[1] >= 0) ? "YES" : "NO");

    return 0;
}