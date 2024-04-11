#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 1e5+5;

int main() {
  int t; cin >> t;
  while(t--) {
    int n,m; cin >> n >> m;
    vector<int> k(n);
    for(int i=0;i<n;i++) cin >> k[i], --k[i];
    vector<int> c(m);
    for(int i=0;i<m;i++) cin >> c[i];
    ll ans = 1e15;
    sort(k.begin(), k.end());
    int numNeed = 0;
    int j=0;
    for(int i=0;i<n;i++) {
      if(j>k[i]) ++numNeed;
      else ++j;
    }
    //pay at least numNeed up front, buy the rest
    vector<ll> pref(n+1);
    pref[0] = 0LL;
    for(int i=1;i<=n;i++) pref[i] = pref[i-1]+c[i-1];
    vector<ll> pref2(n+1);
    pref2[0] = 0LL;
    for(int i=1;i<=n;i++) pref2[i] = pref2[i-1]+c[k[i-1]];
    for(int i=numNeed;i<=n;i++) {
      ans = min(ans, pref[n-i]+pref2[i]);
    }
    cout << ans << "\n";
  }
}