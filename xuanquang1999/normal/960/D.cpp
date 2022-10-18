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

int loga2(ll x) {
    fdto(i, 59, 0)
        if ((x>>i) > 0) return i;
}

int Q;
ll delta[60], MOD[60];

ll add(ll &a, ll b, ll MOD) {
    a = ((a+b)%MOD + MOD)%MOD;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(i, 0, 59) MOD[i] = 1LL<<i;

    scanf("%d", &Q);
    fto(iq, 1, Q) {
        int t;
        ll u, k;
        scanf("%d%lld", &t, &u);
        if (t == 1) {
            scanf("%lld", &k);
            int h = loga2(u);
            add(delta[h], k, MOD[h]);
        } else if (t == 2) {
            scanf("%lld", &k);
            int H = loga2(u);
            fto(h, H, 59) {
                add(delta[h], k, MOD[h]);
                add(k, k, MOD[59]);
            }
        } else if (t == 3) {
//            fto(h, 0, 3) printf("%lld ", delta[h]);
//            puts("");
            int H = loga2(u);
            ll v = u-MOD[H];
            add(v, delta[H], MOD[H]);
            v += MOD[H];
            fdto(h, H, 0) {
                ll ans = v-MOD[h];
                add(ans, -delta[h], MOD[h]);
                ans += MOD[h];
                printf("%lld ", ans);
//                debug(v);
                v /= 2;
            }
            printf("\n");
        }
    }

    return 0;
}