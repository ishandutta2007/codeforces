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
vector<ll> g[500500];
ll a[100500];

int main() {
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll n = s.size();
        ll mx = -1;
        ll mn = n + 1;
        ll ones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                mn = min(mn, 1LL * i);
                mx = max(mx, 1LL * i);
                ones++;
            }
        }
        if (ones == 0) {
            cout << 0 << "\n";
        } else {
            cout << mx - mn + 1 - ones << "\n";
        }
    }
    return 0;
}