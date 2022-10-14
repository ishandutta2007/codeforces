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
ll n,i,j,k,z,m,q,r,timer,v,tot,x,y,xx, yy,INF, sz;
ll a[100500], cnt[100500], col[100500];

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    //cout << n << " " << m << endl;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        if (c == 'B')
            x += i, y += j, z++;
    }
    x /= z;
    y /= z;
    cout << x+1 << " " << y+1 << endl;
    return 0;
}