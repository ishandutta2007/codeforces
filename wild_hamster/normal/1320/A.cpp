
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
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 1000000
#define OFF 400001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll d[85][85];
ll a[500500], b[500500];
vector<ll> g[1000500];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        g[x - i + OFF].push_back(i);
    }
    ll ans = 0;
    for (int i = 0; i < 1000000; i++) {
        ll sum = 1LL * (i - OFF) * (ll)g[i].size();
        for (auto x : g[i]) {
            sum += x;
        }
        ans = max(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}