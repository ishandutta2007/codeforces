#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, k;
  cin >> n >> k;
  map<ll, int> dp;
  dp[0LL] = k;
  while(n--) {
    ll s, m;
    cin >> s >> m;
    s = max(s, dp.begin()->first);
    ll key = dp.begin()->first;
    cout << s+m << endl;
    if(--dp[key] == 0) dp.erase(key);
    dp[s+m]++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}