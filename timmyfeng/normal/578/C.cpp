#include <bits/stdc++.h>
using namespace std;

const int L = 128;

array<double, 2> calc(vector<int> &a, double x) {
  double mini = 0.0, maxi = 0.0, sum = 0.0;
  int n = a.size();

  for (int j = 0; j < n; ++j) {
    sum = a[j] + x + min(sum, 0.0);
    mini = min(mini, sum);
  }

  sum = 0.0;
  for (int j = 0; j < n; ++j) {
    sum = a[j] + x + max(sum, 0.0);
    maxi = max(maxi, sum);
  }

  return {mini, maxi};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  double l = -10000.0, r = 10000.0;
  for (int i = 0; i < L; ++i) {
    double x = (l + r) / 2;
    auto [mini, maxi] = calc(a, x);
    (-mini < maxi ? r : l) = x;
  }

  auto [mini, maxi] = calc(a, l);
  cout << max(-mini, maxi) << "\n";
}