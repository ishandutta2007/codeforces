#include <bits/stdc++.h>

using namespace std;

#define ide_gas_na INT_MAX

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> kaunt(10);
  for (char c : s)
    kaunt[c - '0']++;
  cout << min(n / 11, kaunt[8]) << '\n';
  return 0;
}