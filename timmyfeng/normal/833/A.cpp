#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;

    long long c = 1LL * a * b;
    long long lo = 0;
    long long hi = 1000000;
    while (lo <= hi) {
      long long mid = (lo + hi) / 2;
      if (mid * mid * mid < c) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    long long gcd = __gcd(a, b);
    if (lo * lo * lo != c || gcd % (a / gcd) != 0 || gcd % (b / gcd) != 0) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
}