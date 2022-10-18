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
#define maxN 100005
#define oo 1000000007
#define EPS 1e-9
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

int n, a[maxN], d[maxN], S;
vector<int> c[2], g[maxN];

void DFS(int u) {
    if (sz(g[u]) == 0) d[u] = 1;
    else {
        forit(it, g[u]) {
            int v = *it;
            DFS(v);
            d[u] = (d[v]+1)%2;
        }
    }
    c[d[u]].pb(a[u]);
    if (d[u] == 1) S ^= a[u];
}

ll Tri(ll x) {return x*(x-1)/2;}

int Count(const vector<int> &v, const int &x) {
    return upper_bound(v.begin(), v.end(), x)-lower_bound(v.begin(), v.end(), x);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(u, 1, n) scanf("%d", &a[u]);
    fto(u, 2, n) {
        int p; scanf("%d", &p);
        g[p].pb(u);
    }

    DFS(1);

    fto(i, 0, sz(c[0])-1) c[0][i] ^= S;

    sort(c[0].begin(), c[0].end());
    ll ans = 0;
    forit(it, c[1]) ans += Count(c[0], *it);

    if (S == 0) ans += Tri(sz(c[0]))+Tri(sz(c[1]));

    printf("%lld", ans);

    return 0;
}