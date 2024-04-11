#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < 60; i++) {
      long long ddd = pow(2, i);
      long long cnt = (n + 1) / ddd;
      if ((n + 1) % ddd == 0 && cnt != 0) {
        cnt--;
      }
      ans += cnt; 
    }
    cout << ans << '\n';
  }
  return 0;
}