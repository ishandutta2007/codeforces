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
#define MOD 1000000007
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

ll power(ll x, int n) {
    if (n == 0) return 1;
    if (n&1) return (x*power(x, n-1))%MOD;
    ll p = power(x, n/2);
    return (p*p)%MOD;
}

int n, a[maxN];
ll fact[maxN], invFact[maxN];

ll C(ll n, ll k) {
    return ((fact[n]*invFact[k]%MOD) * invFact[n-k])%MOD;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(u, 1, n) scanf("%d", &a[u]);

    fact[0] = invFact[0] = 1;
    fto(i, 1, maxN-1) fact[i] = (fact[i-1]*i)%MOD;
    invFact[maxN-1] = power(fact[maxN-1], MOD-2);
    fdto(i, maxN-2, 1) invFact[i] = (invFact[i+1]*(i+1))%MOD;

//    fto(i, 0, 10) printf("%d %lld %lld\n", i, fact[i], invFact[i]);

    sort(a+1, a+n+1);
    int j = n, ans = 0;
    fdto(i, n, 1) {
        while (j > 0 && a[j] >= a[i]) --j;
        if (a[i] != a[n]) {
            int k = n-j-1;
//            printf("%d\n", k);
            ll x = ((C(n, k+1)*fact[k])%MOD * fact[n-k-1])%MOD;
//            debug(x);
            ans = (ans + a[i]*x)%MOD;
        }
    }

    printf("%d", ans);

    return 0;
}