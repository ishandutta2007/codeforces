#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n, x, y;
  cin >> n >> x >> y;
  cout << (max(x - 1, y - 1) <= max(n - x, n - y) ? "White" : "Black") << "\n";
}