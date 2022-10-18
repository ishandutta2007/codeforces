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
#define oo 1000000007
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

int n, v[maxN], t[maxN];
ll d[maxN], f[maxN], ans[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &v[i]);
    fto(i, 1, n) scanf("%d", &t[i]);

    fto(i, 1, n) d[i] = d[i-1]+t[i];

    fto(i, 1, n) {
        int lo = i, hi = n, res = n+1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (d[mid]-d[i-1] >= v[i]) {
                res = mid;
                hi = mid-1;
            } else lo = mid+1;
        }

        f[i] += 1;
        f[res] += -1;
        ans[res] += v[i]-(d[res-1]-d[i-1]);
    }
//    fto(i, 1, n) printf("%lld %lld\n", f[i], ans[i]);

    fto(i, 1, n) {
        f[i] += f[i-1];
        ans[i] += 1LL*f[i]*t[i];
    }

    fto(i, 1, n) printf("%lld ", ans[i]);

    return 0;
}