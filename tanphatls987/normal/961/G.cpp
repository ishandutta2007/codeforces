#include <bits/stdc++.h>

using namespace std;


const int N=2e5+10;
const int MOD=1e9+7;
long long fac[N],rev[N],revfac[N];
void prepare(){
        fac[0]=1;
        for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%MOD;
        rev[1]=1;
        for(int i=2;i<N;i++) rev[i]=MOD-(MOD/i)*rev[MOD%i]%MOD;
        revfac[0]=1;
        for(int i=1;i<N;i++) revfac[i]=revfac[i-1]*rev[i]%MOD;
}

long long C(int n,int k){
        if (k<0||k>n) return 0;
        return fac[n]*revfac[n-k]%MOD*revfac[k]%MOD;
}
long long power(long long x,long long y){
        long long ans=1;
        while (y){
                if (y&1) ans=ans*x%MOD;
                x=x*x%MOD;
                y>>=1;
        }
        return ans;
}
long long sterling(int n,int k){
        long long ans=0;
        for(int i=0;i<=k;i++){
                int sign=(k-i)%2?-1:1;
                ans=(ans+sign*C(k,i)*power(i,n))%MOD;
        }
        return ((ans+MOD)*revfac[k])%MOD;
}
int main(){
        prepare();
        int n,k;
        cin>>n>>k;
        long long ans=0;
        for(int i=1;i<=n;i++){
                int val;
                cin>>val;
                ans=(ans+val)%MOD;
        }
        ans=ans*(sterling(n-1,k-1)+(n-1+k)*sterling(n-1,k)%MOD)%MOD;
        cout<<ans;
}