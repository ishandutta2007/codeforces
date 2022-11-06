#include <bits/stdc++.h>
using namespace std;

int k, a, b;

int main() {
  cin >> k >> a >> b;
  if (a < k && b < k) return cout << "-1\n", 0;
  int awin = a / k, al = a % k;
  int bwin = b / k, bl = b % k;
  if (al > (k - 1) * bwin) return cout << "-1\n", 0;
  if (bl > (k - 1) * awin) return cout << "-1\n", 0;
  cout << awin + bwin << '\n';
  return 0;
}