#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
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

const int MAXN = 200005;

int n, siz[MAXN], cntOdd;
vector<int> g[MAXN];
ll ans;

void DFS(int u, int p, int par) {
    siz[u] = 1;
    if (par == 1) ++cntOdd;

    for(int v: g[u]) {
        if (v == p) continue;
        DFS(v, u, par^1);

        ans += 1LL*(n-siz[v])*siz[v];
        siz[u] += siz[v];
    }
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

    DFS(1, -1, 0);
//    debug(ans);
    ans /= 2;

    ll cntPair = 1LL*cntOdd*(n-cntOdd);
//    debug(cntPair);
    ans += (cntPair+1)/2;

    printf("%lld", ans);

    return 0;
}