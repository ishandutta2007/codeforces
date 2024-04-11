#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t;
     cin >> t;
     while(t--) {
         int n, m;
         cin >> n >> m;
         string s;
         cin >> s;
         vector<int> col(n * m);
         for(int i = 0; i < m; ++i) {
             for(int j = i; j < n * m; j += m) {
                 if(s[j] == '1') {
                     col[j] += 1;
                     break;
                 }
             }
         }
         for(int j = 1; j < n * m; ++j) col[j] += col[j - 1];

         vector<int> row(n * m);
         int p = -1;
         for(int i = n * m - 1; i >= 0; --i) {
             if(s[i] == '1') {
                 int d = min(m, p == -1 ? m : p - i);
                 row[i] += 1;
                 if(i + d < n * m) row[i + d] -= 1;
                 p = i;
             }
         }
         for(int i = 1; i < n * m; ++i) row[i] += row[i - 1];
         for(int i = m; i < n * m; ++i) row[i] += row[i - m];
         for(int i = 0; i < n * m; ++i) cout << col[i] + row[i] << ' '; cout << '\n';
     }
}