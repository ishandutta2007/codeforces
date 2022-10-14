/**
 *    author:  wxhtzdy
 *    created: 12.09.2022 16:46:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = (int) (s[i] - 'a');     
    }  
    if (a[0] <= a[n - 1]) {
      vector<int> pos;
      for (int i = 0; i < n; i++) {
        if (a[i] >= a[0] && a[i] <= a[n - 1]) {
          pos.push_back(i);
        }
      }                               
      sort(pos.begin(), pos.end(), [&](int i, int j) {
        if (a[i] == a[j]) {
          return i < j; 
        } else {
          return a[i] < a[j];
        }
      });  
      cout << a[n - 1] - a[0] << " " << (int) pos.size() << '\n';
      for (int i = 0; i < (int) pos.size(); i++) {
        cout << pos[i] + 1 << " "; 
      }
      cout << '\n';
    } else {
      vector<int> pos;
      for (int i = 0; i < n; i++) {
        if (a[i] >= a[n - 1] && a[i] <= a[0]) {
          pos.push_back(i);
        }
      }                               
      sort(pos.begin(), pos.end(), [&](int i, int j) {
        if (a[i] == a[j]) {
          return i < j; 
        } else {
          return a[i] > a[j];
        }
      });  
      cout << a[0] - a[n - 1] << " " << (int) pos.size() << '\n';
      for (int i = 0; i < (int) pos.size(); i++) {
        cout << pos[i] + 1 << " "; 
      }
      cout << '\n';
    }
  }                                                                    
  return 0;
}