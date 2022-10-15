#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL);
  ll n; cin >> n;
  vector<ll> p(n + 1), h(n + 1);
  h[1] = 1;
  for(ll i = 2; i <= n; i++){
    cin >> p[i];
    h[i] = h[p[i]] + 1;
  }
  bool isValid = true;
  vector<ll> s(n + 1), a(n + 1, INF);
  for(ll i = 1; i <= n; i++){
    cin >> s[i];
    a[p[i]] = min(a[p[i]], s[i]);
  }
  for(ll i = 1; i <= n; i++){
    if(h[i] % 2 == 0){
      if(s[i] != -1) isValid = false;
      if(a[i] == INF) s[i] = s[p[i]];
      else s[i] = a[i];
    }
    else{
      if(s[i] == -1) isValid = false;
    }
    if(s[i] < s[p[i]]) isValid = false;
  }
  if(!isValid) cout << -1 << endl;
  else{
    ll ans = s[1];
    for(ll i = 2; i <= n; i++) ans += s[i] - s[p[i]];
    cout << ans << endl;
  }
  return 0;
}