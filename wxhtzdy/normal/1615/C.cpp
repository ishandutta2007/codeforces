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
    string s;
    cin >> s;
    string t;
    cin >> t;
    if (s == t) {
      cout << 0 << '\n';
      continue;
    }
    map<pair<int, int>, int> who;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        who[{s[i] - '0', t[i] - '0'}] = i;  
      }
    }
    int ans = 1e9;
    function<void(int)> Try = [&](int id) {
      string ns = s;
      for (int i = 0; i < n; i++) {
        if (i == id) {
          for (int j = 0; j < n; j++) {
            if (i == j) {
              continue;
            }
            ns[j] = (ns[j] == '0' ? '1' : '0');
          }
        }
      }
      int cnt_s = count(ns.begin(), ns.end(), '0');
      int cnt_t = count(t.begin(), t.end(), '0');
      if (cnt_s != cnt_t) {
        return;
      }
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (ns[i] != t[i]) {
          cnt += 1;
        }
      }      
      ans = min(ans, cnt + (id != -1));
    };
    Try(-1);                           
    for (auto x : who) {
      Try(x.second);
    }
    cout << (ans == 1e9 ? -1 : ans) << '\n';
  }                                                                    
  return 0;
}