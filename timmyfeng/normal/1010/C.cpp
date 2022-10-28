#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  int g = k;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    g = __gcd(g, a);
  }

  cout << k / g << "\n";
  for (int i = 0; i < k; i += g) {
    cout << i << " ";
  }
  cout << "\n";
}