#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
using ll = long long;
const int MX = 5e5+5;

int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(nullptr);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> p(n);
    p[0] = n/2+1;
    for(int i=1;i<=n/2 - 1;i++) {
      p[i] = i;
    }
    for(int i=n/2;i<=n-2;i++) {
      p[i] = i+2;
    }
    p[n-1] = n/2;
    vector<pair<int, int>> in;
    ll ans = 0LL;
    for(int i=n/2-1;i>=1;i--) {
      in.push_back({i, n-1});
    }
    for(int i=n/2;i<=n-2;i++) {
      in.push_back({i, 0});
    }
    in.push_back({0, n-1});
    for(auto &it : in) {
      ans+=(it.s-it.f)*1LL*(it.s-it.f);
    }
    cout << ans << "\n";
    for(int i=0;i<n;i++) {
      cout << p[i] << " ";
    }
    cout << "\n";
    cout << in.size() << "\n";
    for(auto &it : in) {
      cout << it.f+1 << " " << it.s+1 << "\n";
    }
  }
}