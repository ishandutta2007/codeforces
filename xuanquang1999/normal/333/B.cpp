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

int n, m, ans;
bool availr[maxN], availc[maxN];

int main() {
    scanf("%d%d", &n, &m);
    memset(availr, true, sizeof availr);
    memset(availc, true, sizeof availc);
    fto(i, 1, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        availr[x] = availc[y] = false;
    }
    fto(i, 2, n-1) ans += availr[i], ans += availc[i];
    if (n&1 && availr[n/2+1] && availc[n/2+1]) --ans;
    cout << ans;

    return 0;
}