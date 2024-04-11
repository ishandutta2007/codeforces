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
    vector<int> a(n);
    bool turn = (n % 2 == 1 ? 0 : 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > 1) {
        turn = (i % 2 == 0 ? 0 : 1);
        break; 
      }
    }
    if (!turn) cout << "First" << '\n';
    else cout << "Second" << '\n';
  }
  return 0;
}