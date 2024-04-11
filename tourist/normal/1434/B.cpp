/**
 *    author:  tourist
 *    created: 25.10.2020 14:11:57       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> op(2 * n);
  vector<int> st;
  for (int i = 0; i < 2 * n; i++) {
    string s;
    cin >> s;
    if (s == "+") {
      st.push_back(i);
    } else {
      if (st.empty()) {
        cout << "NO" << '\n';
        return 0;
      }
      cin >> op[i];
      op[st.back()] = -op[i];
      st.pop_back();
    }
  }
  set<int> s;
  for (int i = 0; i < 2 * n; i++) {
    if (op[i] < 0) {
      s.insert(-op[i]);
    } else {
      if (s.empty() || *s.begin() != op[i]) {
        cout << "NO" << '\n';
        return 0;
      }
      s.erase(s.begin());
    }
  }
  cout << "YES" << '\n';
  for (int i = 0; i < 2 * n; i++) {
    if (op[i] < 0) {
      cout << -op[i] << " ";
    }
  }
  cout << '\n';
  return 0;
}