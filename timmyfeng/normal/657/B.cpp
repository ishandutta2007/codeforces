#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;

bool prefix_ok[N], suffix_ok[N];
long long prefix[N], suffix[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i <= n; ++i) {
    cin >> a[i];
  }

  prefix_ok[0] = true;
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = (prefix[i] + a[i]) / 2;
    prefix_ok[i + 1] = (prefix_ok[i] && (prefix[i] + a[i]) % 2 == 0);
  }

  suffix_ok[n] = true;
  for (int i = n; i > 0; --i) {
    suffix[i - 1] = 2 * (suffix[i] + a[i]);
    suffix_ok[i - 1] = (suffix_ok[i] && abs(suffix[i - 1]) < (1LL << 60));
  }

  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (prefix_ok[i] && suffix_ok[i]) {
      long long value = prefix[i] + suffix[i];
      ans += (abs(value) <= k && (value != 0 || i < n));
    }
  }

  cout << ans << "\n";
}