#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t;
     cin >> t;
     while(t--) {
         int n;
         cin >> n;
         vector<int> a(n);
         for(int i = 0; i < n; ++i) cin >> a[i], --a[i];
         vector<vector<int>> pre(n + 1, vector<int>(n)), suf(n + 1, vector<int>(n));
         for(int i = 0; i < n; ++i) {
             if(i) pre[i] = pre[i - 1];
             for(int j = a[i]; j < n; ++j) pre[i][j]++;
         }
         for(int i = n - 1; i >= 0; --i) {
             suf[i] = suf[i + 1];
             for(int j = a[i]; j < n; ++j) suf[i][j]++;
         }
         ll ans = 0;
         for(int i = 1; i < n; ++i) {
             for(int j = i + 1; j + 1 < n; ++j) {
                 ans += 1ll * pre[i-1][a[j]] * suf[j+1][a[i]];
             }
         }
         cout << ans << '\n';
     }
}