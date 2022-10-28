#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 2;

int taxi[N];
int ans[N];
int x[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  n += m;

  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  for (int i = 0, j = 0; i < n; ++i) {
    bool t;
    cin >> t;
    if (t) {
      taxi[j] = x[i];
      ++j;
    }
  }

  int ptr = 0;
  for (int i = 0; i < n; ++i) {
    if (ptr + 1 < m && abs(taxi[ptr + 1] - x[i]) < abs(taxi[ptr] - x[i])) {
      ++ptr;
    }
    ++ans[ptr];
  }

  for (int i = 0; i < m; ++i) {
    cout << ans[i] - 1 << " ";
  }
  cout << "\n";
}