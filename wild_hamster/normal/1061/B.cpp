#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
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
ll n,m,k, y, z, l, i, j, p;
ll a[100500];
set<ll> f;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    ll mx = 0;
    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
        if (a[i] > 0)
            k++;
    }
    ans = sum - (k+mx-1);
    sort(a, a+n);
    reverse(a, a+n);
    ll max_place = MOD;
    for (int i = 0; i < n; i++) {
        if (a[i] >= max_place) {
            if (max_place == 1)
                continue;
            max_place--;
            f.insert(max_place);
        } else if (a[i] < max_place) {
            max_place = a[i];
            f.insert(max_place);
        }
    }
    ans += f.size() - 1;
    cout << ans << endl;

    return 0;
}