#include <iostream>
#include <vector>

using namespace std;

int main() {
   int t; cin >> t;
   while (t--) {
      int n, k; cin >> n >> k;
      string s; cin >> s;
      vector<int> p(n + 1);
      p[0] = 0;
      for (int i = 1; i <= n; i++) {
         p[i] = p[i - 1] + (s[i - 1] == 'W');
      }
      int ans = n;
      for (int i = k; i <= n; i++) {
         ans = min(ans, p[i] - p[i - k]);
      }
      cout << ans << "\n";
      
   }
}