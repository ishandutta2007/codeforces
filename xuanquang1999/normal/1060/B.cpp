#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
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

int S(ll x) {
    int res = 0;
    while (x > 0) {
        res += x%10;
        x /= 10;
    }
    return res;
}

ll n;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n;

    int ans = 0;
    fto(d, 1, 9)
        if (d <= n) ans = max(ans, S(d) + S(n-d));

    ll e10 = 10;
    while (true) {
        bool stop = false;
        fto(d, 1, 9) {
            ll a = d*e10 + e10-1;
            if (a > n) {
                stop = true;
                break;
            }
            ll b = n-a;
            ans = max(ans, S(a) + S(b));
        }
        if (stop) break;
        e10 *= 10;
    }

    cout << ans;

    return 0;
}