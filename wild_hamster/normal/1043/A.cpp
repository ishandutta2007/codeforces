#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<ll,ll>
#define X first
#define Y second
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define INF 998244353
#define MAXN 1000005
typedef long long ll;
using namespace std;
ll i,j,k,q,x,y,n,m,  x1,y1,x2,y2,z;
ll a[200500];
string s;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    for (int k = mx; k <= 15000; k++) {
        int ans1 = 0, ans2 = 0;
        for (int j = 0; j < n; j++) {
            ans1 += k-a[j];
            ans2 += a[j];
        }
        if (ans1 > ans2) {
            cout << k << endl;
            return 0;
        }
    }

    return 0;
}