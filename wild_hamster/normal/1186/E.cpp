#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>

#define MOD 1000003
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair
typedef long long ll;
using namespace std;
ll n, m, k, x, y, z;
ll a[2005][2005], pa[2005][2005], ca[2005][2005], b[300500], cura[300500], curb[300500], q;
char s[1005];
ll bits(ll x) {
    y = 0;
    while (x > 0) {
        y += x%2;
        x /= 2;
    }
    return y;
}
ll f(ll x, ll y) {
    ll xx = x / (2*n) * 2 * n;
    ll yy = y / (2*m) * 2 * m;
    ll pshe = pa[x-xx][y-yy];
    if ((bits(x / (2*n)) +  bits(y / (2*m))) % 2) {
        pshe = ca[x-xx][y-yy];
    }
    ll ans = xx * yy / 2 + xx * (y - yy) / 2 + yy * (x - xx) / 2 + pshe;
    return ans;
}
int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; j < m; j++) {
            int x = s[j] - '0';
            a[i][j] = a[i+n][j+m] = x;
            a[i][j+m] = a[i+n][j] = 1 - x;
        }
    }
    for (int i = 1; i <= 2*n; i++) {
        for (int j = 1; j <= 2*m; j++) {
            pa[i][j] = pa[i-1][j] + pa[i][j-1] - pa[i-1][j-1] + a[i-1][j-1];
            ca[i][j] = ca[i-1][j] + ca[i][j-1] - ca[i-1][j-1] + 1 - a[i-1][j-1];
        }
    }

    for (int i = 0; i < q; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << f(x2,y2) - f(x1-1,y2) - f(x2, y1-1) + f(x1-1, y1-1) << "\n";
    }
    return 0;

}