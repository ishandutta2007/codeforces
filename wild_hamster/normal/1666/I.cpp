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

ll n, t, k, x, y, m;
ll a[200500];
vector<ll> g[100500];
set<ll> f;
ll scan(ll x, ll y) {
  cout << "SCAN " << x << " " << y << endl;
  ll ans;
  cin >> ans;
  return ans;
}
ll dig(ll x, ll y) {
  cout << "DIG " << x << " " << y << endl;
  ll ans;
  cin >> ans;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    ll sum = scan(1, 1);
    ll ns = scan(n, 1);
    ll sumc = (ns + sum + 6 - 2 * n) / 2;
    ll sumr = sum + 4 - sumc;
    ll rmid = scan(sumr / 2, 1);

    ll distr = (rmid - sumc + 2);
    ll r1 = sumr / 2 + distr / 2 + distr % 2;
    ll r2 = sumr / 2 - distr / 2;

    ll cmid = scan(1, sumc / 2);
    ll distc = (cmid - sumr + 2);
    ll c1 = sumc / 2 + distc / 2 + distc % 2;
    ll c2 = sumc / 2 - distc / 2;
    if (dig(r1, c1)) {
      dig(r2, c2);
    } else {
      dig(r1, c2);
      dig(r2, c1);
    }
  }
  return 0;
}