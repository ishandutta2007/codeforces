#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 998244353
#define mp make_pair
#define X first
#define Y second
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll b[300500], c[300500];
ll a[300500];
ll Abs(ll x) {
    return (x > 0 ? x : -x);
}
struct suck {
    ll x;
    ll y;
    ll z;
};
std::vector<suck> f;
int main() {
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%I64d %I64d", &a[i], &b[i]);
        //cin >> a[i] >> b[i];
        ans += a[i];
    }
    if (ans < 0) {
        for (int i = 0; i < n; i++) {
            a[i] = -a[i];
        }
    }
    for (int i = 0; i < 62; i++) {
        long long p = 0;
        for (int j = 0; j < n; j++) {
            if ((b[j] >> i) & 1) {
                p -= a[j];
            } else {
                p += a[j];
            }
        }
        if (p < 0) {
            cout << (1LL << i) << endl;
            return 0;
        }
    }

    for (int i = 0; i < 42; i++) {
        for (int k = 0; k < 42; k++) {
            long long p = 0;
            for (int j = 0; j < n; j++) {
                if ((((b[j] >> i) & 1) + (b[j] >> k) & 1) & 1) {
                    p -= a[j];
                } else {
                    p += a[j];
                }
            }
            if (p < 0) {
                cout << (1LL << i) + (1LL << k) << endl;
                return 0;
            }
        }
    }
    cout << (1LL << 62) - 1;
    return 0;
}