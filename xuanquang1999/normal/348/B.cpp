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
#define maxN 100005
#define oo 10000000000007LL
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

int n, a[maxN];
vector<int> g[maxN];
ll ans, f[maxN], k[maxN];

ll GCD(ll a, ll b) {return (b == 0) ? a : GCD(b, a%b);}
ll overflow(ll a, ll b) {return ((a*b)/a != b);}

ll LCM(ll a, ll b) {
    //if (a == -1) return b;
    ll d = GCD(a, b);
    if (overflow(a/d, b)) return oo;
    return a/GCD(a, b)*b;
}

void DFS(int u, int p) {
    //debug(u);
    ll m = 1;
    ll minF = -1;
    int cntChild = 0;
    forit(it, g[u]) {
        int v = *it;
        if (v != p) {
            ++cntChild;
            DFS(v, u);
            m = LCM(m, k[v]);
            if (minF == -1 || f[v] < minF) minF = f[v];
        }
    }
    if (minF == -1) {
        f[u] = a[u];
        k[u] = 1;
    } else {
        minF = (minF/m)*m;
        k[u] = min(oo, m*cntChild);
        f[u] = min(oo, minF*cntChild);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    //debug(overflow(1000000000, 1000000000));
    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 1, n-1) {
        int u, v; scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    DFS(1, -1);

    ll ans = accumulate(a+1, a+n+1, (ll)0)-f[1];
//    fto(u, 1, n) printf("%lld ", f[u]);
//    puts("");
    printf("%lld", ans);

    return 0;
}