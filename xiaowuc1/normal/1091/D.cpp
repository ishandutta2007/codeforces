#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;

int l[50];
// 1, 2, 9, 56, 395,   3084,   26621,    253280,   2642391, 30052700

const int MOD = 998244353;

void solve() {
  int n;
  cin >> n;
  ll ret = 0;
  ll f = 1;
  for(int i = 2; i <= n; i++) {
    f *= i;
    f %= MOD;
  }
  ret += f;
  ll s = 1;
  for(int i = n; i > 2; i--) {
    s *= i;
    s %= MOD;
    ret += f-s;
    ret %= MOD;
    ret += MOD;
    ret %= MOD;
  }
  cout << ret << endl;
  /*
  for(int i = 0; i < n; i++) {
    l[i] = i+1;
  }
  vector<int> v;
  do {
    for(int i = 0; i < n; i++) {
      v.push_back(l[i]);
    }
  }
  while(next_permutation(l, l+n));
  map<int, int> dp;
  ll ret = 0;
  for(int i = 0; i + n <= v.size(); i++) {
    int c = 0;
    for(int j = 0; j < n; j++) {
      c += v[i+j];
    }
    if(c == n*(n+1)/2) {
      dp[i%n]++;
      ret++;
    }
  }
  for(auto x: dp) {
    cout << x.first << " " << x.second << endl;
  }
  cout << ret << endl;
  */
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  solve();
}