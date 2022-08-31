/**
 *    author:  tourist
 *    created: 28.02.2021 17:25:10       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    auto Ask = [&](vector<int> L, vector<int> R) {
      cout << "? " << L.size() << " " << R.size() << endl;
      for (int i = 0; i < (int) L.size(); i++) {
        if (i > 0) cout << " ";
        cout << L[i] + 1;
      }
      cout << endl;
      for (int i = 0; i < (int) R.size(); i++) {
        if (i > 0) cout << " ";
        cout << R[i] + 1;
      }
      cout << endl;
      int f;
      cin >> f;
      return f;
    };
    int any = n - 1;
    int ex = 0;
    while (true) {
      vector<int> L(1, any);
      vector<int> R;
      for (int j = 0; j < any; j++) {
        R.push_back(j);
      }
      int f = Ask(L, R);
      if (f != 0) {
        ex = f;
        break;
      }
      any -= 1;
    }
    vector<int> res;
    for (int i = any - 1; i >= 1; i--) {
      vector<int> L(1, any);
      vector<int> R(1, i);
      int f = Ask(L, R);
      if (f == 0) {
        res.push_back(i);
      } else {
        ex ^= f;
      }
    }
    if (!(ex & 1)) {
      res.push_back(0);
    }
    int low = any, high = n;
    while (low + 1 < high) {
      int mid = (low + high) >> 1;
      vector<int> L(1, any);
      vector<int> R;
      for (int i = any + 1; i <= mid; i++) {
        R.push_back(i);
      }
      int f = Ask(L, R);
      if (f != 0) {
        high = mid;
      } else {
        low = mid;
      }
    }
    for (int i = any + 1; i < n; i++) {
      if (i != high) {
        res.push_back(i);
      }
    }
    sort(res.begin(), res.end());
    cout << "! " << res.size();
    for (int x : res) {
      cout << " " << x + 1;
    }
    cout << endl;
  }
  return 0;
}