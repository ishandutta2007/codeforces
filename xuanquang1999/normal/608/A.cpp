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
#define maxN 105
#define oo 1000000007
#define EPS 10e-9

int n, s, cur;
ii a[maxN];

int main() {
    scanf("%d%d", &n, &s);
    fto(i, 1, n) scanf("%d%d", &a[i].ff, &a[i].ss);
    sort(a+1, a+n+1);
    a[n+1].ff = s;

    fdto(i, n, 0) {
        cur = max(a[i].ss, cur+(a[i+1].ff-a[i].ff));
    }
    cout << cur;

    return 0;
}