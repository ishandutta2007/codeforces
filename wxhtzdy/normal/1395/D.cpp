/**
 *  author: milos
 *  created: 27.12.2020 19:48:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d, m;
  cin >> n >> d >> m;
  vector<long long> a(n);
  vector<long long> big, small;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > m) {
      big.push_back(a[i]);  
    } else {
      small.push_back(a[i]);
      ans += a[i];
    }
  }
  sort(small.rbegin(), small.rend());
  sort(big.rbegin(), big.rend());
  vector<long long> pref;
  for (int i = 0; i < (int) small.size(); i++) {
    if (i == 0) {
      pref.push_back(small[i]);
    } else {
      long long lst = pref.back();
      pref.push_back(lst + small[i]);
    }
  }
  long long sum = 0;
  long long cnt = 0;              
  for (int i = 0; i < (int) big.size(); i++) {
    sum += big[i];
    if (i == 0) {
      cnt++;
    } else {
      cnt += d + 1;
    }
    int take = n - cnt;
    if (take < 0) {
      break;
    }
    if ((int) small.size() >= take && take > 0) {
      ans = max(ans, sum + pref[take - 1]);
    } else {
      if (take > (int) small.size() && (int) small.size() > 0) {
        ans = max(ans, sum + pref.back());
      } else {
        ans = max(ans, sum);
      }
    } 
    //cout << i << " " << take << '\n';
  }
  cout << ans << '\n';
  return 0;
}