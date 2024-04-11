#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
   int t; cin >> t;
   while (t--) {
      int n, k; cin >> n >> k;
      vector<int> a(n);
      long long sum = 0;
      int sum2 = 0;
      for (int i = 0; i < n; i++) {
         cin >> a[i];
         sum += a[i] / k;
         a[i] = a[i] % k;
      }
      sort(a.begin(), a.end());
      //max sum of (a[i] + a[j] / k) over pairs
      //= (a[i] + a[j]) 0 or (a[i] + a[j] - k) 1
      //want to maximize number - k
      int j = 0;
      for (int i = n - 1; i >= 0; i--) {
         while (j < n && a[i] + a[j] < k) {
            ++j;
         }
         if (j >= i) break;
         else {
            ++sum2;
            ++j;
         }
      }
      cout << sum + sum2 << "\n";
      
   }
}