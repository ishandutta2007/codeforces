#include <bits/stdc++.h>
using namespace std;

const int L = 60;

long long basis[L];

bool update(long long x) {
  for (int i = 0; i < 60; ++i) {
    if ((x & (1LL << i)) > 0) {
      if (basis[i] > 0) {
        x ^= basis[i];
      } else {
        basis[i] = x;
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  long long sum = 0, ans = 1;
  for (int i = 0; i < n; ++i) {
    long long a, b;
    cin >> a >> b;
    sum ^= a;
    if (update(a ^ b)) {
      ans *= 2;
    }
  }

  if (update(sum)) {
    cout << 1 << "/" << 1 << "\n";
  } else {
    cout << ans - 1 << "/" << ans << "\n";
  }
}