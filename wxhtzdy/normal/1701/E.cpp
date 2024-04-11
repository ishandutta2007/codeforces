/**
 *    author:  wxhtzdy
 *    created: 13.07.2022 20:05:15
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<int> z_function(int n, const T &s) {
  vector<int> z(n, n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    z[i] = (i > r ? 0 : min(r - i + 1, z[i - l]));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}
template <typename T>
vector<int> z_function(const T &s) {
  return z_function((int) s.size(), s);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int ptr = 0;
    int ans = n;
    for (int i = 0; i < n; i++) {
      if (ptr < m && s[i] == t[ptr]) {
        ptr += 1;
      }    
      if (i + 1 == ptr) {
        ans -= 1;
      }
    }
    if (ptr < m) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> at(n);
    ptr = m - 1;
    for (int i = n - 1; i >= 0; i--) {
      if (ptr >= 0 && s[i] == t[ptr]) {
        ptr -= 1;
      }
      at[i] = ptr;
    }     
    ptr = 0;
    string rt = t;
    reverse(rt.begin(), rt.end());
    {
      string str = s;
      reverse(str.begin(), str.end());
      str = str + '#' + rt;
      auto z = z_function(str);
      int save = z[n + 1];
      ans = min(ans, 1 + 2 * (n - save) - (m - save));
    }                             
    for (int i = 0; i < n - 1; i++) {
      if (ptr < m && s[i] == t[ptr]) {
        ptr += 1;
      }
      int pos = at[i + 1];
      string str = s.substr(0, i + 1);
      reverse(str.begin(), str.end());
      str = str + '#' + rt;
      auto z = z_function(str); 
      for (int j = 1; j <= m; j++) {
        if (j > ptr) {
          break;
        }
        if (j < pos + 1) {
          continue;
        }
        int save = z[i + + 2 + m - j];
        ans = min(ans, n - i - 1 + 2 * (i + 1 - save) - (j - save) + 1);
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}