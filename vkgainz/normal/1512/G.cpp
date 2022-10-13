#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 1e7+5;
using cd = complex<double>;
const double PI = acos(-1);
ll sum[MX];
int ans[MX];
int main() {
  for(int i=1;i<MX;i++)  {
    for(int j=1;j*i<MX;j++) {
      sum[i*j] += i;
    }
  }
  for(int i=0;i<MX;i++) ans[i] = 100000000;
  for(int i=MX-1;i>=1;i--) {
    if(sum[i] < MX) {
      ans[sum[i]] = i;
    }
  }
  int t; cin >> t;
  while(t--) {
    int c; cin >> c;
    if(ans[c] == 100000000) cout << -1 << "\n";
    else
      cout << ans[c] << "\n";
  }
}