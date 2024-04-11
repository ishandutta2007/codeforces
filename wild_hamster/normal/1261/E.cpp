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
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
ll a[1005];
bitset<1005> b[1005];
bitset<1005> curset;
vector<pii> f;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        bool only_ones = true;
        for (int j = 0; j < n; j++) {
            if (a[j] > 1) {
                only_ones = false;
            }
        }
        ll took_one = 0;
        f.clear();
        for (int j = 0; j < n; j++) {
            if (a[j] != 0) {
                if (a[j] != 1 || took_one == 0 || only_ones) {
                    f.push_back(mp(a[j], j));
                    if (a[j] == 1) {
                        took_one++;
                    }
                }
            }
        }
        sort(f.begin(), f.end());
        reverse(f.begin(), f.end());
        curset.reset();
        for (auto x : f) {
            ll y = x.Y;
            curset[y] = 1;
            bool good = true;
            for (int j = 0; j < i; j++) {
                if (curset == b[j]) {
                    good = false;
                    break;
                }
            }
            if (!good) {
                curset[y] = 0;
            }
        }
        for (int j = 0; j < n; j++) {
            a[j] -= curset[j];
        }
        b[i] = curset;
    }

    ll sum = 0;
    for (int i = 0; i <= n; i++) {
        if (b[i].count()) {
            sum++;
        }
    }
    cout << sum << "\n";
    for (int i = 0; i <= n; i++) {
        if (b[i].count()) {
            for (int j = 0; j < n; j++) {
                cout << b[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}