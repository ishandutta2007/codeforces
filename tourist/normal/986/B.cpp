/**
 *    author:  tourist
 *    created: 29.05.2018 18:40:07       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  vector<int> was(n, 0);
  int cyc = 0;
  for (int i = 0; i < n; i++) {
    if (was[i]) {
      continue;
    }
    cyc++;
    int p = i;
    while (!was[p]) {
      was[p] = 1;
      p = a[p];
    }
  }
  cout << ((n - cyc) % 2 == (3 * n) % 2 ? "Petr" : "Um_nik") << '\n';
  return 0;
}