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

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 1000000
#define OFF 200001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
vector<pii> g[200500];
ll a[1000500];
vector<ll> f;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        ll y;
        ll cool = 0;
        ll mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> y;
            if (y == x) {
                cool = 1;
            }
            mx = max(mx, y);
        }
        if (cool) {
            cout << 1 << "\n";
        } else {
            cout << max(2LL, (x - 1) / mx + 1) << "\n";
        }
    }
    return 0;
}