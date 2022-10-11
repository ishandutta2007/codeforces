#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  map<int, int> dp;
  int n;
  cin >> n;
  while(n--) {
    int a;
    cin >> a;
    dp[a]++;
  }
  int ret = 0;
  for(auto x: dp) {
    ret += x.second;
    for(int i = 0; i <= 30; i++) {
      int goal = (1<<i) - x.first;
      if(goal == x.first && dp[goal] >= 2) {
        ret -= x.second;
        break;
      }
      if(goal != x.first && dp.count(goal)) {
        ret -= x.second;
        break;
      }
    }
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}