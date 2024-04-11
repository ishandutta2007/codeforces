#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;

ll dp[5];
int n;
string s;
ll cost[100005];
ll ndp[5];

void solve() {
  string match = "hard";
  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    cin >> cost[i];
  }
  for(int i = 1; i <= 4; i++) {
    dp[i] = 1LL << 60;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 5; j++) {
      ndp[j] = 1LL << 60;
    }
    for(int j = 0; j < 4; j++) {
      if(s[i] == match[j]) {
        ndp[j+1] = min(ndp[j+1], dp[j]);
      }
      else {
        ndp[j] = min(ndp[j], dp[j]);
      }
      ndp[j] = min(ndp[j], dp[j] + cost[i]);
    }
    memcpy(dp, ndp, sizeof(dp));
  }
  ll ret = dp[0];
  for(int i = 1; i < 4; i++) {
    ret = min(ret, dp[i]);
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  solve();
}