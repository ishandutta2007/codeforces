#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

vector<vector<int>> load(int n, int m) {
  vector<vector<int>> ret;
  ret.resize(n+m-1);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int t;
      cin >> t;
      ret[i+j].push_back(t);
    }
  }
  for(int i = 0; i < ret.size(); i++) sort(ret[i].begin(), ret[i].end());
  return ret;
}

void solve() {
  int n, m;
  cin >> n >> m;
  if(load(n, m) == load(n, m)) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}