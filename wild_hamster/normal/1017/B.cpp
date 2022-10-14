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
#define IN 5
#define OR 10
#define AND 15
#define XOR 20
#define NOT 25
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, cnt,v,tot,x,y,INF, sz;
ll a[200500], b[2000500], answers[200500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    string s,t;
    cin >> s;
    cin >> t;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            l++;
    }
    ll ans = l*(n-l);
    x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && t[i] == '1')
            x++;
        if (s[i] == '1' && t[i] == '1')
            y++;
    }
    ans -= x*y;
    cout << ans << endl;
    return 0;
}