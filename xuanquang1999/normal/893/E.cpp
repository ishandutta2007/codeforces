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
#define maxX 1000105
#define MOD 1000000007
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

int q, p[maxX];
ll fact[maxX], invFact[maxX], e2[maxX];

ll C(int n, int k) {
    return ((invFact[k]*invFact[n-k])%MOD * fact[n])%MOD;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(i, 2, maxX-1) {
        for(int j = i; j < maxX; j += i)
            if (p[j] == 0) p[j] = i;
    }

    fact[0] = invFact[0] = e2[0] = 1;
    fto(i, 1, maxX-1) {
        fact[i] = (fact[i-1]*i)%MOD;
        invFact[i] = power(fact[i], MOD-2);
        e2[i] = (e2[i-1]*2)%MOD;
    }

//    fto(i, 1, 10) printf("%d ", p[i]);
//    puts("");

    scanf("%d", &q);
    fto(i, 1, q) {
        int x, y; scanf("%d%d", &x, &y);

        ll ans = 1;
        while (x > 1) {
            int cnt = 1;
            while (p[x/p[x]] == p[x]) {
                ++cnt;
                x /= p[x];
            }
            x /= p[x];

            ans = (ans*C(y+cnt-1, y-1))%MOD;
        }

        ans = (ans*e2[y-1])%MOD;

        printf("%lld\n", ans);
    }


    return 0;
}