//84104971101048411497
#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define maxN 5005
#define oo 1000000000000000007LL
#define EPS 10e-9

struct present {
    int x, y, id;
    bool inline operator < (const present &b) const {
        return (x > b.x || (x == b.x && y > b.y));
    }
};

int n, f[maxN], trace[maxN], pos;
present a[maxN];

void printAns(int u) {
    if (u == -1) return;
    printf("%d ", a[u].id);
    printAns(trace[u]);
}

int main() {
    scanf("%d%d%d", &n, &a[0].x, &a[0].y), a[0].id = 0;
    fto(i, 1, n) scanf("%d%d", &a[i].x, &a[i].y), a[i].id = i;
    sort(a, a+n+1);
    fto(i, 0, n) trace[i] = -1;
    fto(i, 0, n) {
        f[i] = 1;
        fto(j, 0, i-1) {
            if (a[j].x > a[i].x && a[j].y > a[i].y && f[i] < f[j]+1) {
                f[i] = f[j]+1;
                trace[i] = j;
            }
        }
        if (a[i].id == 0) pos = i;
    }
//    fto(i, 0, n) printf("%d %d %d %d %d\n", a[i].x, a[i].y, a[i].id, f[i], trace[i]);

    printf("%d\n", f[pos]-1);
    printAns(trace[pos]);

    return 0;
}