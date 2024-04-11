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
#include <string>
#include <time.h>
#include <stack>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 305000
#define MOD 998244353
ll n, x, k, z, m, pos;

ll a[100500], b[100500];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll flag = 0;
        for (int i = 0; i + 1 < n; i++) {
            ll nxt = max(a[i+1] - k, 0LL);
            if (nxt > a[i]) {
                m -= (nxt - a[i]);
                if (m < 0) {
                    flag = 1;
                    continue;
                }
            } else {
                m += a[i] - nxt;
            }
        }
        if (flag) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}