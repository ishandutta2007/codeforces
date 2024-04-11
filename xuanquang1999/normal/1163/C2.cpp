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

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a%b);
}

const int MAXN = 1005;

int n, x[MAXN], y[MAXN];

set<pair<pii, ll>> mline;
map<pii, int> mdir;

ll c2(int x) {
    return 1LL*x*(x-1)/2;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d%d", &x[i], &y[i]);

    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            int a = y[j] - y[i], b = x[i] - x[j];

            int d = gcd(abs(a), abs(b));
            a /= d; b /= d;

            if (a < 0) {
                a = -a;
                b = -b;
            }

            if (a == 0 && b < 0)
                b = -b;

            ll c = 1LL*a*x[i] + 1LL*b*y[i];

            mline.insert({{a, b}, c});
        }
    }

    for(pair<pii, ll> e: mline)
        ++mdir[e.first];

//    for(pair<pii, ll> e: mline)
//        printf("%d %d %lld\n", e.first.first, e.first.second, e.second);
//    for(pair<pii, int> e: mdir)
//        printf("%d %d %d\n", e.first.first, e.first.second, e.second);

    ll ans = c2(mline.size());

    for(pair<pii, int> e: mdir)
        ans -= c2(e.second);

    printf("%lld", ans);

    return 0;
}