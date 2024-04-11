#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  k = (1 << k) - 1;

  map<int, int> freq;
  int sum = 0;
  ++freq[sum];

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    sum ^= a;
    ++freq[min(sum, sum ^ k)];
  }

  long long ans = (long long) n * (n + 1) / 2;
  for (auto [a, b] : freq) {
    long long c = b / 2, d = (b + 1) / 2;
    ans -= c * (c - 1) / 2;
    ans -= d * (d - 1) / 2;
  }

  cout << ans << "\n";
}