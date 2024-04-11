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
#define N 1000005
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, cnt,v,tot,x,y,INF, sz;
ll b[200500], a[200500];
vector<ll> f;
ll gcd(ll a, ll b) {
    return (b==0?a:gcd(b,a%b));
}
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output3.txt", "w", stdout);
    //cin >> n >> m;
    //n = 1000, m = 1000;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= k;
    }
    ll x = k;
    for (int i = 0; i < n; i++)
        x = gcd(x, a[i]);
    if (x == k) {
        cout << 1 << endl;
        cout << 0 << endl;
    } else {
        cout << k/x << endl;
        for (int i = 0; i < k; i += x)
            cout << i << " ";
    }
    return 0;
}