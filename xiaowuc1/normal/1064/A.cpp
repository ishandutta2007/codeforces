#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  vector<int> v;
  v.resize(3);
  cin >> v[0];
  cin >> v[1];
  cin >> v[2];
  int ret = 0;
  sort(v.begin(), v.end());
  while(v[0] + v[1] <= v[2]) {
    v[0]++;
    sort(v.begin(), v.end());
    ret++;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}