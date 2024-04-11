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
#define N 10000000
#define OFF 400001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll ii;
ll a[200500], b[200500], c[200500];
vector<pii> f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        for (int j = 0; j < 20; j++) {
            if ((x >> j) & 1) {
                a[j]++;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll x = 0;
        for (int j = 0; j < 20; j++) {
            if (a[j] > i) {
                x |= (1<<j);
            }
        }
        ans += x * x;
    }
    cout << ans << "\n";
    return 0;
}