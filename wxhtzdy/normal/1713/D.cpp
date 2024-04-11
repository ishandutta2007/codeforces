/**
 *    author:  wxhtzdy
 *    created: 24.08.2022 16:03:30
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
    n = (1 << n);               
    vector<int> a;        
    for (int i = 1; i <= n; i++) {
      a.push_back(i);
    }      
    auto Ask = [&](int i, int j) {
      cout << "? " << i << " " << j << endl;
      int x;
      cin >> x;
      return x; 
    };
    while (a.size() > 1) {
      if (a.size() < 4) {
        int win = a[0];
        for (int i = 1; i < a.size(); i++) {
          if (Ask(win, a[i]) == 2) {
            win = a[i];
          }
        }
        a = {win};
        break;
      }
      vector<int> b;
      for (int i = 0; i < (int) a.size(); i += 4) {
        if (i + 1 == (int) a.size()) {
          b.push_back(Ask(a[i], a[i + 1]) == 1 ? a[i] : a[i + 1]);
          continue;
        }
        int x = Ask(a[i], a[i + 2]);
        if (x == 0) {
          b.push_back(Ask(a[i + 1], a[i + 3]) == 1 ? a[i + 1] : a[i + 3]);          
        } else if (x == 1) {
          b.push_back(Ask(a[i], a[i + 3]) == 1 ? a[i] : a[i + 3]);
        } else {
          b.push_back(Ask(a[i + 1], a[i + 2]) == 1 ? a[i + 1] : a[i + 2]);
        }
      }
      swap(a, b);
    }       
    cout << "! " << a[0] << endl;;
  }                                                                    
  return 0;
}