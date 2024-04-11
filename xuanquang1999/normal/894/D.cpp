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
#define maxN 1000005
#define oo 2000000007
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

int n, q, w[maxN], par[maxN];
vector<ll> a[maxN], d[maxN];

vector<ll> DFS(int u) {
    int l = 2*u, r = 2*u+1;

    vector<ll> L, R;
    if (l <= n) {
        L = DFS(l);
        fto(i, 0, sz(L)-1) L[i] += w[l];
    }
    if (r <= n) {
        R = DFS(r);
        fto(i, 0, sz(R)-1) R[i] += w[r];
    }

    vector<ll> ans(sz(L)+sz(R));
    merge(L.begin(), L.end(), R.begin(), R.end(), ans.begin());
    ans.insert(ans.begin(), 0);

    return a[u] = ans;
}

ll Solve(int u, int H) {
//    printf("%d %d\n", u, C, H);
    int p = upper_bound(a[u].begin(), a[u].end(), H)-a[u].begin();
    if (p == 0) return 0;
    return 1LL*p*H - d[u][p-1];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    fto(i, 2, n) scanf("%d", &w[i]);

    DFS(1);

    fto(u, 1, n) {
        d[u].resize(sz(a[u]));
        d[u][0] = a[u][0];
        fto(i, 1, sz(a[u])-1) d[u][i] = d[u][i-1]+a[u][i];
    }

//    fto(u, 1, n) {
//        debug(u);
//        for(ll x: a[u]) printf("%lld ", x);
//        puts("");
//        for(ll x: d[u]) printf("%lld ", x);
//        puts("");
//    }

    fto(i, 1, q) {
        int u, H;
        scanf("%d%d", &u, &H);

//        printf("%d %d\n", u, H);
        ll ans = Solve(u, H), dist = 0;
//        debug(ans);
        while (u > 1) {
            dist += w[u];
            if (dist > H) break;
            ans += H-dist;
//            debug(ans);
            ans += Solve(u^1, H-dist-w[u^1]);
//            debug(ans);
            u >>= 1;
        }

        printf("%lld\n", ans);
    }

    return 0;
}