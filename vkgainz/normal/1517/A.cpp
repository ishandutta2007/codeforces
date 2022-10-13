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
int main() {
  int t; cin >> t;
  while(t--) {
    ll n; cin >> n;
    if(n%2050) {
      cout << -1 << "\n";
      continue;
    }
    n/=2050;
    int ans = 0;
    for(int i=0;i<19;i++) {
      ans += n%10;
      n/=10;
    }
    cout << ans << "\n";
  }
}