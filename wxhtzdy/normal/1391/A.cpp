/**
 *    author:  milos
 *    created: 11.08.2020 10:45:57      
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
    for (int i = 0; i < n; i++) {
      cout << i + 1 << " ";
    }
    cout << '\n';
  }    
  return 0;   
}