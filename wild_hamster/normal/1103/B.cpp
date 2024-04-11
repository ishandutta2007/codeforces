#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
#include <time.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, p, x;
ll a[500500], b[500050], pa[500500], dp[500500], ans, BB;
ll binpow(ll x, ll y) {
    if (y == 0)
        return 1;
    ll tmp = binpow(x, y/2);
    tmp = tmp * tmp % MOD;
    if (y % 2 == 0)
        return tmp;
    return x * tmp % MOD;
}

ll Abs(ll x) {
    return x>0?x:-x;
}

string check(ll x, ll y) {
    if (x % BB >= y % BB) {
        return "x";
    }
    return "y";
}

string query(ll x, ll y) {
    p++;
    cout << "? " << x << " " << y << endl;
    fflush(stdout);
    string ans;
    //ans = check(x, y);
    cin >> ans;
    return ans;
}

void play() {
    p = 0;
    ll ans = 29;
    for (int i = 0; i < 29; i++) {
        string r = query((1 << i) - 1, (1 << (i+1)) - 1);
        if (r == "x") {
            ans = i;
            break;
        }
    }
    ll l = (1<<ans), r = ((1<<(ans+1)) - 1);
    while (l < r) {
        ll mid = (l + r) / 2;
        string rr = query(mid, r);
        if (rr == "x") {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << "! " << r << endl;
    //assert(r == BB && p <= 60);
    fflush(stdout);
    return;
}

int main() {
    std::string s;
    while (cin >> s) {
        if (s == "end") {
            return 0;
        }
        play();
    }
    return 0;
}