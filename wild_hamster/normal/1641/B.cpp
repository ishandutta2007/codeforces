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
vector<ll> ans2;

ll process(ll pos, ll wasted) {
  for (int i = 0; i < pos; i++) {
    ans.push_back(mp(wasted + pos + i, a[i]));
  }
  ans2.push_back(2 * pos);
  wasted += 2 * pos;
  return wasted;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> t;
  for (int ii = 0; ii < t; ii++){
    ans.clear();
    cin >> n;
    f.clear();
    ans2.clear();
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      f[a[i]]++;
    }
    if (n % 2) {
      cout << -1 << "\n";
      continue;
    }
    bool bad = false;
    ll pnt = 0;
    for (auto e : f) {
      for (int i = 0; i < e.Y / 2; i++) {
        b[pnt++] = e.X;
      }
    }
    if (pnt != n / 2) {
      cout << -1 << "\n";
      continue;
    }
    for (int i = 0; i < n / 2; i++) {
      b[i + n / 2] = b[i];
    }
    ans.clear();
    ll wasted = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == b[i]) {
        continue;
      }
      ll pos = 0;
      for (int j = 0; j < i; j++) {
        if (a[j] == b[i]) {
          pos = j;
          break;
        }
      }
      if (pos != 0) {
        wasted = process(pos+1, wasted);
        reverse(a, a+pos+1);
      }
      wasted = process(i+1, wasted);
      reverse(a, a+i+1);
    }
    ans2.push_back(n);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i].X << " " << ans[i].Y << "\n";
    }
    cout << ans2.size() << "\n";
    for (int i = 0; i < ans2.size(); i++) {
      cout << ans2[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}