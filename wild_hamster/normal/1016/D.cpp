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
ll n,i,j,k,m,q,r,timer,v,tot,x,y,xx, yy,INF, sz;
ll a[300500], b[300500];

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x ^= a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        y ^= b[i];
    }
    if (x != y) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++)
            cout << 0 << " ";
        cout << a[i] << endl;
    }
    for (int i = 0; i < m-1; i++)
        cout << b[i] << " ";
    cout << (a[n-1]^y^b[m-1]) << endl;
    return 0;
}