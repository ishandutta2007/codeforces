#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int qq;
  cin >> qq;
  vector<int> st;
  int ans = 0, ok = 0, speed = 0;
  while (qq--) {
    int foo;
    cin >> foo;
    if (foo == 1) {
      cin >> speed;
      while (st.size() > 0 && st.back() < speed) {
        ans++;
        st.pop_back();
      }
    } else if (foo == 2) {
      ans += ok;
      ok = 0;
    } else if (foo == 3) {
      int x;
      cin >> x;
      if (x < speed) ans++;
      else st.push_back(x);
    } else if (foo == 4) {
      ok = 0;
    } else if (foo == 5) {
      st.clear();
    } else if (foo == 6) {
      ok++;
    }
  }
  cout << ans << '\n';
  return 0;
}