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

ll power(ll x, ll n, ll M) {
    if (n == 0) return 1;
    if (n&1) return (x*power(x, n-1, M))%M;
    ll p = power(x, n/2, M);
    return (p*p)%M;
}

ll n, k;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> k;
    if (n < 60 && k > (1LL<<n)) {
        puts("1 1");
        return 0;
    }

    ll p = (1LL * (n%(MOD-1)) * ((k-1)%(MOD-1)))%(MOD-1);
//    debug(p);
    fto(i, 1, 59) {
        ll x = (k-1)/(1LL<<i);
        p = (p - x%(MOD-1) + MOD-1)%(MOD-1);
    }
//    debug(p);

    ll prod = 1;
    if (k >= MOD) {
        prod = 0;
    } else {
        fto(i, 1, k-1) {
            int t = i&(-i);
            int x = log2(t);
//            printf("%d %d %d\n", i, t, x);
            prod = (prod*(power(2, n-x, MOD)-i/t+MOD))%MOD;
        }
    }

    ll B = power(2, p, MOD);
    ll A = (B - prod + MOD)%MOD;

    cout << A << " " << B;

    return 0;
}