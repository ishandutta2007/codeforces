#include <bits/stdc++.h>
using namespace std;
typedef long long LL; 
inline LL pow(LL x,LL y,LL mod)
{
    LL ans=1;
    for(;y;y>>=1,x=(x*x)%mod)
        if(y&1)
            ans=(ans*x)%mod;
    return ans%mod;
}
const LL mod=1000000007;
const int maxn=100005;
LL fac[maxn<<1];
int main()
{
    LL n;
    cin>>n;
    fac[0]=1;
    for(int i=1;i<=(n<<1);++i)
        fac[i]=fac[i-1]*i% mod;
    cout<<(fac[n<<1]*pow(fac[n]*fac[n]%mod,mod-2,mod))%mod-n<<endl;
    return 0;
}