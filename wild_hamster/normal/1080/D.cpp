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
typedef long long ll;
using namespace std;
ll n,m,k,a[100500],x, rt[35], dp[300500][3], y, z, l, i, j, p;
int main() {
     //freopen("input.txt","r",stdin);
    rt[1] = 1;
    for (int i = 2; i <= 31; i++)
        rt[i] = rt[i-1] * 4 + 1;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        ll sum = 0;
        ll p = 1;
        ll flag = 0;
        for (int i = 0; i < n; i++) {
            sum += p;
            p *= 4;
            if (sum >= k) {
                flag = 1;
                break;
            }
        }
        if (n == 2 && k == 3)
            flag = 0;
        if (!flag) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES ";
        ll r = 0, d = 0;
        ll x;
        for (int i = 0; i <= 62; i++) {
            r = r * 2 + 1;
            d += r;
            if (d > k) {
                x = i;
                break;
            }
        }
        cout << max(0LL, n-x) << endl;
    }
    return 0;
}