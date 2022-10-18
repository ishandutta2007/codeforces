#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a << ": " << a << endl
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define maxN 105
#define oo 1000000007
int m, n, c[maxN][maxN], ans;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &m, &n);
    fto(i, 1, m)
        fto(j, 1, n) scanf("%d", &c[i][j]);
    fto(i, 1, m) {
        int cur = oo;
        fto(j, 1, n) cur = min(cur, c[i][j]);
        ans = max(ans, cur);
    }
    cout << ans;


    return 0;
}