#include <bits/stdc++.h>
using namespace std;

int n, a[100];

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (n == 1 && a[0] == 0) return cout << "UP\n", 0;
  if (n == 1 && a[0] == 15) return cout << "DOWN\n", 0;
  if (n == 1) return cout << "-1\n", 0;
  if (a[n - 1] > a[n - 2] && a[n - 1] != 15) return cout << "UP\n", 0;
  if (a[n - 1] < a[n - 2] && a[n - 1] != 0) return cout << "DOWN\n", 0;
  if (a[n - 1] > a[n - 2] && a[n - 1] == 15) return cout << "DOWN\n", 0;
  if (a[n - 1] < a[n - 2] && a[n - 1] == 0) return cout << "UP\n", 0;
  cout << "-1\n";
  return 0;
}