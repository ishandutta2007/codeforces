#include<bits/stdc++.h>
using namespace std;
const int N=200005,E=15000005;
const long long inf=1000000000000000000ll;
int n,M,mi[5005][5005];
long long fac[N],inv[N],ans;
long long C(int n,int m)
{
    return fac[n]*inv[m]%M*inv[n-m]%M;
}
long long qpow(long long a,long long b)
{
    long long s=a,ans=1;
    while(b){
        if(b&1)
            ans=ans*s%M;
        s=s*s%M;
        b>>=1;
    }
    return ans;
}
int main(){
    cin>>n>>M;
    fac[0]=inv[0]=inv[1]=1;
    for(int i=2;i<=n;++i)
        inv[i]=inv[M%i]*(M-M/i)%M;
    for(int i=1;i<=n;++i)
    {
        inv[i]=inv[i-1]*inv[i]%M;
        fac[i]=fac[i-1]*i%M;
    }
    long long s1=1;
    for(int i=0;i<=n;++i)
    {
        mi[i][0]=1;
        for(int j=1;j<=n;++j)
            mi[i][j]=1ll*mi[i][j-1]*i%M;
    }
    for(int j=1;2*j<=n;++j)
    {
        s1=s1*(n-1)%M;
        for(int i=0;i<=n-2*j;++i)
            ans=(ans+C(n,i)*fac[n-i]%M*s1%M*mi[n-i-j][i]%M*C(n-i-j-1,j-1)%M*inv[j])%M;
    }
    cout<<ans<<endl;
}