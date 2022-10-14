#include <bits/stdc++.h>
                                
using namespace std;
 
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int sz = 1, res = 0;
    for (int i = 0; i < n; i++) {
      if (sz * a[i] >= x) {
        res++;
        sz = 1;
      } else {
        sz++;
      }
    }
    cout << res << endl;
  }
}