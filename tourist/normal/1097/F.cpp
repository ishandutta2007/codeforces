/**
 *    author:  tourist
 *    created: 04.01.2019 18:06:12       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = 7070;
  vector<int> sqfree(MAX, 1);
  for (int i = 1; i < MAX; i++) {
    for (int j = 2; j * j <= i; j++) {
      if (i % (j * j) == 0) {
        sqfree[i] = 0;
        break;
      }
    }
  }
  vector<bitset<MAX>> divs(MAX);
  vector<bitset<MAX>> muls(MAX);
  for (int i = 1; i < MAX; i++) {
    for (int j = 1; j <= i; j++) {
      if (i % j == 0) {
        divs[i].set(j);
        if (sqfree[i / j]) {
          muls[j].set(i);
        }
      }
    }
  }
  int n, tt;
  cin >> n >> tt;
  vector<bitset<MAX>> a(n);
  while (tt--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, v;
      cin >> x >> v;
      x--;
      a[x] = divs[v];
    }
    if (op == 2) {
      int x, y, z;
      cin >> x >> y >> z;
      x--; y--; z--;
      a[x] = a[y] ^ a[z];
    }
    if (op == 3) {
      int x, y, z;
      cin >> x >> y >> z;
      x--; y--; z--;
      a[x] = a[y] & a[z];
    }
    if (op == 4) {
      int x, v;
      cin >> x >> v;
      x--;
      cout << (a[x] & muls[v]).count() % 2;
    }
/*    for (int i = 0; i < n; i++) {
      cout << i << ":";
      for (int j = 0; j < MAX; j++)
        if (a[i][j] == 1) cout << " " << j;
      cout << "; ";
    }
    cout << '\n';*/
  }
  cout << '\n';
  return 0;
}