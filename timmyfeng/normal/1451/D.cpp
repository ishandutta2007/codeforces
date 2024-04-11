#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long d, k;
    cin >> d >> k;

    long long x = 0;
    while (2 * x * x <= d * d) {
      x += k;
    }

    if (x * x + (x - k) * (x - k) <= d * d) {
      cout << "Ashish\n";
    } else {
      cout << "Utkarsh\n";
    }
  }
}