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
#include <fstream>

#define pii pair<ll,ll>
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
using namespace std;
#define OFF 400001
#define C 13000
#define NN 1000000
#define MOD 1000000007
ll n, x, k, z, m, pos, q, ans_v, y, root, xx;
ll ii;
ll a[1005005], b[505];
vector<pii> ans;
ll diff(string x, string y) {
    ll ans = 0;
    for (int i = 0; i < x.size(); i++) {
        ans += (x[i] != y[i]);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(0));
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll l = 0, r = (ll)1e+12 + 10;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if ((mid + mid + n - 1) * n / 2 <= sum) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = l + i;
        sum -= l + i;
    }
    for (int i = 0; i < sum; i++) {
        a[i]++;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}