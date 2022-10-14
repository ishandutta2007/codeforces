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
ll b[3000500], a[3000500], c[300050], d[300500];
map<ll, ll> f, compr;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        f[x]++;
    }
    j = 0;
    for (auto [key, value] : f) {
        compr[key] = j++;
    }
    m = j;
    for (auto x : f) {
        a[compr[x.X]] = x.Y;
    }
    k *= 8;
    k /= n;
    if (k >= 30 || (1<<k) >= m) {
        cout << 0 << endl;
    } else {
        k = (1<<k);
        ll sum = 0;
        ll tot = 0;
        for (int j = 0; j < k; j++) {
            sum += a[j];
        }
        tot = sum;
        for (int j = k; j < m; j++) {
            sum += a[j] - a[j-k];
            tot = max(tot, sum);
        }
        cout << n - tot << endl;
    }
    return 0;

}