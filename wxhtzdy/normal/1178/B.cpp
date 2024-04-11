#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  string s;
  cin >> s;
  int n = (int) s.length();
  vector<long long> l(n, 0);
  for (int i = 1; i < n; i++) {
    l[i] = l[i - 1];
    if (s[i] == s[i - 1] && s[i] == 'v') {
      l[i]++;
    }
  }
  vector<long long> r(n, 0);
  for (int i = n - 2; i >= 0; i--) {
    r[i] = r[i + 1];
    if (s[i] == s[i + 1] && s[i] == 'v') {
      r[i]++;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o') {
      ans += (long long) l[i] * r[i];
    }
  }
  cout << ans << '\n';
  return 0;
}