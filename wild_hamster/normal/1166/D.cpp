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
ll a[155];
string pat = "aoeui";
int main() {
    ll q;
    cin >> q;
    while (q--) {
        ll l, r, x;
        cin >> l >> r >> x;
        ll fl = 0;
        if (l == r) {
            cout << 1 << " " << l << endl;
            continue;
        }
        x--;
        for (int i = 0; i < 50; i++) {
            if ((l + 1) * (1LL << i) > r) {
                break;
            }
            ll lft = r - (l + 1) * (1LL << i);

            if (lft <= (1LL<<i) * x) {
                a[0] = l;
                for (int j = 0; j <= i; j++) {
                    a[j+1] = 1;
                    for (int k = 0; k <= j; k++) {
                        a[j+1] += a[k];
                    }
                }
                for (int j = i; j >= 0; j--) {
                    ll pr = j;
                    if (pr > 0) {
                        pr--;
                    }
                    ll px = (lft >> pr);
                    px = min(px, x);
                    lft -= px * (1LL << pr);
                    for (int k = i+1-j; k <= i+1; k++) {
                        ll df = (k - (i+1-j));
                        if (df > 0) {
                            df--;
                        }
                        a[k] += px * (1LL << df);
                    }
                }
                cout << i+2;
                for (int k = 0; k <= i+1; k++) {
                    cout << " " << a[k];
                }
                cout << endl;
                fl = 1;
                break;
            }
        }
        if (!fl) {
            cout << -1 << endl;
        }
    }
    return 0;
}