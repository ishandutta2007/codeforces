#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin >> k;
  cout << 3 << " " << 4 << "\n";
  cout << (1 << 18) - 1 << " " << k << " " << k << " " << 0 << "\n";
  cout << (1 << 17) << " " << 0 << " " << k << " " << 0 << "\n";
  cout << (1 << 17) << " " << (1 << 17) << " " << (1 << 18) - 1 << " " << k << "\n";
}