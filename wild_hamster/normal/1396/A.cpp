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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << " " << 1 << "\n" << -a[0] << "\n";

        cout << 1 << " " << 1 << "\n" << 0 << "\n";

        cout << 1 << " " << 1 << "\n" << 0 << "\n";
        return 0;
    }
    cout << n << " " << n << "\n";
    cout << -a[n-1] << "\n";
    a[n-1] = 0;

    cout << 1 << " " << n - 1 << "\n";
    for (int i = 0; i < n - 1; i++) {
        ll x = ((a[i] + 1LL * n * MOD) % n) * (n - 1);
        cout << x << " ";
        a[i] += x;
    }
    cout << "\n";

    cout << 1 << " " << n << "\n";
    for (int i = 0; i < n; i++) {
        ll x = -(a[i] / n * n);
        a[i] += x;
        cout << x << " " ;
    }
    cout << "\n";
    /*for (int i = 0; i < n; i++) {
        cout << a[i] << " " ;
    }
    cout << "\n";*/
    return 0;
}