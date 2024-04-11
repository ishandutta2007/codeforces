#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n, k;
  cin >> n >> k;

  long long l = max(1LL, k - n);
  long long r = min(n - 1, (k - 1) / 2);

  cout << max(0LL, r - l + 1) << "\n";
}