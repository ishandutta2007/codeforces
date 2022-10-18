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

int n, m, a[maxN], b[maxN], d[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) scanf("%d", &a[i]);
    a[n+1] = m;

    fto(i, 1, n+1)
        b[i] = a[i]-a[i-1];

    fdto(i, n+1, 1)
        d[i] = d[i+2]+b[i];

//    fto(i, 1, n+1) printf("%d %d\n", b[i], d[i]);

    int ans = d[1], cur = 0;
    fto(i, 1, n+1) {
        if (b[i] > 1) {
            int x;
            if (i%2 == 1)
                x = d[i+1]+b[i]-1+cur;
            else
                x = d[i+2]+b[i]-1+cur;
            ans = max(x, ans);
        }

        if (i%2 == 1)
            cur += b[i];
    }

    printf("%d", ans);

    return 0;
}