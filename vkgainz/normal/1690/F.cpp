#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long period(vector<char> &s) {
   for (int len = 1; len <= s.size(); len++) {
      if (s.size() % len == 0) {
         bool work = true;
         for (int i = 0; i < s.size(); i++) {
            if (s[i] != s[(i + len) % s.size()]) {
               work = false;
            }
         }
         if (work) return len;
      }
   }
   return -1;
}

int main() {
   int t; cin >> t;
   while (t--) {
      int n; cin >> n;
      string s; cin >> s;
      vector<int> p(n);
      for (int i = 0; i < n; i++) {
         cin >> p[i];
         --p[i];
      }
      vector<bool> vis(n);
      long long ans = 1;
      for (int i = 0; i < n; i++) {
         if (vis[i]) continue;
         vis[i] = true;
         vector<char> occ;
         occ.push_back(s[i]);
         int curr = i;
         while (!vis[p[curr]]) {
            curr = p[curr];
            occ.push_back(s[curr]);
            vis[curr] = true;
         }
         long long p = period(occ);
         ans = ans * 1LL * p / __gcd(ans, p);
      }
      cout << ans << "\n";
   }
}