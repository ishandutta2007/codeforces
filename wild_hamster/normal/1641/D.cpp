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
ll b[100500];
map<ll, ll> f, g;
pair<ll, vector<ll> > a[100500];
bitset<100005> cur;
bitset<100005> shits[505];
vector<ll> bigs, smalls;
vector<ll> nuggets[500500];


int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> x;
      f[x]++;
      a[i].Y.push_back(x);
    }
    cin >> a[i].X;
  }
  sort(a, a + n);
  for (auto it : f) {
    if (it.Y > 1000) {
      bigs.push_back(it.X);
    } else {
      smalls.push_back(it.X);
    }
  }
  for (int i = 0; i <= 500; i++) {
    shits[i].set();
  }
  for (int i = 0; i < bigs.size(); i++) {
    g[bigs[i]] = i;
  }
  for (int i = 0; i < smalls.size(); i++) {
    g[smalls[i]] = i + (int)bigs.size();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i].Y[j] = g[a[i].Y[j]];
      if (a[i].Y[j] < bigs.size()) {
        shits[a[i].Y[j]][i] = 0;
      } else {
        nuggets[a[i].Y[j]].push_back(i);
      }
    }
  }
  ll ans = (ll)1e+18;
  for (int i = 0; i < n; i++) {
    cur.set();
    for (int j = 0; j < m; j++) {
      ll val = a[i].Y[j];
      if (val < bigs.size()) {
        cur &= shits[val];
      } else {
        for (auto k : nuggets[val]) {
          cur[k] = 0;
        }
      }
    }
    ll pos = cur._Find_first();
    if (pos < n) {
      ans = min(ans, a[pos].X + a[i].X);
    }
  }
  if (ans == (ll)1e+18) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
  return 0;
}