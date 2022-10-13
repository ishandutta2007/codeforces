#include <iostream>
#include <vector>

using namespace std;

int main() {
   int t; cin >> t;
   while (t--) {
      int n; cin >> n;
      cout << 2 << "\n";
      for (int i = 1; i <= n; i += 2) {
         for (int j = 0; i * (1 << j) <= n; j++) {
            cout << i * (1 << j) << " ";
         }
      }
      cout << "\n";
   }
}