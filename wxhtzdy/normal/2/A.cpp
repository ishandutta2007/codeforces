#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> a(n);
  vector<string> s(n);
  map<string, int> m;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> a[i]; 
    m[s[i]] += a[i];
  }
  for (int i = 0; i < n; i++) {
    mx = max(mx, m[s[i]]);
  }
  map<string, int> k;
  for (int i = 0; i < n; i++) {
    k[s[i]] += a[i];
    if (k[s[i]] >= mx && m[s[i]] == mx) {
      cout << s[i] << '\n';
      return 0;
    }
  }
  return 0;
}