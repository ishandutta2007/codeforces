//

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, t, k;
ll a[55555], b[55555];

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> k;
    if (n <= 4 && k == n-1) {
      cout << -1 << "\n";
      continue;
    }
    for (int i = 0; i < n / 2; i++) {
      a[i] = i;
      b[i] = n - i - 1;
    }
    if (k > 0) {
      if (k < n / 2) {
        std::swap(a[0], a[k]);
      } else
      if (k < n - 1) {
        std::swap(a[0], b[n-1-k]);
      } else {
        std::swap(a[0], a[n/2-1]);
        std::swap(b[n/2-1], a[n/2-2]);
      }
    }
    for (int i = 0; i < n / 2; i++) {
      cout << a[i] << " " << b[i] << "\n";
    }
  }
  return 0;
}