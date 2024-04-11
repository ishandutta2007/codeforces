#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define ROW 5
#define N 1000005
typedef int ll;
using namespace std;
ll n,i,j,k,m,q,timer,mx, v,tot,x,y,INF, sz,ans;
int a[10050];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n/2; i++) {
        if (a[i] == 2 && a[n-i-1] == 2) {
            ans += 2*min(x,y);
        } else if (a[i] == 2 || a[n-i-1] == 2) {
            if (min(a[i], a[n-i-1]) == 1)
                ans += y;
            else
                ans += x;
        } else if (a[i] != a[n-i-1]) {
            cout << -1 << endl;
            return 0;
        }
    }
    if (n%2 && a[n/2] == 2)
        ans += min(x, y);
    cout << ans << endl;
    return 0;
}