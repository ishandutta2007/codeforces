#include<bits/stdc++.h>
using namespace std;

int main() {
   int t; cin >> t;
   while(t--) {
       int n; cin >> n;
       vector<int> d(n);
       for(int i = 0; i < n; i++) {
           cin >> d[i];
       }
       sort(d.begin(), d.end());
       long long sum = 0LL;
       long long ans = d[n - 1];
       for(int i = 0; i < n; i++) {
           ans -= (d[i] * 1LL * i - sum);
           sum += d[i];
       }
       cout << ans << "\n";
   }
}