#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);         
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> v;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == b[i]) continue;
      int k = -1;
      for (int j = i - 1; j >= 0; j--) {
        if (a[j] == b[i]) {
          k = j;
          break;
        }
      }
      if (k == -1) {
        v.push_back(i);
        for (int j = 0; j <= i; j++) {
          a[j] = (a[j] == '1' ? '0' : '1');  
        }
        continue;
      }
      for (int j = 0; j <= k; j++) {
        a[j] = (a[j] == '1' ? '0' : '1');  
      }
      reverse(a.begin(), a.begin() + k + 1);
      for (int j = 0; j <= i; j++) {
        a[j] = (a[j] == '1' ? '0' : '1');  
      }
      reverse(a.begin(), a.begin() + i + 1);
      v.push_back(k);
      v.push_back(i);   
    }
    cout << v.size() << " ";
    for (int c : v) cout << c + 1 << " ";
    cout << '\n'; 
  }
  return 0;
}