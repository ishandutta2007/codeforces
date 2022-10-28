#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

int a[N];
int b[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, p;
  cin >> n >> p;

  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  
  if (accumulate(a, a + n, 0LL) <= p) {
    cout << -1 << "\n";
    exit(0);
  }

  double lo = 0.0;
  double hi = 1e14;

  for (int i = 0; i < 100; ++i) {
    double mid = (lo + hi) / 2;
    double balance = 0.0;
    for (int j = 0; j < n; ++j) {
      balance += max(0.0, a[j] * mid - b[j]);
    }
    (mid * p < balance ? hi : lo) = mid;
  }

  cout << fixed << setprecision(12) << lo << "\n";
}