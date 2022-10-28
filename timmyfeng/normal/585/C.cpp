#include <bits/stdc++.h>
using namespace std;

void solve(long long x, long long y) {
  if (x == y) {
    return;
  } else if (x < y) {
    long long k = (y - 1) / x;
    cout << k << "B";
    solve(x, y - k * x);
  } else {
    long long k = (x - 1) / y;
    cout << k << "A";
    solve(x - k * y, y);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long x, y;
  cin >> x >> y;

  if (__gcd(x, y) != 1) {
    cout << "Impossible\n";
  } else {
    solve(x, y);
    cout << "\n";
  }
}