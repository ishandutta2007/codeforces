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
         vector<int> a(n), b(n);
         for(int i = 0; i < n; ++i) cin >> a[i], --a[i];
         for(int i = 0; i < n; ++i) cin >> b[i], --b[i];
         vector<int> pos(n);
         for(int i = 0; i < n; ++i) pos[a[i]] = i;
         vector<int> vis(n);

         int del = 0;
         for(int i = 0; i < n; ++i) {
             if(vis[i]) continue;
             int p = i, cnt = 0;
             while(!vis[p]) {
                 ++cnt;
                 vis[p] = 1;
                 p = pos[b[p]];
             }
             if(cnt % 2 == 1) ++del;
         }

         ll ans = 0;
         for(int i = 1, j = n, k = 0; k < (n - del) / 2; ++i, --j, ++k) {
             ans += j - i;
         }
         cout << ans * 2 << '\n';
     }
}