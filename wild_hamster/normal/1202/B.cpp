#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>

#define MOD 1000000007
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 4005
ll x, y;
ll a[15][15];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    for (int i = 0; i + 1 < s.size(); i++) {
        a[s[i]-'0'][s[i+1]-'0']++;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            ll ans = 0;
            for (int k = 0; k < 10; k++) {
                for (int l = 0; l < 10; l++) {
                    if (a[k][l] == 0) {
                        continue;
                    }
                    ll pr = MOD;
                    for (int p = 0; p <= 10; p++) {
                        for (int r = 0; r <= 10; r++) {
                            if (p + r == 0) {
                                continue;
                            }

                            if ((k + p * i + r * j) % 10 == l) {
                                pr = min(pr, 0LL + p + r);
                            }
                        }
                    }
                    if (pr == MOD) {
                        ans = MOD;
                    } else {
                        ans += a[k][l] * (pr - 1);
                    }
                }
            }
            if (ans >= MOD) {
                cout << -1 << " ";
            } else {
                cout << ans << " ";
            }
        }
        cout << endl;
    }
    return 0;
}