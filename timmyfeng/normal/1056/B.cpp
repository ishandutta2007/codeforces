#include <bits/stdc++.h>
using namespace std;

const int M = 1'000;

int mod_i[M];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int count_i = n / m + (n % m >= i) - (i == 0);
    mod_i[i * i % m] += count_i;
  }

  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    ans += (long long) mod_i[i] * mod_i[(m - i) % m];
  }

  cout << ans << "\n";
}