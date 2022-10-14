#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
#include <time.h>
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
#define MOD ((1<<30)-1)
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, p, x;
ll  a[500050], b[505], pa[500500], dp[500500], ans;
ll Abs(ll x) {
    return x>0?x:-x;
}
string s[305];
multiset<int> f;
int main() {
    cin >> n >> k;
    for (int i = 0; i < 30; i++) {
        if (((1<<i)&n) != 0) {
            f.insert(1<<i);
        }
    }
    if (k < f.size() || k > n) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    while (k > f.size()) {
        auto it = prev(f.end());
        x = *it;
        f.erase(it);
        f.insert(x / 2);
        f.insert(x / 2);
    }
    for (auto &x : f) {
        cout << x << " ";
    }
    return 0;
}