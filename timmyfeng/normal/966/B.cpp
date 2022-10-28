#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x1, x2;
  cin >> n >> x1 >> x2;

  vector<array<int, 2>> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i][0];
    c[i][1] = i + 1;
  }
  sort(c.begin(), c.end());

  for (int k = 0; k < 2; ++k) {
    int left = 0;
    int right = n;
    for (int i = 0; i < n; ++i) {
      int used = i + (x1 - 1) / c[i][0] + 1;
      if (used < right) {
        left = i;
        right = used;
      }
    }
    
    for (int i = right; i < n; ++i) {
      int cnt = (x2 - 1) / c[i][0] + 1;
      if (i + cnt - 1 < n) {
        cout << "Yes\n";
        if (k == 0) {
          cout << right - left << " " << cnt << "\n";
          for (int j = left; j < right; ++j) {
            cout << c[j][1] << " ";
          }
          cout << "\n";
          for (int j = 0; j < cnt; ++j) {
            cout << c[i + j][1] << " ";
          } 
          cout << "\n";
        } else {
          cout << cnt << " " << right - left << "\n";
          for (int j = 0; j < cnt; ++j) {
            cout << c[i + j][1] << " ";
          } 
          cout << "\n";
          for (int j = left; j < right; ++j) {
            cout << c[j][1] << " ";
          }
          cout << "\n";
        }
        exit(0);
      }
    }
    swap(x1, x2);
  }
  cout << "No\n";
}