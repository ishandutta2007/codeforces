
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
ll a[1000500], b[1005000], dp[1000500], used[1005000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        ll x = -1LL * MOD * MOD;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            x = max(x, a[i]);
        }
        for (int i = 0; i < n; i++) {
            a[i] = x - a[i];
        }
        if (k % 2 == 0) {

            x = -1LL * MOD * MOD;
            for (int i = 0 ;i < n; i++) {
                x = max(x, a[i]);
            }
            for (int i = 0; i < n; i++) {
                a[i] = x - a[i];
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}