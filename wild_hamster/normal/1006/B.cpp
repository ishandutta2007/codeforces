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
ll b[200500], d[200500];
pii a[200500];
vector<ll> f;
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output3.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].X;
        a[i].Y = i+1;
    }
    sort(a, a+n);
    reverse(a, a+n);
    for (int i = 0; i < k; i++) {
        x += a[i].X;
        f.push_back(a[i].Y);
    }
    cout << x << endl;
    sort(f.begin(), f.end());
    if (k == 1) {
        cout << n << endl;
        return 0;
    }
    cout << f[0];
    for (int i = 0; i+2 < k; i++)
        cout << " " << f[i+1] - f[i];
    cout << " " << n - f[k-2] << endl;

    return 0;
}