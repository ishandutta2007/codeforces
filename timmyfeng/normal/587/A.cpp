#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;

int weights[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int w;
    cin >> w;
    ++weights[w];
  }

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ans += weights[i] % 2;
    if (weights[i] > 0) {
      weights[i + 1] += weights[i] / 2;
    }
  }

  cout << ans << "\n";
}