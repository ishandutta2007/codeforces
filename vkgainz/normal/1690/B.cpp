#include <iostream>
#include <vector>

using namespace std;

int main() {
   int t; cin >> t;
   while (t--) {
      int n; cin >> n;
      vector<int> a(n), b(n);
      for (int i = 0; i < n; i++) {
         cin >> a[i];
      }
      int mx = 0;
      bool work = true;
      for (int i = 0; i < n; i++){
         cin >> b[i];
         if (a[i] < b[i]) work = false;
         mx = max(mx, a[i] - b[i]);
      }
      for (int i = 0; i < n; i++) {
         if (max(0, a[i] - mx) != b[i]) {
            work = false;
         }
      }
      if (work) cout << "YES" << "\n";
      else cout << "NO" << "\n";
   }
}