/**
 *    author:  wxhtzdy
 *    created: 01.08.2022 16:42:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    string t;
    cin >> t;
    int k;
    cin >> k;
    map<string, int> have;
    for (int i = 0; i < k; i++) {
      string s;
      cin >> s;
      have[s] = i;
    }
    int n = (int) t.size();   
    int beg = -1;
    vector<pair<int, int>> seq;
    bool fail = false;            
    while (beg < n - 1) {
      int end = beg;
      pair<int, int> seg;     
      for (int j = max(0, beg - 10); j <= beg + 1; j++) {
        string str = "";
        for (int p = j; p < n; p++) {
          str += t[p];
          if (have.count(str)) {    
            if (end < p) {
              end = p;
              seg = {j, have[str]};
            }
          }
        }
      }
      if (end == beg) {
        fail = true;
        break;
      }
      seq.push_back(seg);               
      beg = end;
    }  
    if (fail) {
      cout << -1 << '\n';
    } else {
      cout << (int) seq.size() << '\n';
      for (int i = 0; i < (int) seq.size(); i++) {
        cout << seq[i].second + 1 << " " << seq[i].first + 1 << '\n';
      }
    }
  }  
  return 0;
}