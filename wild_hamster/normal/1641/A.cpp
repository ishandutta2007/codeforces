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
ll a[200500], b[100500];
map<ll, ll> f;
vector<pii> ans;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> t;
  for (int ii = 0; ii < t; ii++){
    cin >> n >> x;
    f.clear();
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      f[a[i]]++;
    }
    ll ans = 0;
    while (!f.empty()) {
      auto it = f.begin();
      if (it->Y == 0) {
        f.erase(it);
        continue;
      }
      ll p = it->X;
      ll y = it->Y;
      ll pp = 0;
      if (f.find(p * x) != f.end()) {
        pp = f[p*x];
      }
      if (pp > y) {
        f[p*x] -= y;
      } else {
        ans += y - pp;
        f.erase(p * x);
      }
      f.erase(p);
    }
    cout << ans << "\n";
  }
  return 0;
}