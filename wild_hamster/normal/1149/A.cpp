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

ll a[300500], x, y, z, n, m;

ll Abs(ll x) {
    return (x > 0 ? x : -x);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    if (a[2] == 0) {
        for (int i = 0; i < n; i++) {
            cout << 1 << " ";
        }
        return 0;
    }
    if (a[1] == 0) {
        for (int i = 0; i < n; i++) {
            cout << 2 << " ";
        }
        return 0;
    }
    cout << 2 << " " << 1;
    a[2]--;
    a[1]--;
    for (int i = 0; i < a[2]; i++) {
        cout << " " << 2;
    }
    for (int i = 0; i < a[1]; i++) {
        cout << " " << 1;
    }

    return 0;
}