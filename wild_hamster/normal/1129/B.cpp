#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 1000000007
#define mp make_pair
#define X first
#define Y second
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x;
ll a[200500], b[200500];
vector<ll> g[100500];
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

ll binpow(ll x, ll y) {
    if (y == 0)
        return 1;
    ll tmp = binpow(x, y/2);
    tmp = tmp * tmp % MOD;
    if (y % 2)
        return x * tmp % MOD;
    return tmp;
}
bool check() {
    ll ans = 0;
    b[0] = 0;
    for (int i = 1; i <= l; i++)
        b[i] = b[i-1] + a[i-1];
    for (int i = 0; i < l; i++) {
        for (int j = i; j < l; j++) {
            ll sum = b[j+1] - b[i];
            ans = max(ans, sum * (j-i+1));
        }
    }
    if (ans - z != k) {

        cout << ans << " " << z << endl;
        return false;
    }
    return true;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> k;
    ll mx;
     {
        for (mx = 999999; mx >= 0; mx--) {
            for (int d = 7; d < 2000; d += 2) {
                if ((k + mx) % d == 0 && (k + mx) / d + d - 1 <= mx) {

                    ll diff = mx - (k + mx) / d;
                    z = mx;
                    l = d;
                    a[0] = -(diff - (d - 2));
                    for (int i = 1; i < d - 1; i++)
                        a[i] = -1;
                    a[d - 1] = mx;
                    swap(a[0], a[d - 2]);

                    if (!check()) {
                        continue;
                    }
                    mx = -5;
                    cout << d << endl;
                    for (int i = 0; i < d; i++)
                        cout << a[i] << " ";
                    cout << endl;
                    break;
                }
            }
        }
        if (mx != -6) {
            cout << "hyU";
            return 1;
        }
    }
    return 0;
}