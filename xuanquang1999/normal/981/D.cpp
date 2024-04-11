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

int n, k;
ll a[maxN], sum[maxN];

bool Check(ll x) {
    vector<vector<bool> > dp(n+1, vector<bool>(k+1, false));
    dp[0][0] = true;
    fto(r, 1, n) {
        fto(i, 1, k) {
            fto(l, 1, r) {
                if (((sum[r]-sum[l-1])&x) == x) dp[r][i] = dp[r][i] | dp[l-1][i-1];
            }
        }
    }
    return dp[n][k];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> k;
    fto(i, 1, n) {
        cin >> a[i];
        sum[i] = sum[i-1]+a[i];
    }

    ll ans = 0;
    fdto(i, 59, 0) {
        if (Check(ans+(1LL<<i))) {
            ans += 1LL<<i;
        }
    }

    cout << ans;

    return 0;
}