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
int d[255][505][505];
char s[505][505];
bool check(ll l1, ll r1, ll l2, ll r2, char c) {
    for (int i = l1; i <= l2; i++) {
        for (int j = r1; j <= r2; j++) {
            if (i < 0 || i >= n || j < 0 || j >= m) {
                return false;
            }
            if (s[i][j] != c) {
                return false;
            }
        }
    }
    return true;
}
bool get(ll k, ll l1, ll r1, ll l2, ll r2) {
    if (l1 > l2 || r1 > r2) {
        return false;
    }
    ll sum = d[k][l2][r2] - d[k][l1-1][r2] - d[k][l2][r1-1] + d[k][l1-1][r1-1];
    return (sum > 0);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 1; k <= 251; k++) {
                bool cool = (
                        check(i - k + 1, j - k + 1, i, j, 'R') &
                        check(i - k + 1, j + 1, i, j + k, 'G') &
                        check(i + 1, j - k + 1, i + k, j, 'Y') &
                        check(i + 1, j + 1, i + k, j + k, 'B')
                );
                if (!cool) {
                    for (int l = 1; l < k; l++) {
                        d[l][i+1][j+1] = 1;
                    }
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= 251; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                d[i][j][k] = d[i][j-1][k] + d[i][j][k-1] - d[i][j-1][k-1] + d[i][j][k];
            }
        }
    }

    for (int i = 0; i < q; i++) {
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        ll hyu = 0;
        for (int k = 250; k >= 1; k--) {
            if (get(k, l1 + k - 1, r1 + k - 1, l2 - k, r2 - k)) {
                cout << k * k * 4 << "\n";
                hyu = 1;
                break;
            }
        }
        if (!hyu) {
            cout <<  0 << "\n";
        }
    }

    return 0;
}