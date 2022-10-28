#include <bits/stdc++.h>
using namespace std;

const int N = 2000 + 1;

long long mini[2][N];
int a[2][N], n[2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n[0] >> n[1];

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n[i]; ++j) {
      cin >> a[i][j];
    }

    fill(mini[i] + 1, mini[i] + n[i] + 1, LLONG_MAX);
    for (int j = 0; j < n[i]; ++j) {
      long long sum = 0;
      for (int k = j; k < n[i]; ++k) {
        sum += a[i][k];
        mini[i][k - j + 1] = min(mini[i][k - j + 1], sum);
      }
    }
  }

  int ans = 0, x;
  cin >> x;
  for (int i = 1; i <= n[0]; ++i) {
    for (int j = 1; j <= n[1]; ++j) {
      if (mini[0][i] <= x / mini[1][j]) {
        ans = max(ans, i * j);
      }
    }
  }

  cout << ans << "\n";
}