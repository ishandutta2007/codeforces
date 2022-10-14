#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
using namespace std;
#define OFF 400001
#define C 13000
#define NN 1000000
#define MOD 1000000007
ll n, x, k, z, m, pos, q, ans_v, y, root, xx;
ll ii;
ll a[55][55];
vector<pii> ans;
ll diff(string x, string y) {
    ll ans = 0;
    for (int i = 0; i < x.size(); i++) {
        ans += (x[i] != y[i]);
    }
    return ans;
}
int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
    ll t = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2 == 0) {
                a[i][j] = (1LL << (2 * n - i - j));
            } else {
                a[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    fflush(stdout);
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll sum = 0;
        cin >> sum;
        ll x = 1, y = 1;
        ans.clear();
        sum -= a[0][0];
        while (x + y != 2 * n) {
            ans.push_back(mp(x, y));
            if (x == n) {
                y++;
                continue;
            }
            if (y == n) {
                x++;
                continue;
            }
            if (a[x][y-1] > a[x-1][y]) {
                if (sum >= a[x][y-1]) {
                    x++;
                } else {
                    y++;
                }
            }  else {
                if (sum >= a[x-1][y]) {
                    y++;
                } else {
                    x++;
                }
            }
            sum -= a[x - 1][y - 1];
        }
        ans.push_back(mp(x, y));
        for (auto x : ans) {
            cout << x.X << " " << x.Y << "\n";
        }
        fflush(stdout);
    }
    return 0;
}