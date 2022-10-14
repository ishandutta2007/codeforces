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
ll a[100500];
vector<pair<string, ll> > f;
vector<pair<ll, string> > ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> n >> m >> k;
    if (k > 4 * m * n - 2 * m - 2 * n) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n-1; i++) {
        f.emplace_back("RDU", m-1);
        f.emplace_back("L", m-1);
        f.emplace_back("D", 1);
    }
    f.emplace_back("R", m-1);
    f.emplace_back("L", m-1);
    f.emplace_back("U", n-1);
    ll sum = 0;
    for (auto x : f) {
        if (k >= x.X.size() * x.Y) {
            k -= x.X.size() * x.Y;
            if (x.Y > 0) {
                ans.push_back(mp(x.Y, x.X));
            }
        } else {
            if (k / (x.X.size()) > 0) {
                ans.push_back(mp(k / (x.X.size()), x.X));
            }
            k %= x.X.size();
            for (int j = 0; j < k; j++) {
                string hyu;
                hyu.push_back(x.X[j]);
                ans.push_back(mp(1LL, hyu));
            }
            break;
        }
    }
    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x.X << " " << x.Y << "\n";
    }


    return 0;
}