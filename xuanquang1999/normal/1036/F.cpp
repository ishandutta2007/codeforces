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

const ll MAXX = 1000000000000000000LL;
const ll oo = 1000000000000000007LL;

ll mul(ll a, ll b) {
    return (a <= oo/b) ? a*b : oo;
}

ll power(const ll &x, ll n) {
    if (n == 0) return 1;
    if (n&1) return mul(x, pow(x, n-1));
    ll p = power(x, n/2);
    return mul(p, p);
}

int nTest;
vector<ll> a;

bool isSqr(const ll &x) {
    ll p = sqrt(x);
    return (p*p == x);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

//    debug(oo);
//    debug(mul(oo, oo));

    fto(n, 3, 59) {
        ll p;
        for(int x = 2; (p = power(x, n)) <= MAXX; ++x) {
//            cout << p << " " << x << endl;
            if (!isSqr(p))
                a.push_back(p);
        }
    }

    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
//    fto(i, 0, 10) cout << a[i] << endl;

    ios::sync_with_stdio(false);
    cin >> nTest;
    fto(iTest, 1, nTest) {
        ll x; cin >> x;
        ll ans = sqrt(x) - 1;
        ans += upper_bound(a.begin(), a.end(), x) - a.begin();
        ans = x - ans - 1;
        cout << ans << endl;
    }


    return 0;
}