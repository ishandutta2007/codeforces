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
ll n,m,k, y, z, l, i, j, x;
ll  a[1500050], b[505000], p[500500], dp[500500], ans;
string d[55];
map<ll, ll> f;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int min_val = 0;
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                sum++;
            } else {
                sum--;
            }
            min_val = min(min_val, sum);
        }
        if (sum < 0) {
            if (min_val >= sum) {
                f[sum]++;
            }
        } else {
            if (min_val >= 0) {
                f[sum]++;
            }
        }
    }
    ll tot = f[0] / 2;
    for (auto &x : f) {
        if (x.first > 0) {
            tot += min(f[x.first], f[-x.first]);
        }
    }
    cout << tot << endl;
    return 0;
}