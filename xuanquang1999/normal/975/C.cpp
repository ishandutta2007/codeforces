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
#define maxN 300005
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

int n, q, a[maxN];
ll d[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    fto(i, 1, n) {
        scanf("%d", &a[i]);
        d[i] = d[i-1]+a[i];
    }

    int i = 1, curA = a[1];
    fto(iq, 1, q) {
//        printf("%d %d\n", i, curA);
        ll k; scanf("%lld", &k);
        int lo = i, hi = n, res = i-1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;

            ll sum = d[mid]-d[i]+curA;
            if (sum <= k) {
                res = mid;
                lo = mid+1;
            } else hi = mid-1;
        }

        int ans;
        if (res == n) {
            ans = n;
            i = 1;
            curA = a[1];
        } else {
            ans = n-res;
            curA = a[res+1] - (k-(d[res]-d[i]+curA));
            i = res+1;
        }

        printf("%d\n", ans);
    }

    return 0;
}