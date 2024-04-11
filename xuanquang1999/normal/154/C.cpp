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
#define maxN 1000005
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

const int MOD[2] = {1000002233, 1000002277};

int n, m, e[2][maxN];
ii h[maxN];
ll ans;

void addHash(int u, int v) {
    h[u].ff = (h[u].ff+e[0][v])%MOD[0];
    h[u].ss = (h[u].ss+e[1][v])%MOD[1];
}

void CountPair() {
    map<ii, int> hMap;
    fto(u, 1, n) {
        ans += hMap[h[u]];
        ++hMap[h[u]];
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 0, 1) {
        e[i][0] = 1;
        fto(j, 1, n) e[i][j] = (e[i][j-1]*2)%MOD[i];
    }
//    fto(i, 0, 1) {
//        fto(j, 0, n) printf("%d ", e[i][j]);
//        puts("");
//    }
    fto(i, 1, m) {
        int u, v; scanf("%d%d", &u, &v);
        addHash(u, v);
        addHash(v, u);
    }
    CountPair();
    //debug(ans);
    fto(u, 1, n) addHash(u, u);
    CountPair();
    //debug(ans);

    printf("%lld", ans);

    return 0;
}