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

int n, q, a[maxN];
ll d[maxN], ans[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n)
        scanf("%d", &a[i]);

    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);
    fto(i, 1, n)
        d[i] = d[i-1]+a[i];

    fto(k, 1, n-1) {
        int l = 1, dist = 0;
        ll prod = 1;
        while (l <= n) {
            int r = min((ll)n, l+prod-1);
            ans[k] += (d[r]-d[l-1])*dist;

            l = r+1;
            prod *= k;
            ++dist;
        }
    }

    scanf("%d", &q);
    fto(i, 1, q) {
        int k; scanf("%d", &k);
        k = min(k, n-1);
        printf("%lld\n", ans[k]);
    }

    return 0;
}