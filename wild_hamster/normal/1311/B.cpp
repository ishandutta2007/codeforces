#include <time.h>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <stdint.h>
#include <assert.h>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 1000000000
#define OFF 2001
#define N 100000000
#define PI 3.14159265358979323846
ll n, x, k, z, m, pos, q, ans_v, y, mx;
ll x1, p1, x2;
ll a[105], b[105];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(b, b+m);
        ll s = 1;
        for (int i = 0; i + 1 < m; i++) {
            if (b[i] + 1 == b[i + 1]) {
                s++;
            } else {
                sort(a + b[i] - s, a + b[i] + 1);
                s = 1;
            }
        }
        sort(a + b[m-1] - s, a + b[m-1] + 1);
        ll good = 1;
        for (int i = 0; i + 1 < n; i++) {
            if (a[i] > a[i+1]) {
                good = 0;
            }
        }
        cout << (good ? "YES" : "NO") << "\n";
    }

    return 0;
}