#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<stdio.h>
#include<set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const int mod = 998244353;
ll fac[1000005];
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
int main()
{
    int n;
    cin>>n;
    fac[0] = 1;
    for(int i=1;i<=n;++i)
    {
        fac[i] = fac[i-1]*i%mod;
    }
    ll ans = 0;
    for(int i=2;i<=n;++i)
    {
        ans = ans + fac[n]*(n-i+1)%mod*(i-1)%mod*fpow(fac[i],mod-2)%mod;
        ans %= mod;
    }
    ans += 1;
    ans %= mod;
    cout<<ans<<endl;
}