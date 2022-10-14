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

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 10000007
#define MOD 998244353
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2, a[100500];
vector<pii> f;

void solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (i < (k - 1) * 2) {
            a[i] = i % 2;
        } else if (i < (k-1) * 2 + (n - (k-1) * 2) / 2) {
            a[i] = 0;
        } else {
            a[i] = 1;
        }
    }
    f.clear();
    for (int i = 0; i < n; i++) {
        ll cur = 0;
        if (s[i] == ')') {
            cur = 1;
        }
        char needed = '(';
        if (a[i] == 1) {
            needed = ')';
        }
        if (cur != a[i]) {
            for (int j = i + 1; j < n; j++) {
                if (s[j] == needed) {
                    f.push_back(mp(i+1, j+1));
                    reverse(s.begin() + i, s.begin() + j + 1);
                    break;
                }
            }
        }
    }
    cout << f.size() << "\n";
    for (auto x : f) {
        cout << x.X << " " << x.Y << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}