/**
 *    author:  wxhtzdy
 *    created: 01.08.2022 16:40:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int s;
    cin >> s;
    vector<int> a;
    int t = 0;
    for (int i = 9; i >= 1; i--) {
      if (t < s) {
        a.push_back(i);
        t += i;
      }
    }
    reverse(a.begin(), a.end());
    int prv = 0;
    for (int i = 0; i < (int) a.size(); i++) {
      while (a[i] - 1 > prv && t - 1 >= s) {
        a[i] -= 1; 
        t -= 1;
      }
      prv = a[i];
    }
    for (int i = 0; i < (int) a.size(); i++) {
      cout << a[i];
    }
    cout << '\n';
  }                                                                    
  return 0;
}