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
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output3.txt", "w", stdout);
    //cin >> n >> m;
    //n = 1000, m = 1000;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] == 1 || b[i] == 1) {
            cout << -1 << endl;
            return 0;
        }
        //a[i] = 2, b[i] = 2;
    }
    double l = 0, r = 10000000000;
    for (int i = 0; i < 100; i++) {
        double mid = (l+r)/2;
        double mass = mid + m;
        for (int j = 0; j < n; j++) {
            mass -= 1. * mass / a[j];
            mass -= 1. * mass / b[(j+1)%n];
        }
        if (mass >= m)
            r = mid;
        else
            l = mid;
    }
    printf("%.10f\n", l);
    return 0;
}