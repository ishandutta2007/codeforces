#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<ll> a, b;
  int MOD = 998244353;
  for(int i = 0; i < n; i++) {
    ll t;
    cin >> t;
    ll lhs = i+1;
    ll rhs = n+1-lhs;
    t *= lhs;
    t *= rhs;
    a.push_back(t);
  }
  for(int i = 0; i < n; i++) {
    ll t;
    cin >> t;
    b.push_back(t);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  ll ret = 0;
  for(int i = 0; i < a.size(); i++) {
    ll inc = a[i];
    inc %= MOD;
    inc *= b[i];
    inc %= MOD;
    ret += inc;
    ret %= MOD;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}