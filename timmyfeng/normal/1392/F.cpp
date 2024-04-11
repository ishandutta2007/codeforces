#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

long long h[N];
long long ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    sum += h[i];
  }

  long long base = 1LL * (n - 1) * (n - 2) / 2;
  long long offset = (sum - base) / n;
  ans[0] = offset + (sum - base) % n;
  iota(ans + 1, ans + n, offset);
  sort(ans, ans + n);

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}