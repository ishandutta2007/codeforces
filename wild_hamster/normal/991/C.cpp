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
#define ROW 5
#define COL 30000
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot,x,y,INF, ans;
ll a[1200005], b[1205000], w[1205000];
ll gcd(ll a, ll b) {
    return (b==0?a:gcd(b,a%b));
}
int main() {

    //freopen("input.txt","r",stdin);
    cin >> n;
    ll l = 1, r = n;
    while (l < r) {
        ll mid = (l+r)/2;
        ll k = 0, m = 0;
        ll n1 = n;
        while (n1 > 0) {
            k += min(n1, mid);
            n1 -= min(n1, mid);
            m += n1 / 10;
            n1 -= n1/10;
        }
        if (k*2 >= n) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    cout << l << endl;
    return 0;
}