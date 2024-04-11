#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#define ll long long
#define N 500005
#define M 25
#define mod 1000000007
int inf=0x3f3f3f3f;
using namespace std;
ll f(ll x)
{
    ll ans=0;
    ll now=1;
    ll sum=x;
    ll len=1;
    ll j=1;
    ll o=2;
    while(sum)
    {
        sum-=len;
        if(now)
        {
            ans+=((len%mod)*((len+j-1)%mod));
            ans%=mod;
            j+=((len*2)%mod);
            j%=mod;
        }
        else
        {
            ans+=((len%mod)*((len+o-1)%mod));
            ans%=mod;
            o+=((len*2)%mod);
            o%=mod;
        }
        now=1-now;
        len=min(len*2,sum);
    }
    return ans%mod;
}
int main()
{
    ll l,r;
    cin>>l>>r;
    ll ans=f(r)-f(l-1);
    ans=(((ans%mod)+mod)%mod);
    cout<<ans<<endl;
    return 0;
}