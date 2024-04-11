#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
const int MX = 3e6+5;
ll sum(ll x) {
  int ans = 0;
  while(x > 0) {
    ans += x%10;
    x/=10;
  }
  return ans;
}
int main() {
  int t; cin >> t;
  while(t--) {
    ll n; cin >> n;
    ll ans = 2e18;
    for(int i=0;i<=9;i++) {
      if(__gcd(sum(n+i), n+i) > 1)
        ans = min(ans, n+i);
    }
    cout << ans << "\n";
  }
}