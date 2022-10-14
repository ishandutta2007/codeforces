#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <time.h>
#include <fstream>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
typedef long long ll;
using namespace std;

ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[100500], leaf[100500];
vector<ll> g[100500];
ll f(ll k) {
    if (k == 0) {
        return 0;
    }
    if (k >= (1<<(n-1))) {
        ll val = a[0]*(1<<(n)), idx = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]*(1<<(n-i)) < val) {
                val = a[i]*(1<<(n-i));
                idx = i;
            }
        }
        ll to_buy = (k/(1<<idx));
        ll ans = to_buy * a[idx];
        return ans + f(k-to_buy*(1<<idx));
    } else {
        ll x = 1;
        ll y = 0;
        while (x <= k) {
            x *= 2;
            y++;
        }
        ll ans = a[y];
        for (int i = y; i < n; i++)
            ans = min(ans, a[i]);

        ll val = a[0]*(1<<(n)), idx = 0;
        for (int i = 0; i < y; i++) {
            if (a[i]*(1<<(n-i)) < val) {
                val = a[i]*(1<<(n-i));
                idx = i;
            }
        }
        ll to_buy = (k/(1<<idx));
        return min(ans, to_buy*a[idx] + f(k-to_buy*(1<<idx)));
    }
}
int main() {
    // cout << setprecision(20);
    // ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    for (i = 0; i < n; i++)
        cin >> a[i];
    cout << f(k);
    return 0;
}