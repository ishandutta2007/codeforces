#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, k;
  cin >> n >> k;
  map<int, int> dp;
  while(n--) {
    int a, b;
    cin >> a >> b;
    dp[2*a]++;
    dp[2*b+1]--;
  }
  int curr = 0;
  bool currGood = false;
  int lhs = -1;
  vector<pii> ret;
  for(auto out: dp) {
    int nextCoord = out.first;
    bool nextGood = curr + out.second >= k;
    if(currGood != nextGood) {
      if(nextGood) {
        lhs = nextCoord;
      }
      else {
        ret.push_back({lhs/2, (nextCoord-1)/2});
      }
    }
    curr += out.second;
    currGood = nextGood;
  }
  cout << ret.size() << "\n";
  for(pii out: ret) {
    cout << out.first << " " << out.second << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}