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
#define maxN 100005
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

struct Edge {int u, v, w;};

bool isPrime(int x) {
    if (x < 2) return false;
    fto(i, 2, sqrt(x))
        if (x%i == 0) return false;
    return true;
}

int n, m;
vector<Edge> e;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    int x;
    for(x = n-1; ; ++x) {
        if (isPrime(x)) break;
    }

    fto(i, 1, n-2) e.pb({i, i+1, 1});
    e.pb({n-1, n, x-(n-2)});

    fto(i, 1, n) {
        fto(j, i+2, n) {
            if (sz(e) == m) break;
            e.pb({i, j, 1000000000});
        }
    }

    printf("%d %d\n", x, x);
    for(Edge p: e) printf("%d %d %d\n", p.u, p.v, p.w);

    return 0;
}