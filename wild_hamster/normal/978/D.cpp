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
#define PI 3.14159265359
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum, ans;
ll a[200500],  b[200500];
ll dp[100500];
ll used[100500];
vector<ll> f;
set<ll> g;
ll Abs(ll x) {
    return x>0?x:-x;
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n <= 2) {
        cout << 0 << endl;
        return 0;
    }
    ans = MOD;
    for (int j = a[0]-1; j <= a[0]+1; j++)
    for (int k = a[1]-1; k <= a[1]+1; k++) {
        ll d = k-j;
        ll cnt = (j != a[0]) + (k != a[1]);
        ll cur = k;
        ll flag = 1;
        for (int i = 2; i < n; i++) {
            cur += d;
            if (Abs(cur-a[i]) > 1) {
                flag = 0;
                break;
            } else
                cnt += (cur != a[i]);
        }
        if (flag)
            ans = min(ans, cnt);
    }
    if (ans != MOD)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}