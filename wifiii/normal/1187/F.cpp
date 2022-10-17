
#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

const int mod = 1e9+7;

ll l[200005],r[200005];
ll np[200005],p[200005],np3[200005],sum;
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
inline void add(ll &a,ll b) {a=(a+b)%mod;}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    forii cin>>l[i];
    forii cin>>r[i],r[i]+=1;
    forii if(min(r[i],r[i-1])>max(l[i],l[i-1])) np[i]=(min(r[i],r[i-1])-max(l[i],l[i-1]))*fpow((r[i]-l[i])*(r[i-1]-l[i-1])%mod,mod-2);
    forii
        if(min(min(r[i],r[i-1]),r[i+1])>max(max(l[i],l[i-1]),l[i+1]))
        np3[i]=(min(min(r[i],r[i-1]),r[i+1])-max(max(l[i],l[i-1]),l[i+1]))*fpow((r[i]-l[i])*(r[i-1]-l[i-1])%mod*(r[i+1]-l[i+1])%mod,mod-2);
    forii p[i]=(mod+1-np[i])%mod;
    forii add(sum,p[i]);
    ll ans=0;
    forii
    {
        add(ans,(sum-p[i-1]-p[i]-p[i+1]) % mod * p[i] % mod);
        add(ans,p[i]);
        if(i<n) add(ans,(1-np[i]-np[i+1]+np3[i])%mod);
        if(i>1) add(ans,(1-np[i]-np[i-1]+np3[i-1])%mod);
    }
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
}