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
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (n == 1) {
            cout << "T" << "\n";
            continue;
        }
        sort(a, a+n);
        if (a[n-1] > sum - a[n-1] || sum % 2 == 1) {
            cout << "T" << "\n";
        } else {
            cout << "HL" << "\n";
        }
    }

    return 0;
}