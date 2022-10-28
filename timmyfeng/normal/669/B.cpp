#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string d;
  cin >> n >> d;

  vector<int> l(n);
  for (auto &i : l) {
    cin >> i;
  }

  int u = 0;
  for (int i = 0; i < n && u >= 0 && u < n; ++i) {
    if (d[u] == '>') {
      u += l[u];
    } else {
      u -= l[u];
    }
  }

  cout << (u >= 0 && u < n ? "INFINITE" : "FINITE") << "\n";
}