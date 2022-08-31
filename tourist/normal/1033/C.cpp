/**
 *    author:  tourist
 *    created: 07.10.2018 20:09:43       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), pos(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    pos[a[i]] = i;
  }
  string win(n, '?');
  for (int x = n - 1; x >= 0; x--) {
    int i = pos[x];
    win[i] = 'B';
    int j = i;
    while (true) {
      j -= (x + 1);
      if (j < 0) {
        break;
      }
      if (win[j] == 'B') {
        win[i] = 'A';
        break;
      }
    }
    j = i;
    while (true) {
      j += (x + 1);
      if (j >= n) {
        break;
      }
      if (win[j] == 'B') {
        win[i] = 'A';
        break;
      }
    }
  }
  cout << win << '\n';
  return 0;
}