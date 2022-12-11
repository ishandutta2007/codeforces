#include <iostream>
#include <set>
#include <algorithm>
 
 using namespace std;
 
 int main() {
     ios_base :: sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     int n, k;
     cin >> n >> k;
     pair <int, int> p_i[n];
     long long cash[n];
     for (int i = 0; i < n; i++) {
         cin >> p_i[i].first;
         p_i[i].second = i;
     }
     for (int i = 0; i < n; i++) cin >> cash[i];
     stable_sort(p_i, p_i + n);
     multiset <long long, greater<long long>> s;
     long long ans[n];
     for (int i = 0; i < n; i++) {
         set <long long, greater<long long>> :: iterator uk = s.begin();
         int cnt = 0;
         ans[p_i[i].second] = cash[p_i[i].second];
         while (cnt < k && uk != s.end()) {
             cnt++;
             ans[p_i[i].second] += (*uk);
             uk++;
         }
         s.insert(cash[p_i[i].second]);
     }
     for (int i = 0; i < n; i++) cout << ans[i] << ' ';
     return 0;
 }