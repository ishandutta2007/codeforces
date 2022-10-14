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
#include <stdint.h>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
ll a[MAXN], b[MAXN];
vector<ll> f;
vector<ll> g[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << 0 << endl;
        return 0;
    }
    if ( n < m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << (n + j + 1) * (i + 1) << " ";
            }
            cout << "\n";
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << (m + i + 1) * (j + 1) << " ";
            }
            cout << "\n";
        }
    }


    return 0;
}