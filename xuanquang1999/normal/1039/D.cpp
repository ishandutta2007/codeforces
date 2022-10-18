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

const int MAXN = 100005;

int n, dp[MAXN], par[MAXN], ans[MAXN];
vector<int> g[MAXN], ord;


void DFS(int u) {
    for(int v: g[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        DFS(v);
    }
    ord.pb(u);
}

int Solve(int k) {
    if (ans[k] != -1) return ans[k];

    ans[k] = 0;
    for(int u: ord) {
        int max1 = 0, max2 = 0;
        for(int v: g[u]) {
            if (v == par[u]) continue;
            if (dp[v] > max1) {
                max2 = max1;
                max1 = dp[v];
            } else if (dp[v] > max2)
                max2 = dp[v];
        }

        if (max1 + max2 + 1 >= k) {
            ++ans[k];
            dp[u] = 0;
        } else
            dp[u] = max1 + 1;
    }

    return ans[k];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    DFS(1);
    fto(x, 1, n) ans[x] = -1;

    int C = sqrt(n * log2(n));
    fto(x, 1, C)
        ans[x] = Solve(x);

    int x = C+1;
    while (x <= n) {
        int lo = x, hi = n, res = 0;
        while (lo <= hi) {
            int mid = (lo + hi)/2;
            if (Solve(mid) == Solve(x)) {
                res = mid;
                lo = mid+1;
            } else hi = mid-1;
        }

        fto(i, x, res) ans[i] = Solve(x);
        x = res + 1;
    }

    fto(i, 1, n) printf("%d\n", ans[i]);

    return 0;
}