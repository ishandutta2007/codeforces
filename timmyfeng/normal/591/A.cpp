#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int l, p, q;
  cin >> l >> p >> q;

  cout << (double) l * p / (p + q) << "\n";
}