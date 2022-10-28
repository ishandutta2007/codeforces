#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }

  for (int i = 1; i <= n; ++i) {
    int cur = i;
    set<int> visited;
    while (visited.count(cur) == 0) {
      visited.insert(cur);
      cur = p[cur];
    }
    cout << cur << " ";
  }
  cout << "\n";
}