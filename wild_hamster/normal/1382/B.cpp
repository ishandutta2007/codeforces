
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

typedef int ll;
using namespace std;
#define N 10000000
#define OFF 400001
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root, xx;
ll ii;
ll a[100500];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    reverse(a, a+n);
    ll x = 0;
    for (int i = 0; i < n; i++) {
        if (x == 0) {
            x = 1;
        } else {
            x = (a[i] != 1);
        }
    }
    cout << (x ? "First" : "Second") << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}