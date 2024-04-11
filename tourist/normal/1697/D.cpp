/**
 *    author:  tourist
 *    created: 12.06.2022 18:44:37       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto Ask = [&](int l, int r) {
    cout << "? 2" << " " << l + 1 << " " << r + 1 << endl;
    int x;
    cin >> x;
    return x;
  };
  auto AskOne = [&](int x) {
    cout << "? 1" << " " << x + 1 << endl;
    char foo;
    cin >> foo;
    return foo;
  };
  string s = "";
  vector<int> b;
  for (int i = 0; i < n; i++) {
    sort(b.begin(), b.end());
    int low = -1;
    int high = (int) b.size() - 1;
    while (low < high) {
      int mid = (low + high + 1) >> 1;
      if (Ask(b[mid], i) == (int) b.size() - mid) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    if (low == -1) {
      s += AskOne(i);
      b.push_back(i);
    } else {
      s += s[b[low]];
      b[low] = i;
    }
  }
  cout << "! " << s << endl;
  return 0;
}