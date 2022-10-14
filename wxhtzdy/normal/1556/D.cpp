/**
 *    author:  milos
 *    created: 28.08.2021 22:21:52       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    //cin >> b[i];
  }
  auto And = [&](int i, int j) {
    cout << "and " << i << " " << j << endl;
    int x = b[i - 1] & b[j - 1];
    cin >> x;
    return x;  
  };
  auto Or = [&](int i, int j) {
    cout << "or " << i << " " << j << endl;
    int x = b[i - 1] | b[j - 1];
    cin >> x;
    return x;  
  };
  int x12 = And(1, 2);   
  int x13 = And(1, 3); 
  int x23 = And(2, 3); 
  int y12 = Or(1, 2);
  int y13 = Or(1, 3); 
  int y23 = Or(2, 3); 
  vector<int> ans(n);
  ans[0] = x12;
  for (int i = 0; i < 31; i++) {
    if (!(y12 & (1 << i))) {
      continue;
    }
    if (x12 & (1 << i)) {
      continue;
    }
    if (x23 & (1 << i)) {
      continue;
    }
    if (!(y23 & (1 << i))) {
      ans[0] += (1 << i);
      continue;
    }
    if (y13 & (1 << i)) {
      ans[0] += (1 << i);
    }
  }
  //cout << ans[0] << '\n';
  for (int i = 0; i < 31; i++) {
    if (x12 & (1 << i)) {
      ans[1] += (1 << i);
      continue;  
    }    
    if (y12 & (1 << i)) {
      if (ans[0] & (1 << i)) {
        // do nothing 
      } else {
        ans[1] += (1 << i);
      }
    }
  }
  //cout << ans[1] << '\n'; 
  for (int i = 0; i < 31; i++) {
    if (x13 & (1 << i)) {
      ans[2] += (1 << i);
      continue;  
    }    
    if (y13 & (1 << i)) {
      if (ans[0] & (1 << i)) {
        // do nothing 
      } else {
        ans[2] += (1 << i);
      }
    }
  }
  //cout << ans[2] << '\n';  
  for (int i = 3; i < n; i++) {
    int xx = And(1, i + 1);
    int yy = Or(1, i + 1);    
    for (int j = 0; j < 31; j++) {
      if (xx & (1 << j)) {
        ans[i] += (1 << j);
        continue;
      }
      if (yy & (1 << j)) {
        if (ans[0] & (1 << j)) {
          // do nothing
        } else {
          ans[i] += (1 << j);
        }
      }
    }
    //cout << ans[i] << '\n'; 
  }
  sort(ans.begin(), ans.end());
  cout << "finish " << ans[k - 1] << endl;
  return 0;
}