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
#define maxN 500005
#define maxX 1000005
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

int n, x, y, a[maxN], cnt[maxX];
ll sum[maxX];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &x, &y);
    fto(i, 1, n) scanf("%d", &a[i]);

    fto(i, 1, n) {
        ++cnt[a[i]];
        sum[a[i]] += a[i];
    }

    fto(i, 1, maxX-1) {
        cnt[i] += cnt[i-1];
        sum[i] += sum[i-1];
    }

//    fto(i, 1, maxX-1) printf("%d %lld\n", cnt[i], sum[i]);

    ll ans = oo;
    fto(d, 2, maxX-1) {
        ll cur = 0;
        for(int i = 1; i < maxX; i += d) {
            int l = i, r = min(maxX-1, i+d-1);
            int k = max(l-1, min(r, i+d-x/y-2));
//            printf("%d %d %d %d\n", d, l, k, r);
            ll cntX = cnt[k]-cnt[l-1], cntY = 1LL*(cnt[r]-cnt[k])*(d*(i/d+1))-(sum[r]-sum[k]);
            cur += 1LL*cntX*x + 1LL*cntY*y;
        }
//        printf("%d %lld\n", d, cur);
        ans = min(ans, cur);
    }

    cout << ans;

    return 0;
}