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
ll a[105], rowmx[1005], rownow[1005][1005], colmx[1005], colnow[1005][1005];
map<ll, ll> f;
vector<ll> g[500500];
ll used[500500];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    ll m = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2)
            m++;
        z += x / 2;
        y = min(z, m);
        m -= y;
        z -= y;
        l += y;
        k += z;
        z = 0;
    }
    cout << l + k * 2 / 3 << endl;
    return 0;
}