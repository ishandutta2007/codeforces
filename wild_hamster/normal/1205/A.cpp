#include <string>
#include <time.h>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>

#define MOD 998244353
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 1488228
ll x, y, n, m, k;
ll a[105][105], d[105][105];
int main() {
    cin >> n;
    if (n % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    ll p = 1;
    for (int i = 0; i < n; i++) {
        cout << p << " ";
        if (i % 2 == 0) {
            p += 3;
        } else {
            p += 1;
        }
    }
    p = 2;
    for (int i = 0; i < n; i++) {
        cout << p << " ";
        if (i % 2 == 1) {
            p += 3;
        } else {
            p += 1;
        }
    }
    cout << endl;
    return 0;
}