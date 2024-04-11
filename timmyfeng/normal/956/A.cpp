#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  set<string> seen;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    seen.insert(s);
  }

  vector<int> cnt(m);
  for (auto& i : seen) {
    for (int j = 0; j < m; ++j) {
      cnt[j] += (i[j] == '#');
    }
  }

  cout << (*max_element(cnt.begin(), cnt.end()) <= 1 ? "Yes" : "No") << "\n";
}