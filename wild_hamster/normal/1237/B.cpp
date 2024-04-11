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
#define MAXN (1<<20)
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;
ll x1, p1, x2, p2;

ll a[600500], b[600500], p[600500];
set<ll> g;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[a[i]] = i;
        g.insert(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll pos = 0;
    ll x = -1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {


        if (p[b[i]] > *(g.begin())) {
            ans++;
        }

        g.erase(p[b[i]]);
    }
    cout << ans << endl;
    return 0;
}