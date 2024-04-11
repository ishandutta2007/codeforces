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
pii a[200500];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i <n ; i++) {
            cin >> a[i].X >> a[i].Y;
        }
        a[n] = {0, 0};
        n++;
        sort(a, a+n);
        bool good = true;
        for (int i = 0; i + 1 < n; i++) {
            if (a[i].X > a[i+1].X || a[i].Y > a[i+1].Y) {
                good = false;
                break;
            }
        }
        if (!good) {
            cout << "NO\n";
            continue;
        }

        string s;
        for (int i = 0; i + 1 < n; i++) {
            ll x = a[i+1].X - a[i].X;
            ll y = a[i+1].Y - a[i].Y;
            while (x > 0) {
                x--;
                s.push_back('R');
            }
            while (y > 0) {
                y--;
                s.push_back('U');
            }
        }
        cout << "YES\n";
        cout << s << "\n";

    }


    return 0;
}