#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void die() {
  cout << "-1\n";
  exit(0);
}

pii l[1000005];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  map<int, int> dp;
  while(n--) {
    int t;
    cin >> t;
    dp[t]++;
  }
  for(int i = 0; i < m; i++) {
    int t;
    cin >> t;
    l[i] = {t, i+1};
  }
  sort(l, l+m);
  queue<pii> ret;
  int idx = 0;
  for(int d = 0; !dp.empty() || idx < m; d++) {
    int allowed = k;
    while(dp.count(d)) {
      if(allowed > 0) {
        allowed--;
        if(--dp[d] == 0) dp.erase(d);
      }
      else {
        if(ret.empty()) {
          die();
        }
        ret.pop();
      }
    }
    while(allowed > 0 && idx < m) {
      if(l[idx].first >= d) {
        ret.push(l[idx]);
        allowed--;
      }
      idx++;
    }
  }
  cout << ret.size() << "\n";
  while(ret.size()) {
    cout << ret.front().second << " ";
    ret.pop();
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}