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

int power(int x, int n, int MOD) {
    if (n == 0) return 1%MOD;
    if (n&1) return (1LL*x*power(x, n-1, MOD))%MOD;
    int p = power(x, n/2, MOD);
    return (1LL*p*p)%MOD;
}

int a, b, p, apow[maxN], inv[maxN];
ll x;

ll Solve() {
//    puts("Ok");
    apow[0] = 1%p;
//    puts("Ok");
    fto(i, 1, p) {
        apow[i] = (1LL*apow[i-1]*a)%p;
        inv[i] = power(i, p-2, p);
    }
//    puts("Ok");

//    fto(i, 1, 10) printf("%d %d\n", apow[i], inv[i]);

    ll ans = 0;
    fto(r, 0, min(x, (ll)p-2)) {
        int q = ((1LL*b*inv[apow[r]]-r+p)*inv[p-1])%p;
        ll lim = (x-r)/(p-1);
//        printf("%d %d\n", r, q);
        if (lim >= q) ans += (lim-q)/p+1;
    }

    return ans;
}

ll BruteForce() {
    int ans = 0, cur = 1;
    fto(i, 1, x) {
        cur = (1LL*cur*a)%p;
        if ((1LL*i*cur)%p == b) ++ans;
    }
    //debug(ans);
    return ans;
}

bool isPrime(int p) {
    if (p < 2) return false;
    fto(i, 2, sqrt(p))
        if (p%i == 0) return false;
    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d%lld", &a, &b, &p, &x);

    cout << Solve();

//    while (true) {
////        puts("Test:");
//        p = rand()%300;
//        while (!isPrime(p)) ++p;
//
//        a = rand()%(p-1)+1;
//        b = rand()%(p-1)+1;
//        x = rand()%10000;
//
////        printf("%d %d %d %lld\n", a, b, p, x);
//        if (BruteForce() != Solve()) {
//            printf("%d %d %d %lld\n", a, b, p, x);
//        }
//    }

    return 0;
}