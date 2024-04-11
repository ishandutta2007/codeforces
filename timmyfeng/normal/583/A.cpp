#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);


  int n;
  cin >> n;

  set<int> rows, cols;
  for (int i = 1; i <= n * n; ++i) {
    int r, c;
    cin >> r >> c;
    if (rows.count(r) == 0 && cols.count(c) == 0) {
      rows.insert(r), cols.insert(c);
      cout << i << " ";
    }
  }
  cout << "\n";
}