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
    vector<int> a(n);
    map<int, int> lst;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      lst[a[i]] = i;
    }
    int ptr = n - 1;
    while (ptr > 0 && a[ptr - 1] <= a[ptr]) {
      ptr -= 1;
    }
    int pos = ptr - 1;
    for (int i = 0; i <= pos; i++) {
      pos = max(pos, lst[a[i]]);
    }
    set<int> st;
    for (int i = 0; i <= pos; i++) {
      st.insert(a[i]);
    }
    cout << st.size() << '\n';
  }
  return 0;
}