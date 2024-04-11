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
#define MOD 1000000007
#define mp make_pair
#define X first
#define Y second
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[100500], b[100500];
ll dp[505][505];
ll fuck(ll a, ll b) {
    if (a != b && (a == 1 || b == 1)) {
        ll p = max(a, b);
        return p + 1;
    }
    return 0;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    ll x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            continue;
        }
        if (a[i] != 1) {
            if (a[i - 1] != 1) {
                cout << "Infinite" << endl;
                return 0;
            }
            if (i >= 2 && a[i - 2] == 3 && a[i] == 2) {
                z += 2;
            } else {
                z += a[i] + 1;
            }
        } else {
            z += a[i-1] + 1;
        }
    }
    cout << "Finite" << endl << z << endl;
    return 0;
}