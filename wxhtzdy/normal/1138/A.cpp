#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int ptr = i;
    while (ptr + 1 < n && t[ptr + 1] == t[ptr]) {
      ptr += 1;
    }
    a.push_back(ptr - i + 1);
    i = ptr;
  }
  int ans = 0;
  for (int i = 0; i + 1 < (int) a.size(); i++) {
    ans = max(ans, min(a[i], a[i + 1]) * 2); 
  }
  cout << ans << '\n';              
  return 0;
}