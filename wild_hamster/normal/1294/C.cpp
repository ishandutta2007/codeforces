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
#define MOD 998244353
#define OFF 2001
ll n, x, k, z, m, pos, q, ans_v, y, mx;
ll x1, p1, x2;
vector<ll> f;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        f.clear();
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                n /= i;
                f.push_back(i);
            }
        }
        if (n != 1) {
            f.push_back(n);
        }
        if (f.size() >= 6) {
            cout << "YES\n";
            ll a = f[0];
            ll b = f[1] * f[2];
            ll c = 1;
            for (int j = 3; j < f.size(); j++) {
                c = c * f[j];
            }
            cout << a << " " << b << " " << c << "\n";
            continue;
        }

        ll sz = (1LL << (f.size()));
        ll fs = f.size();
        bool good = false;
        for (int i = 1; i < sz; i++) {
            for (int j = 1; j < sz; j++) {
                for (int k = 1; k < sz; k++) {
                    if ((i ^ j ^ k) == sz - 1 && (i + j + k) == sz - 1 && !good) {
                        ll a = 1, b = 1, c = 1;
                        for (int t = 0; t < fs; t++) {
                            if ((i >> t) & 1) {
                                a *= f[t];
                            }
                        }
                        for (int t = 0; t < fs; t++) {
                            if ((j >> t) & 1) {
                                b *= f[t];
                            }
                        }
                        for (int t = 0; t < fs; t++) {
                            if ((k >> t) & 1) {
                                c *= f[t];
                            }
                        }
                        if (a != b && b != c && a != c && !good) {
                            good = true;
                            cout << "YES\n";
                            cout << a << " " << b << " " << c << "\n";
                        }
                    }
                }
            }
        }
        if (!good) {
            cout << "NO\n";
        }
    }


    return 0;
}