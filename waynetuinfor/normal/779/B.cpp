#include <bits/stdc++.h>
using namespace std;

int k, z, rm;
string n;

int main() {
  cin >> n >> k;
  for (int i = n.length() - 1; i >= 0; --i) {
    if (z == k) break;
    if (n[i] == '0') ++z;
    else ++rm;
  }
  if (z < k) return cout << n.length() - 1 << '\n', 0;
  cout << rm << '\n';
  return 0;
}