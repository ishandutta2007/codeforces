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
ll n,m,k,a[100500],x, rt[35], y, z, l, i, j, p;
set<pii> f;
ll gcd(ll a, ll b) {
    return b == 0? a : gcd(b, a%b);
}
int main() {
     //freopen("input.txt","r",stdin);
    cin >> n >> m;
    ll ans = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
        if ((i*i + j*j) % m == 0) {
            ans += ((n-i+m)/m)*((n-j+m)/m);
        }
    cout << ans << endl;
    return 0;
}