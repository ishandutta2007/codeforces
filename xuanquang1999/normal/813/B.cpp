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
#define maxN 100005
#define oo 2000000007
#define EPS 1e-9
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

ll x, y, l, r;
vector<ll> u;

bool overFlow(ll a, ll b) {
    return (((a*b)/a != b) || a*b > (ll)1e18+1);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> x >> y >> l >> r;

    ll prox = 1;
    fto(px, 0, 60) {
        ll proy = 1;
        fto(py, 0, 60) {
            if (prox+proy >= l && prox+proy <= r) u.pb(prox+proy);
            if (overFlow(proy, y)) break;
            proy *= y;
        }
        if (overFlow(prox, x)) break;
        prox *= x;
    }

    u.pb(l-1); u.pb(r+1);
    sort(u.begin(), u.end());

    ll ans = 0;
    fto(i, 0, sz(u)-2) ans = max(ans, u[i+1]-u[i]-1);
    cout << ans;


    return 0;
}