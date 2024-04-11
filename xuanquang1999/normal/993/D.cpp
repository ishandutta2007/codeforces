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
#define maxN 55
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

struct task {
    int a, b;
    bool inline operator < (const task &rhs) const {
        return a < rhs.a;
    }
};

int n;
task t[maxN];
ll a[maxN], dp[maxN][maxN][maxN];

void minimize(ll &a, ll b) {
    a = min(a, b);
}

bool Check(ll x) {
    fto(i, 0, n-1) a[i] = 1000LL*t[i].a - x*t[i].b;
//    fto(i, 0, n-1) printf("%lld ", a[i]);
//    puts("");
    fto(i, 0, n) fto(j, 0, n) fto(k, 0, n) dp[i][j][k] = oo;
    dp[0][0][0] = 0;
    fto(i, 0, n-1) {
        if (i > 0 && t[i-1].a < t[i].a) {
            fdto(j, i, 0) {
                fdto(k, i-j, 1) {
                    minimize(dp[i][j+k][0], dp[i][j][k]);
                    dp[i][j][k] = oo;
                }
            }
        }
        fto(j, 0, i) {
            fto(k, 0, i-j) {
                minimize(dp[i+1][j][k], dp[i][j][k]+a[i]);
                if (j > 0) minimize(dp[i+1][j-1][k], dp[i][j][k]+a[i]);
                minimize(dp[i+1][j][k+1], dp[i][j][k]);
            }
        }
    }

    return (dp[n][0][0] <= 0);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &t[i].a);
    fto(i, 0, n-1) scanf("%d", &t[i].b);
    sort(t, t+n);

//    Check(1160);
    ll lo = 0, hi = 1e11, res = 0;
    while (lo <= hi) {
        ll mid = (lo+hi)/2;
        if (Check(mid)) {
            res = mid;
            hi = mid-1;
        } else lo = mid+1;
    }

    printf("%lld", res);

    return 0;
}