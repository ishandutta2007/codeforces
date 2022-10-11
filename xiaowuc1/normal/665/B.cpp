#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, m, k;
  vector<int> dp;
  cin >> n >> m >> k;
  dp.resize(k);
  for(int i = 0; i < k; i++) cin >> dp[i];
  int ret = 0;
  for(int qq = 0; qq < n*m; qq++) {
    int want;
    cin >> want;
    bool found = false;
    for(int i = 0; i < k; i++) {
      if(dp[i] == want) {
        found = true;
        ret += i+1;
        dp.erase(dp.begin() + i);
        dp.insert(dp.begin(), want);
        break;
      }
    }
    assert(found);
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}