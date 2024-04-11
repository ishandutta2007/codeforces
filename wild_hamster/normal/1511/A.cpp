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
ll n, k, z, m, pos, q, ans_v, y, root, xx;
ll ii, r1, r2, r3, l;
ll a[2005005], b[2005000];
vector<ll> g[100500];
ll val[6500];
ll cur_edge = 0;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll g = 0, b = 0;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            if (x == 1) {
                g++;
            }
            if (x == 3 ) {
                g++;
            }
        }
        cout << g << "\n";
    }

    return 0;
}