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
#define maxN 2005
#define oo 2000000007
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

int n, k, p, a[maxN], b[maxN];

bool Check(int x) {
    int l[n+1], r[n+1];
    fto(i, 1, n) l[i] = oo, r[i] = 0;
    fto(i, 1, n) {
        fto(j, 1, k) {
            if (abs(a[i]-b[j])+abs(b[j]-p) <= x) {
                l[i] = min(l[i], j);
                r[i] = max(r[i], j);
            }
        }
    }

    bool ok[n+1];
    fto(i, 1, n) ok[i] = false;
    fto(j, 1, k) {
        int id = 0, minR = oo;
        fto(i, 1, n) {
            if (!ok[i] && l[i] <= j && j <= r[i] && r[i] < minR) {
                minR = r[i];
                id = i;
            }
        }
        if (id == 0) continue;
        ok[id] = true;
    }

    fto(i, 1, n) {
        if (!ok[i]) return false;
    }
    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &k, &p);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 1, k) scanf("%d", &b[i]);

    sort(a+1, a+n+1);
    sort(b+1, b+k+1);

    int lo = 0, hi = oo, res = hi+1;
    while (lo <= hi) {
        int mid = (1LL*lo+hi)/2;
        if (Check(mid)) {
            res = mid;
            hi = mid-1;
        } else lo = mid+1;
    }

    printf("%d", res);

    return 0;
}