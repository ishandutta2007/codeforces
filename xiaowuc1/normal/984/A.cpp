#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  int n;
  cin >> n;
  vector<int> v;
  v.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  while(v.size() > 1) {
    v.pop_back();
    if(v.size() > 1) v.erase(v.begin());
  }
  cout << v[0] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}