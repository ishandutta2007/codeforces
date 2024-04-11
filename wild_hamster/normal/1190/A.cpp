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
ll n, m, k, x, y, z;
ll a[200500];
bool cool(ll x, ll y) {
    //cout << x << " " << y << endl;
    if (x == 0) {
        return false;
    }
    if (k >= x && k < y) {
        return false;
    }
    return true;
}
int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    ll curm = 0;
    ll i = 0;
    while (i < m) {
        ll cr = ((a[i] - i) % k + k) % k;
        i++;
        ll p = 1;
        while (i < m && cool(cr, cr + a[i] - a[i-1])) {
            cr += a[i] - a[i-1];

            i++;
            p++;
        }
        //cout << p << endl;
        z++;
    }
    cout << z << endl;
    return 0;
}