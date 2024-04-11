#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> v;
  v.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  set<int> s;
  while(m--) {
    int t;
    cin >> t;
    s.insert(t);
  }
  for(int out: v) {
    if(s.count(out)) cout << out << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}