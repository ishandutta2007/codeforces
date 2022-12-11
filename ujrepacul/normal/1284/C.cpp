#include <bits/stdc++.h>
using namespace std;
long long fact[250003];
int main()
{
    ios_base::sync_with_stdio(false);
    long long n,w,t,i,j,k=0,pas=1<<15,mod,sc,cnt=0;
    cin>>n>>mod;
    fact[1]=1;
    for(i=2;i<=n;++i)
        fact[i]=(fact[i-1]*1LL*i)%mod;
    fact[0]=1;
    for(i=0;i<n;++i)
        cnt=(cnt+(((((n-i)*1LL*(n-i))%mod*1LL*fact[i+1])%mod)*1LL*fact[n-i-1])%mod)%mod;
    cout<<cnt;
    return 0;
}