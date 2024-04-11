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
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, cnt,v,tot,x,y,xx, yy,INF, sz, sum;
ll a[105], dp[505], fac[100500], invfac[100500];
int main() {
    //freopen("input.txt","r",stdin);
    string s, t;
    cin >> n >> m;
    cin >> s >> t;
    v = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*')
            v = i;
    }
    if (v == -1) {
        if (s == t)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return 0;
    }
    //cout << v << endl;
    for (int i = 0; i < v; i++)
    if (i >= m || s[i] != t[i]) {
        cout << "NO" << endl;
        return 0;
    }
    ll pnt = m-1;
    for (int i = n-1; i >= v+1; i--) {
        if (pnt < 0 || s[i] != t[pnt]) {
            cout << "NO" << endl;
            return 0;
        }
        pnt--;
    }
    if (n > m+1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}