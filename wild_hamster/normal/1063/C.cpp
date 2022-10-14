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
#define MOD 1000000007
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom;
int a[500500], b[500500], fac[500500], invfac[500500];
int query(int x, int y) {
    cout << x << " " << y << endl;
    fflush(stdout);
    string ans;
    cin >> ans;
    if (ans == "black")
        return 1;
    return 0;
}
int main() {
    //freopen("input.txt", "r", stdin);
    //inp();
    cin >> n;
    int l = 1, r = 1e+9;
    int bit;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            bit = query(1, 0);
            continue;
        }
        int mid = (l+r)/2;
        int ans = (bit^query(mid, 0));
        if (ans == 0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l-1 << " " << 100 << " " << l << " " << 1 << endl;
    return 0;
}