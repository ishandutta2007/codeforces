/**
 *    author:  tourist
 *    created: 02.02.2020 18:33:41       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  auto Ask = [&](int x) {
    cout << "? " << x + 1 << endl;
    string foo;
    cin >> foo;
    return (foo[0] == 'Y');
  };
  auto DoR = [&]() {
    cout << "R" << endl;
  };
  int b = max(k / 2, 1);
  int cnt = n / b;
  vector<int> dup(n, 0);
  vector<vector<int>> asked(cnt, vector<int>(cnt, 0));
  for (int i = 0; i < cnt; i++) {
    for (int j = i + 1; j < cnt; j++) {
      if (!asked[i][j]) {       
        int x = i, y = j;
        for (int t = 0; t < b; t++) {
          if (Ask(x * b + t)) {
            dup[x * b + t] = 1;
          }
        }
        while (true) {
          for (int t = 0; t < b; t++) {
            if (Ask(y * b + t)) {
              dup[y * b + t] = 1;
            }
          }
          asked[x][y] = 1;
          int z = y + 1;
          while (z < cnt && asked[y][z]) {
            ++z;
          }
          if (z == cnt) {
            break;
          }
          x = y;
          y = z;
        }
        DoR();
      }
    }
  }
  cout << "! " << n - accumulate(dup.begin(), dup.end(), 0) << '\n';
  return 0;
}