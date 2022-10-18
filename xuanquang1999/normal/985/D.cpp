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
#define oo 2000000000000000007LL
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
    if (b == 0) return 0;
    return (a <= oo/b) ? a*b : oo;
}

ll n, H;

ll Calc(ll x) {
    if (x <= H) return mul(x, x+1)/2;

    ll res = mul(H, H+1)/2 + mul(x-H, H);
    ll p = x-H-1;
    ll k = (p+1)/2;
    if (p%2 == 1) res += mul(k, k);
    else res += mul(k+1, k);

    return res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> H;

    ll lo = 1, hi = n, res = 0;
    while (lo <= hi) {
        ll mid = (lo+hi)/2;
        if (Calc(mid) >= n) {
            res = mid;
            hi = mid-1;
        } else lo = mid+1;
    }

    cout << res;

    return 0;
}