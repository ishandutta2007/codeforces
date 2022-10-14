/**
 *    author:  milos
 *    created: 16.02.2021 15:56:39       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    vector<int> b(n + 1, 0);
    for (int i = 0; i < n; i++) {
      if (cnt[a[i]] > 0) {
        b[cnt[a[i]]]++;
        cnt[a[i]] = 0;
      }
    }
    long long ans = (long long) n * (long long) n * (long long) n;
    long long curr = 0LL;
    long long aa = 0LL;
    vector<long long> pref(n + 1, 0LL);
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + (long long) i * b[i];
    }         
    for (int i = n; i > 0; i--) {
      ans = min(ans, pref[i - 1] + curr);
      aa += b[i];
      curr += aa;
    }
    //ans = min(ans, curr);
    cout << ans << '\n';
  }
  return 0;
}