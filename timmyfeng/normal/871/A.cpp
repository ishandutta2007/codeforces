#include <bits/stdc++.h>
using namespace std;

const int S[] = {-1, -1, -1, -1, 1, -1, 1, -1, 2, 1, 2, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n <= 11) {
      cout << S[n] << "\n";
    } else {
      cout << (n - 12) / 4 + 3 - n % 2 << "\n";
    }
  }
}