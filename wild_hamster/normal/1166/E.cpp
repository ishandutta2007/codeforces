#include <algorithm>
#include <string>
#include <time.h>
#include <iostream>
#include <vector>
#include <utility>
#include <bitset>
#include <cmath>
#include <map>
#include <set>

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
#define MOD 1000003
typedef long long ll;
using namespace std;

ll x, y, z, n, m, q;
bitset<10005> a[55], b[55];
string pat = "aoeui";
int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        for (int j = 0; j < n; j++) {
            b[i][j] = 1;
        }
        for (int t = 0; t < x; t++) {
            int y;
            scanf("%d", &y);
            y--;
            a[i][y] = 1;
            b[i][y] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if ((a[i] & b[j]).count() == a[i].count()) {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }
    cout << "possible" << endl;
    return 0;
}