#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  auto Check = [&](long long x) {
    long long c = 0;
    long long p = 1;
    for (int i = 0; i < 100; i++) {
      if (x / p == 0) {
        return c >= n;
      }
      c += (x / p);
      p *= k;
    }
  };
  long long low = 0, high = 1e15;
  while (low <= high) {
    long long mid = low + high >> 1;
    if (Check(mid)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << high + 1 << '\n';
  return 0;
}