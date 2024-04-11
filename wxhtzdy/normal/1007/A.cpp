#include <bits/stdc++.h>
 
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> was;      
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    was[a[i]]++;
    mx = max(mx, was[a[i]]);
  }                        
  cout << n - mx << '\n';
  return 0;        
}