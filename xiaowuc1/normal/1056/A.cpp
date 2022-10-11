#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n;
  cin >> n;
  map<int, int> dp;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    while(a--) {
      int b;
      cin >> b;
      dp[b]++;
    }
  }
  for(auto x: dp) {
    if(x.second == n) cout << x.first << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}