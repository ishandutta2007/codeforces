#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int n;
void solve() {
  set<ll> s;
  cin >> n;
  while(n--) {
    ll t;
    cin >> t;
    s.insert(t);
  }
  vector<ll> gaps;
  for(ll out: s) {
    if(out == *s.rbegin()) continue;
    gaps.push_back(*s.upper_bound(out) - out);
  }
  gaps.push_back(2e18);
  sort(gaps.begin(), gaps.end());
  vector<ll> prefSum;
  prefSum.push_back(0);
  for(ll out: gaps) {
    prefSum.push_back(prefSum[prefSum.size()-1] + out);
  }
  int q;
  cin >> q;
  while(q--) {
    ll a, b;
    cin >> a >> b;
    ll sz = b - a + 1;
    if(sz < gaps[0]) {
      cout << sz * s.size() << " ";
      continue;
    }
    int lhs = 0;
    int rhs = gaps.size() ? gaps.size()-1 : 0;
    while(lhs != rhs) {
      int mid = (lhs+rhs+1)/2;
      if(gaps[mid] <= sz) lhs = mid;
      else rhs = mid-1;
    }
    ll ret = (sz) * (s.size() - lhs - 1) + (prefSum[lhs+1]);
    cout << ret << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
  solve();
}