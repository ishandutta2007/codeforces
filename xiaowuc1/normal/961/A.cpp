#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

int r[1005];
void solve() {
  int k, n;
  cin >> k >> n;
  while(n--) {
    int t;
    cin >> t;
    r[t]++;
  }
  int ret = 1e9;
  for(int i = 1; i <= k; i++) ret = min(ret, r[i]);
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}