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
  }
  function<long long(int, int, int)> Solve = [&](int l, int r, int lst) {
    int mn = 1e9;
    for (int i = l; i <= r; i++) {
      mn = min(mn, a[i]);
    }
    vector<int> ids;
    for (int i = l; i <= r; i++) {
      if (a[i] > mn) {
        ids.push_back(i);
      }
    }
    long long tot = mn - lst;
    for (int i = 0; i < ids.size(); i++) {
      int ptr = i;
      while (ptr + 1 < ids.size() && ids[ptr + 1] == ids[ptr] + 1) {
        ptr += 1;
      }
      tot += Solve(ids[i], ids[ptr], mn);
      i = ptr;
    }                              
    return min(tot, (long long) (r - l + 1));
  };
  cout << Solve(0, n - 1, 0) << '\n';                                                       
  return 0;
}