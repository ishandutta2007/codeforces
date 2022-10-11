#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

map<int, int> dp[2];

void solve() {
  int n;
  cin >> n;
  int curr = 0;
  dp[1][0] = 1;
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    curr ^= t;
    ret += dp[i%2][curr]++;
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}