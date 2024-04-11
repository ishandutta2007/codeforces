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
#define MAXN 300500
#define MOD 998244353
ll n, x, k, z, m, pos, q;

ll a[200500], b[200500], d[150];

set<pii> f;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        string s;
        cin >> s;
        string t;
        string ans;
        ll pshe = 0;
        for (int i = 0; i <= 10; i++) {
            t.clear();
            ll k = -1;
            for (int j = 0; j < n; j++) {
                if (s[j] < i + '0') {
                    t.push_back(s[j]);
                    k = j;
                }
            }

            for (int j = k; j < n; j++) {
                if (s[j] == i + '0') {
                    t.push_back(s[j]);
                }
            }

            for (int j = 0; j < n; j++) {
                if (s[j] > i + '0' || (s[j] == i + '0' && j < k)) {
                    t.push_back(s[j]);
                }
            }
            ll good = 1;
            for (int j = 0; j + 1 < n; j++) {
                if (t[j] > t[j+1]) {
                    good = 0;
                }
            }
            if (good) {
                for (int j = 0; j < n; j++) {
                    if (s[j] < i + '0' || (s[j] == i + '0' && j > k)) {
                        cout << 1;
                    } else {
                        cout << 2;
                    }
                }
                cout << "\n";
                pshe = 1;
                break;
            }
        }
        if (!pshe) {
            cout << "-\n";
        }
    }



    return 0;
}