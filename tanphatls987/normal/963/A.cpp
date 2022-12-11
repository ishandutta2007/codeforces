#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD=1e9+9;

ll power(ll x,ll y){
        ll ans=1;
        while (y){
                if (y&1) ans=ans*x%MOD;
                x=x*x%MOD;
                y>>=1;
        }
        return ans;
}
int n,v1,v2,k;
string s;
int main(){
        cin>>n>>v1>>v2>>k;
        cin>>s;

        int len=(n+1)/k;
        ll ans=0;
        ll rv1=power(v1,MOD-2);
        ll scale=power(v2,k)*power(rv1,k)%MOD;
        assert(scale!=0);
        for(int i=0;i<k;i++){
                ll val=power(v1,n-i)*power(v2,i)%MOD;
                
                ans=(ans+((s[i]=='+')?1:-1)*val+MOD)%MOD;
        }
        if (scale!=1)
                ans=ans*(power(scale,len)+MOD-1)%MOD*power(scale+MOD-1,MOD-2)%MOD;
        else ans=(ans*len)%MOD;
        cout<<ans;
}