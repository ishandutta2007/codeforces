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
#define COL 30000
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,tot,x,y,INF, ans;
ll a[300005], res[305000], b[300500], tin[305000], fup[300500], used[300500], col[300500], w[300500];

int main() {

    //freopen("input.txt","r",stdin);
    cin >> n >> x >> y;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && (i == n-1 || s[i+1] == '1'))
            k++;
    }
    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (y < x)
        cout << k*y << endl;
    else
        cout << y + (k-1)*x << endl;
    return 0;
}