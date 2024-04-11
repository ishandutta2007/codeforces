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
ll n,m,k,x,  y, z, l, r, i, j, p[335], q;
ll a[1005][1005], w[300500];
vector<pii> ans, f;
void go(ll x1, ll y1, ll x2, ll y2, ll val) {
    if (val == 0) {
        for (int i = min(x1, x2); i <= max(x1, x2); i++)
            a[i][y1] = 1;
        for (int i = min(y1, y2); i <= max(y1, y2); i++)
            a[x2][i] = 1;
        } else if (val == 1) {
            for (int i = min(x1, x2); i <= max(x1, x2); i++)
            a[i][y2] = 1;
        for (int i = min(y1, y2); i <= max(y1, y2); i++)
            a[x1][i] = 1;
        }
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        w[x]++;
        w[y]++;
    }
    for (int i = 1; i <= n; i++)
    if (w[i] == 1) {
        k++;
    }
    printf("%.9f\n", 1. * m * 2 / k);
    return 0;
}