#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<bool> possible(m);
  for (int i = 0; i < n && !possible[0]; ++i) {
    int a;
    cin >> a;
    vector<bool> new_possible(m);
    for (int j = 0; j < m; ++j) {
      if (possible[j]) {
        new_possible[j] = true;
        new_possible[(j + a) % m] = true;
      }
    }
    new_possible[a % m] = true;
    possible = new_possible;
  }

  cout << (possible[0] ? "YES" : "NO") << "\n";
}