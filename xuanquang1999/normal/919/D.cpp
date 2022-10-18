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
#define maxN 300005
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

ll mul(ll a, ll b) {
    if (a*b/a != b) return oo;
    return min(oo, a*b);
}

int n, m, a[maxN], dp[maxN];
char s[maxN];
vector<int> g[maxN];
bool marked[maxN];

int Solve(int u) {
    if (dp[u] != -1) return dp[u];
    marked[u] = true;

    int res = a[u];
    for(int v: g[u]) {
        if (marked[v] && dp[v] == -1) {
            puts("-1");
            exit(0);
        }
        res = max(res, Solve(v)+a[u]);
    }

    return dp[u] = res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    scanf("%s", s);
    fto(i, 1, m) {
        int u, v; scanf("%d%d", &u, &v);
        g[u].pb(v);
    }

    int ans = 0;
    fto(c, 'a', 'z') {
        fto(u, 1, n) {
            a[u] = (s[u-1] == c);
            dp[u] = -1;
            marked[u] = false;
        }
        //debug(c);
//        fto(u, 1, n) printf("%d ", a[u]);
//        puts("");
        fto(u, 1, n)
            ans = max(ans, Solve(u));
//        fto(u, 1, n) printf("%d ", dp[u]);
//        puts("");
    }

    printf("%d", ans);

    return 0;
}