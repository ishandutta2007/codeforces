#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    a[i] = abs(a[i + 1] - a[i]);
  }

  long long ans = 0;
  long long plus = 0;
  long long minus = 0;
  for (int i = n - 2; i >= 0; --i) {
    long long plus_new = max((long long) -a[i], minus - a[i]);
    long long minus_new = max((long long) a[i], plus + a[i]);
    plus = plus_new;
    minus = minus_new;
    ans = max(ans, minus);
  }

  cout << ans << "\n";
}