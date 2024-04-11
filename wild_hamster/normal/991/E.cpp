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
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,tot,x,y,INF, ans;
ll a[1200005], b[1205000], fac[1205000], dp[100500][4];
ll gcd(ll a, ll b) {
    return (b==0?a:gcd(b,a%b));
}
string s[2];
void go(ll n) {
    if (n == 10) {
        ll sum = 0;
        for (int i = 0; i < n; i++)
             sum += a[i];
        ll tmp = fac[sum];
        for (int i = 0; i < n; i++)
            tmp /= fac[a[i]];
        ans += tmp;
        if (a[0] > 0) {
            tmp = fac[sum-1];
            tmp /= fac[a[0]-1];
            for (int i = 1; i < n; i++)
                tmp /= fac[a[i]];
            ans -= tmp;
        }
        return;
    }
    if (a[n] == 0)
        go(n+1);
    ll m = a[n];
    for (int i = 1; i <= m; i++) {
        ll x = a[n];
        a[n] = i;
        go(n+1);
        a[n] = x;
    }
}
int main() {

    //freopen("input.txt","r",stdin);
    string s;
    fac[0] = 1;
    for (int i = 1; i <= 19; i++) {
        fac[i] = i * fac[i-1];
        //cout << i << " " << fac[i] << endl;
    }
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        a[s[i]-'0']++;
    go(0);
    cout << ans << endl;
    return 0;
}