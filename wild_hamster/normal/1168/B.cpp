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
#define MOD 998244353
#define mp make_pair
#define X first
#define Y second
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[300500], b[100500];
bool good(ll x) {
    ll p = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] + x) % m < a[i] && (a[i] + x) % m >= p) {
            continue;
        }
        if (p <= a[i] + x && a[i] <= p) {
            continue;
        }
        if (a[i] > p) {
            p = a[i];
            continue;
        }
        return false;
    }
    return true;
}
int main() {
    string s;
    cin >> s;
    ll n = s.size();
    for (int i = 0; i < n; i++) {
        a[i] = n + 2;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 1000; j++) {
            if (i - 2 * j < 0) {
                break;
            }
            if (s[i] == s[i-j] && s[i-j] == s[i-2*j]) {
                a[i - 2*j] = min(a[i - 2 * j], i);
            }
        }
    }
    /*for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }*/
    //cout << endl;
    for (int i = n-2; i >= 0; i--) {
        a[i] = min(a[i], a[i+1]);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(0, n - a[i]);
    }
    cout << ans << endl;
    return 0;
}