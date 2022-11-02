#include<bits/stdc++.h>

using namespace std;
 
#define ll long long
#define ar array
 
#define fi first
#define se second
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll x;
  cin>>x;
  ll ans = x;
  for(ll i=1;i*i<=x;i++){
    if(x%i==0){
      ll a=i,b=x/i;
      if(__gcd(a,b)==1){
        ans=min(ans,b);
      }
    }
  }
  cout<<ans<<' ' <<x/ans<<endl;
}