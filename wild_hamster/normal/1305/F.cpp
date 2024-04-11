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
#define OFF 2001
#define N 100000000
#define PI 3.14159265358979323846
ll n, x, k, z, m, pos, q, ans_v, y, mx;
ll x1, p1, x2;
ll MOD = 1000000000 + 7;
ll a[200500];
map<ll, ll> f;
ll cls(ll x, ll y) {
    ll z = (x / y) * y;
    if (z == 0) {
        return y - x;
    }
    return min(x - z, z + y - x);
}
vector<ll> pool;
string s = "dsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijokldfrthjbiortghiorthjbidrstijdrsbgvdersnfgvlpaewkcfioaw3jnreughdsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijokldfrthjbiortghiorthjbidrstijdrsbgvdersnfgvlpaewkcfioaw3jnreughdsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijokldfrthjbiortghiorthjbidrstijdrsbgvdersnfgvlpaewkcfioaw3jnreughdsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijokldfrthjbiortghiorthjbidrstijdrsbgvdersnfgvlpaewkcfioaw3jnreughdsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijokldfrthjbiortghiorthjbidrstijdrsbgvdersnfgvlpaewkcfioaw3jnreughdsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijokldfrthjbiortghiorthjbidrstijdrsbgvdersnfgvlpaewkcfioaw3jnreughdsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijokldfrthjbiortghiorthjbidrstijdrsbgvdersnfgvlpaewkcfioaw3jnreughdsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijokldfrthjbiortghiorthjbidrstijdrsbgvdersnfgvlpaewkcfioaw3jnreughdfkgjdkfhjdkfhjkdfhjkdfhjdkfkgjdfkgjdsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijodsjdsgjuhjorstjorstghersgvghuersaershjouijoijoijokldfrthjbiortghiorthjbidrstijdrsbgvdersnfgvlpaewkcfioaw3jnreugh";
bool p(ll x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
    ll hyu = 0;
    for (int i = 0; i < s.size(); i++) {
        hyu = (hyu * 26 + s[i] - 'a') % MOD;
    }
    srand(time(0) + hyu);
 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n <= 30) {
        for (int i = 0; i < n; i++) {
            for (int j = -1; j <= 1; j++) {
                if (a[i] + j > 1) {
                    pool.push_back(a[i] + j);
                }
            }
        }
    } else {
        for (int i = 0; i < 35; i++) {
            ll x = (rand() * 30LL + rand()) % n;
            for (int j = -1; j <= 1; j++) {
                if (a[x] + j > 1) {
                    pool.push_back(a[x] + j);
                }
            }
        }
    }
    /*for (auto x : pool) {
        cout << x << "\n";
    }*/
 
    ll ans = n;
    ll sum = 0;
 
    for (auto x : pool) {
        for (ll i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                ll sum = 0;
                for (int j = 0; j < n; j++) {
                    sum += cls(a[j], i);
                }
                ans = min(ans, sum);
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        
            if (x > 1) {
                ll sum = 0;
                for (int j = 0; j < n; j++) {
                    sum += cls(a[j], x);
                }
                ans = min(ans, sum);
            }
 
    }
    cout << ans << "\n";
    return 0;
}