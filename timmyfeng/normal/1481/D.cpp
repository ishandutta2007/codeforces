#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<string> label(n);
  for (auto &i : label) {
    cin >> i;
  }

  if (m % 2 == 1) {
    cout << "YES\n";
    for (int k = 0; k <= m; ++k) {
      cout << 1 + k % 2 << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (label[i][j] == label[j][i]) {
        cout << "YES\n";
        for (int k = 0; k <= m; ++k) {
          cout << (k % 2 == 0 ? i : j) + 1 << " ";
        }
        cout << "\n";
        return;
      }
    }
  }

  if (n == 2) {
    cout << "NO\n";
    return;
  }

  int a, b, c;
  if (label[0][1] == label[1][2]) {
    a = 0, b = 1, c = 2;
  } else if (label[1][2] == label[2][0]) {
    a = 1, b = 2, c = 0;
  } else {
    a = 2, b = 0, c = 1;
  }

  cout << "YES\n";
  for (int i = 0; i <= m; ++i) {
    if (i % 2 == m / 2 % 2) {
      cout << b + 1 << " ";
    } else {
      cout << a + 1 << " ";
      swap(a, c);
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}