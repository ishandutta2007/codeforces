#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int dp[200005];
void solve() {
  string s;
  cin >> s;
  for(int i = 0; i < s.size(); i++) {
    int curr = 0;
    for(int j = 1; j <= 3 && i + j <= s.size(); j++) {
      if(j > 1 && s[i] == '0') continue;
      curr = 10 * curr + s[i+j-1] - '0';
      dp[i+j] = max(dp[i+j], dp[i] + (curr%3 == 0 ? 1 : 0));
    }
  }
  cout << dp[s.size()] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}