#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;
const ll mod=998244353;
const ll linf=0x3f3f3f3f3f3f3f3f;
ll po[maxn],arr[maxn];
int k[maxn];
vector<int>v[maxn];

inline ll pm(ll a,ll n,ll m)
{
    ll ret=1;
    for(; n; n>>=1,a=a*a%m)
        if(n&1)
            ret=ret*a%m;
    return ret;
}

ll ppp(int a)
{
    if(!po[a])
        po[a]=pm(a,mod-2,mod);
    return po[a];
}

int main()
{
//    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",k+i);
        for(int j=0;j<k[i];j++)
        {
            int a;
            scanf("%d",&a);
            arr[a]+=ppp(n)*ppp(k[i])%mod;
            arr[a]%=mod;
            v[i].push_back(a);
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        for(auto j:v[i])
        {
            ans+=arr[j]*po[n]%mod;
            ans%=mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}