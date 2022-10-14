/**
 *  author: milos
 *  created: 08.01.2021 12:12:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }                     
  auto Can = [&](int x) {
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      b[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        int diff = m - a[i];
        if (x >= diff) {
          b[i] = 0;
        }
      } else {
        int diff = m - b[i];
        if ((b[i - 1] + diff) <= x) {
          b[i] = b[i - 1];
        } else {               
          //cout << b[i] << " " << diff << " " << b[i - 1] << '\n';
          if ((b[i] + x) < b[i - 1]) {
            return false;   
          } else {
            b[i] = max(b[i], b[i - 1]);
          }
        }
      }
    }
    for (int i = 1; i < n; i++) {
      if (b[i] < b[i - 1]) {
        return false;
      }
    }
    return true;    
  };
  int bot = 0, top = m, ans = m;   
  while (bot <= top) {
    int mid = bot + top >> 1;
    if (Can(mid) == true) {
      ans = mid;
      top = mid - 1;
    } else {
      bot = mid + 1;
    }
  }
  assert(Can(ans));  
  cout << ans << '\n';  
  return 0;
}