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
ll n,m,k,y, x, t, z, tot;
string s;
ll a[1005000], b[1005000], sz;
int main()
{
    //freopen("input.txt", "r", stdin);
    ll sum1 = 0, sum2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        sum1 += a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%I64d", &b[i]);
        sum2 += b[i];
    }
    if (sum1 != sum2) {
        cout << -1 << endl;
        return 0;
    }
    ll pnt1 = 0, pnt2 = 0;
    while (pnt1 < n || pnt2 < m) {
        if (sum1 > sum2) {
            sum2 += b[pnt2++];
        } else if (sum1 < sum2) {
            sum1 += a[pnt1++];
        } else {
            k++;
            sum2 += b[pnt2++];
            sum1 += a[pnt1++];
        }
    }
    cout << k << endl;

	return 0;
}