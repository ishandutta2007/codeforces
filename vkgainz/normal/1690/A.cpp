#include <iostream>

using namespace std;

int main() {
   int t; cin >> t;
   while (t--) {
      int n; cin >> n;
      for (int i = 3; i <= n; i++) {
         bool work = false;
         if (i + (i - 1) + (i - 2) >= n
            && i + 1 + 2 <= n && (n - (2 * i - 1)) < (i - 1)) {
               work = true;
            }
         if (work) {
            if (n - (2 * i - 1) == 0) {
               cout << i - 2 << " " << i << " " << n - (2 * i - 2) << "\n";
            } else {
               cout << i - 1 << " " << i << " " << n - (2 * i - 1) << "\n";
            }
            break;
         }
      }
   }
}