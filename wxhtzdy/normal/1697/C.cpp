/**
 *    author:  wxhtzdy
 *    created: 13.06.2022 16:00:21
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
    string s, t;
    cin >> s >> t;     
    if (multiset<char>(s.begin(), s.end()) != multiset<char>(t.begin(), t.end())) {
      cout << "NO" << '\n';
      continue;
    }
    string ns = "";
    vector<int> pa;
    for (int i = 0; i < n; i++) {
      if (s[i] != 'b') {
        ns += s[i];
        pa.push_back(i);
      }
    }
    string nt = "";
    vector<int> pb;
    for (int i = 0; i < n; i++) {
      if (t[i] != 'b') {
        nt += t[i];
        pb.push_back(i);
      }
    }
    if (ns != nt) {
      cout << "NO" << '\n';
      continue;
    }          
    bool ok = true;
    for (int i = 0; i < (int) pa.size(); i++) {
      if (ns[i] == 'a') {
        if (pa[i] > pb[i]) {
          ok = false;
        }
      } else if (pa[i] < pb[i]) {
        ok = false;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}