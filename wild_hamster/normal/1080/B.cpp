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
ll n,m,k,x, rt[35], y, z, l, i, j, p;
ll a[100500];
ll used[100500], last_move;
ll f(ll x) {
    if (x % 2)
        return -x + x/2;
    else
        return x/2;
}
int main() {
     //freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    while(t--) {
        cin >> x >> y;
        cout << f(y) - f(x-1) << endl;
    }
    return 0;
}