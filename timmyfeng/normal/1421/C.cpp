#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int n = s.size();

  cout << 3 << "\n";
  cout << "L " << n - 1 << "\n";
  cout << "R " << n - 1 << "\n";
  cout << "R " << 2 * n - 1 << "\n";
}