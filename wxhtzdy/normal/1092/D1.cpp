/**
 *    author:  milos
 *    created: 23.01.2021 21:03:13       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b;
  for (int i = 0; i < n; i++) {
    if ((int) b.size() > 0 && a[i] % 2 == b.back()) {
      b.pop_back();  
    } else {
      b.push_back(a[i] % 2);
    }
  }
  cout << ((int) b.size() < 2 ? "YES" : "NO") << '\n';
  return 0;
}