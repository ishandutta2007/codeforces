#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[300500];
vector<ll> f;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m >> k;
    if (k <= n-1) {
        cout << k+1 << " " << 1 << endl;
        return 0;
    }
    k -= n;
    ll ost = k%(m-1);
    ll di = k/(m-1);
    if (di % 2 == 0) {
        cout << n-di << " " << ost+2 << endl;
    } else {
        cout << n-di << " " << m-ost << endl;
    }
    return 0;
}