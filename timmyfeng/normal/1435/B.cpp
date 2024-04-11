#include <bits/stdc++.h>
using namespace std;

const int N = 250000 + 1;

vector<int> row[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    fill(row, row + n * m + 1, vector<int>());

    for (int i = 0; i < n; ++i) {
      vector<int> a(m);
      for (auto& i : a) {
        cin >> i;
      }
      row[a[0]] = a;
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int a;
        cin >> a;
        if (!row[a].empty()) {
          for (auto j : row[a]) {
            cout << j << " ";
          }
          cout << "\n";
        }
      }
    }
  }
}