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
ll Abs(ll x) {
    return (x > 0 ? x : -x);
}
int main() {
    cin >> n >> m >> k;
    if (n > m) {
        swap(n, m);
    }
    cout << n + m + 2 * k - max(0LL, m-n-1) << endl;
    return 0;
}