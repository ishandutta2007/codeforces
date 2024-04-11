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
ll n,i,j,k,z,m,q,r,timer, cnt,v,tot,x,y,xx, yy,INF, sz;
vector<ll> mag;
int main() {
    //freopen("input.txt","r",stdin);
    int n;
    string s;
    cin >> n >> k >> s;
    r = n;
    for (int i = 1; i < n; i++)
    if (s.substr(0, n-i) == s.substr(i, n-i)) {
        r = i;
        break;
    }
    for (int i = 1; i < k; i++)
        s.append(s.substr(n-r, r));
    cout << s << endl;
    return 0;
}