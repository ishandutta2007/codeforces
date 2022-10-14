#include <bits/stdc++.h>
 
using namespace std;
 
 
const int N = 1e4 + 5;
 
int p[N];
 
int Ask1(int i, int j, int x) {
  cout << "? " << 1 << " " << i + 1 << " " << j + 1 << " " << x << endl;
  //int val = max(min(x, p[i]), min(x + 1, p[j]));
  int val = 0;
  cin >> val;
  return val;
}
 
int Ask2(int i, int j, int x) {
  cout << "? " << 2 << " " << i + 1 << " " << j + 1 << " " << x << endl;
  //int val = min(max(x, p[i]), max(x + 1, p[j]));
  int val = 0;
  cin >> val;
  return val;
}
 
void run_case() {
  int n;
  cin >> n;
  //for (int i = 0; i < n; i++) cin >> p[i];
  int x = Ask1(0, 1, n - 1); // max(min(n - 1, p[0]), p[1])
  int y = Ask1(1, 0, n - 1); // max(min(n - 1, p[1]), p[0])
  int x1 = Ask1(0, 2, n - 1);
  int y1 = Ask1(2, 0, n - 1);
  int x2 = Ask1(1, 2, n - 1);
  int y2 = Ask1(2, 1, n - 1);
  vector<int> ans(n);
  // p[0] <= n - 1 && p[1] <= n - 1
  // max(p[0], p[1])
  // max(p[1], p[0])
  if (x <= n - 1 && y <= n - 1) {
    // max(p[0], p[2]) = x1
    // max(p[1], p[2]) = y1
    if (x1 == n) {
      ans[2] = n;
    } else {
      if (x == x1) {
        ans[0] = x;
      } else {
        if (y == y2) {
          ans[1] = y;
        } else {
          ans[2] = x1;
        }
      }
    }
  } else {
    if (x == n) {
      assert(y < n);
      ans[1] = n;
    } else {
      assert(x < n);
      ans[0] = n;
    }
  }
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (ans[i] != 0) {
      j = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (j == i) {
      continue;
    }
    if (ans[j] == n) {
      int l = Ask2(i, j, 1);
      ans[i] = l;
    } else {
      if (ans[j] <= n / 2) {
        int l = Ask1(j, i, n - 1);
        if (l != ans[j]) {
          ans[i] = l;
        } else {
          l = Ask2(i, j, 1);
          ans[i] = l;
        }
      } else {
        int l = Ask2(i, j, 1);
        if (l != ans[j]) {
          ans[i] = l;
        } else {
          l = Ask1(j, i, n - 1);
          ans[i] = l;
        }
      }
    }
  }
  cout << "! ";
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    run_case();
  }
  return 0;
}