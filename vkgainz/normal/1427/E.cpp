#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define SUMITH_IS_HOT_AF main
int numOp = 0;
vector<tuple<ll,ll,bool>> v;
void getKthMultiple(ll x, ll k) {
    if(k==1) return;
    getKthMultiple(x,k/2);
    ll r = x*(k/2);
    if(k%2==0){
        ++numOp;
        v.push_back({r,r,1});
    }
    else {
        numOp+=2;
        v.push_back({r,r,1});
        v.push_back({2*1LL*r,x,1});
    }
}
ll modInverse(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        ll q = a / m; 
        ll t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 
ll weirdMod(ll x, ll mult, ll mod) {
    if(mult==1) return x%mod;
    ll a = weirdMod(x,mult/2,mod);
    if(mult%2) {
        return (a*1LL*2+x)%mod;
    }
    else {
        return a*1LL*2%mod;
    }
}
int SUMITH_IS_HOT_AF() {
    ll x; cin >> x;
    ll r = 1;
    while(r<x) r*=2;
    r/=2;
    getKthMultiple(x,r);
    ++numOp;
    v.push_back({x,x*1LL*r,0});
    ll g = x^(x*1LL*r);
    ll inv = modInverse(x,g);
    ll y = (g+1)/2;
    ll a = weirdMod(inv-1,y,g);
    if(a<0) a+=g;
    getKthMultiple(x,2*a+1);
    getKthMultiple(g,((x*1LL*(2*a+1))-1)/g);
    ++numOp;
    v.push_back({x*1LL*(2*a+1),(x*1LL*(2*a+1))-1,0});
    cout << v.size() << endl;
    for(auto &it : v){
       if(get<2>(it)==0) {
           cout << get<0>(it) << " ^ " << get<1>(it) << endl;
       }
       else {
           cout << get<0>(it) << " + " << get<1>(it) << endl;
       }
    }
}