#include <bits/stdc++.h>
using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define ftoa(i, l, r, a) for(int i = l; i <= r; i += a)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ii pair<int, int>
#define maxN 105

int a[3];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(i, 0, 2) cin >> a[i];

    sort(a, a+3);

    int ans = 0;
    fto(y, 0, min(a[0], 2)) {
        ans = max(ans, y+(a[0]-y)/3+(a[1]-y)/3+(a[2]-y)/3);
    }

    printf("%d\n", ans);

    return 0;
}