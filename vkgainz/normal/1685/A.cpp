#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool work(int a, int b, int c) {
   return (b > a && b > c) || (b < a && b < c);
}
int main() {
   int t; cin >> t;
   while (t--) {
      int n; cin >> n;
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
         cin >> a[i];
      }
      if (n % 2) {
         cout << "NO" << "\n";
         continue;
      }
      sort(a.begin(), a.end());
      vector<int> b(n);
      for (int i = 0; i < n / 2; i++) {
         b[2 * i] = a[i];
         b[2 * i + 1] = a[i + n / 2];
      }
      bool res = true;
      for (int i = 0; i < n; i++) {
         res &= work(b[(i + n - 1) % n], b[i], b[(i + 1) % n]);
      }
      if (res) {
         cout << "YES" << "\n";
         for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
         }
         cout << "\n";
      }
      else cout << "NO" << "\n";
   }
}