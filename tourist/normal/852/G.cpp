/**
 *    author:  tourist
 *    created: 03.09.2017 13:14:29       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  map <string, int> mp;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mp[s]++;
  }
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    vector <int> q;
    for (int j = 0; j < (int) s.length(); j++) {
      if (s[j] == '?') {
        q.push_back(j);
      }
    }
    set <string> was;
    int ans = 0;
    for (char a = 'a'; a <= 'f'; a++) {
      if (q.size() < 1 && a != 'f') {
        continue;
      }
      for (char b = 'a'; b <= 'f'; b++) {
        if (q.size() < 2 && b != 'f') {
          continue;
        }
        for (char c = 'a'; c <= 'f'; c++) {
          if (q.size() < 3 && c != 'f') {
            continue;
          }
          string st = s;
          if (q.size() >= 1) {
            st[q[0]] = a;
          }
          if (q.size() >= 2) {
            st[q[1]] = b;
          }
          if (q.size() >= 3) {
            st[q[2]] = c;
          }
          while (st.find('f') != string::npos) {
            st.erase(st.begin() + st.find('f'));
          }
          if (was.find(st) != was.end()) {
            continue;
          }
          if (mp.find(st) != mp.end()) {
            was.insert(st);
            ans += mp[st];
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}