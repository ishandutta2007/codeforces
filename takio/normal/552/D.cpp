#include <stdio.h>
#include <map>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#define LL long long
#define pii pair <int, int>
using namespace std ;

const int N = 2010;
int n;
int x[N], y[N];
map <pii, int> mp;
map <pii, int> :: iterator it;

LL solve (int k) {
    mp.clear();
    for (int i = 1; i <= n; i++) if (i != k) {
        int tx = x[k] - x[i], ty = y[k] - y[i];
        if (tx < 0) tx = -tx, ty = -ty;
        int g = __gcd (tx, ty);
        tx /= g, ty /= g;
        mp [pii (tx, ty)]++;
    }
    LL res = 0;
    for (it = mp.begin (); it != mp.end (); it++) {
        int tmp = (*it).second;
//        cout << k << ' ' << tmp << ' ' << 1LL * tmp * (tmp + 1) / 2 * (n - tmp - 1) << endl;
        res += 1LL * tmp * (n - tmp - 1);
    }
//    cout << "res " << k << ' ' << res << endl;
    return res;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &x[i], &y[i]);
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        res += solve (i);
    }
    cout << res / 6 << endl;
}