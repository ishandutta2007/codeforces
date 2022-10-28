#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 1;

int a[N], ans[N], freq[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    int d = 0;
    fill(freq, freq + n + 1, 0);
    for (int j = i; j < n; ++j) {
      ++freq[a[j]];
      if (freq[a[j]] > freq[d] || (freq[a[j]] == freq[d] && a[j] < d)) {
        d = a[j];
      }
      ++ans[d];
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}