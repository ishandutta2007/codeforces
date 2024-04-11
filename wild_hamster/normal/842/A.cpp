#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,Q, mx,a[200500];
int main() {
    //freopen("input.txt", "r", stdin);
    ll l,r,x,y,k;
    cin >> l >> r >> x >> y >> k;
    for (i = x; i <= y; i++)
    {
        if (i*k >= l && i*k <= r)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}