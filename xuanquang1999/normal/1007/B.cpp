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
#define MOD 1000
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

int n, nTest;
ll cntD[maxN];

int GCD(int a, int b) {return (b == 0) ? a : GCD(b, a%b);}

int p[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
int a[3], _gcd[8];

pair<ll, ll> cnt(int a[3]) {
    ll ans3 = 0, ans2 = 0;
    fto(mask, 1, (1<<6)-1) {
        int sign = (__builtin_popcount(mask)%2 == 1) ? 1 : -1;
        int d[3] = {0, 0, 0};
        fto(i, 0, 5) {
            if ((mask>>i)&1) {
                fto(j, 0, 2) d[j] |= 1<<p[i][j];
            }
        }

        ans3 += cntD[_gcd[d[0]]]*cntD[_gcd[d[1]]]*cntD[_gcd[d[2]]]*sign;
        ans2 += cntD[_gcd[d[0]|d[1]]]*cntD[_gcd[d[2]]]*sign;
    }

    return mp(ans3, ans2);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    for(int d = 1; d < maxN; ++d)
        for(int i = d; i < maxN; i += d) ++cntD[i];

//    fto(i, 1, 10) printf("%d ", cntD[i]);
//    puts("");

    scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        fto(i, 0, 2) scanf("%d", &a[i]);

        fto(mask, 0, 7) {
            _gcd[mask] = 0;
            fto(i, 0, 2)
                if ((mask>>i)&1) _gcd[mask] = GCD(_gcd[mask], a[i]);
        }

//        fto(mask, 0, 7) printf("%d ", _gcd[mask]);
//        puts("");

        pair<ll, ll> p = cnt(a);

        ll ans = p.ff;
        ans += 3*p.ss;
        ans += 2*cntD[_gcd[7]];

        printf("%lld\n", ans/6);
    }

    return 0;
}