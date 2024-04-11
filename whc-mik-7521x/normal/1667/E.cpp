#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=998244353;
int n;
long long fac[N],inv[N];
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
void init(){
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
    inv[N-1]=fp(fac[N-1],mod-2);
    for(int i=N-2;i>=1;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
long long C(long long x,long long y){
    if(x<y)return 0;
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
long long A(long long x,long long y){
    return fac[x]*inv[x-y]%mod;
}
const int G=3,Gi=332748118;
template<class T,class Alloc>
vector<T,Alloc>operator*(vector<T,Alloc>v1,vector<T,Alloc>v2){
    vector<T,Alloc>res=v1;
    for(int i=0;i<(int)v1.size();i++)res[i]=res[i]*v2[i]%mod;
    return res;
}
class ntt{
    public:
    long long fp(long long x,long long y){
        long long res=1;
        while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
        return res;
    }
    void cl(vector<long long>&c,int len){
        vector<int>rev;
        rev.resize(c.size());
        rev[0]=0;
        for(int i=0;i<len;i++){
            rev[i]=rev[i>>1]>>1;
            if(i&1)rev[i]|=len>>1;
        }
        for(int i=0;i<len;i++){
            if(i<rev[i])swap(c[i],c[rev[i]]);
        }
    }
    vector<long long>NTT(vector<long long>c,int len,int tp){
        cl(c,len);
        for(int siz=2;siz<=len;siz<<=1){
            long long un=fp(tp==1?G:Gi,(mod-1)/(siz));
            for(int o=0;o<len;o+=siz){
                long long w=1;
                for(int k=o;k<o+(siz>>1);k++){
                    long long u=c[k];
                    long long t=w*c[k+(siz>>1)]%mod;
                    c[k]=(u+t)%mod;
                    c[k+(siz>>1)]=(u-t+mod)%mod;
                    w=w*un%mod;
                }
            }
        }
        if(tp==-1){
            for(int i=0;i<len;i++)c[i]=c[i]*fp(len,mod-2)%mod;
        }
        return c;
    }
    vector<long long>calc(vector<long long>v1,vector<long long>v2){
        int len=1<<(int)(log2(v1.size()+v2.size())+1);
        v1.resize(len),v2.resize(len);
        return NTT(NTT(v1,len,1)*NTT(v2,len,1),len,-1);
    }
};
ntt ty;
long long ans[N],dp[N];
int main(){
    scanf("%d",&n);
    init();
    vector<long long>v1,v2;
    v1.resize(n+1),v2.resize(n+1);
    for(int i=n/2;i<=n;i++)v1[i-n/2]=inv[n-i];
    for(int i=n/2;i<=n-2;i++)v2[n-i]=fac[n-i-2];
    v1=ty.calc(v1,v2);
    dp[1]=fac[n-1];
    for(int i=2;i<=n/2+1;i++)dp[i]=v1[n/2+i+1]*fac[n-i]%mod*(i-1)%mod;
    long long tot=0;
    for(int i=n;i;i--){
        ans[i]=(dp[i]-tot+mod)%mod;
        tot=(tot+dp[i]*fp(i-1,mod-2)%mod)%mod;
    }
    for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
    return  0;
}