//84104971101048411497
#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ii pair<int, int>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define maxN 100005
#define oo 1000000007
#define EPS 10e-9

int n, l, x, y, a[maxN];
ii fmx, fmy;

ii FirstMark(int x) {
//    debug(x);
    fto(i, 1, n) {
        int p = lower_bound(a+1, a+n+1, a[i]+x)-a;
//        printf("%d %d %d\n", a[i]+x, i, p);
        if (a[p] == a[i]+x) return mp(i, p);
    }
    return mp(-1, -1);
}

ii LastMark(int x) {
//    debug(x);
    fdto(p, n, 1) {
        int i = lower_bound(a+1, a+n+1, a[p]-x)-a;
//        printf("%d %d %d\n", a[i]+x, i, p);
        if (a[i] == a[p]-x) return mp(i, p);
    }
    return mp(-1, -1);
}

int main() {
    scanf("%d%d%d%d", &n, &l, &x, &y);
    fto(i, 1, n) scanf("%d", &a[i]);

    fmx = FirstMark(x), fmy = FirstMark(y);
    if (fmx.ff != -1 && fmy.ff != -1) puts("0");
    else if (fmx.ff != -1) printf("1\n%d", y);
    else if (fmy.ff != -1) printf("1\n%d", x);
    else {
        fmx = FirstMark(y-x), fmy = LastMark(y-x);
        if (fmx.ss != -1 && l-a[fmx.ss] >= x) printf("1\n%d", a[fmx.ss]+x);
        else if (fmy.ss != -1 && a[fmy.ff] >= x) printf("1\n%d", a[fmy.ff]-x);
        else {
            fmx = FirstMark(x+y);
            if (fmx.ss != -1) printf("1\n%d", a[fmx.ff]+x);
            else printf("2\n%d %d", x, y);
        }
    }


    return 0;
}