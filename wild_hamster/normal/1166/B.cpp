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
typedef int ll;
using namespace std;

ll a[300500], x, y, z, n, m, q;
ll b[500500];
string pat = "aoeui";
int main() {
    cin >> n;
    for (int i = 5; i <= n; i++) {
        if (n % i == 0) {
            ll j = n / i;
            if (j >= 5) {
                for (int k = 0; k < i; k++) {
                    for (int l = 0; l < j; l++) {
                        cout << pat[(k+l)%5];
                    }
                }
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}