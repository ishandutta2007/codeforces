#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        int u=po(a,b-1);
        return (a*u)%p;
    }
}
int inv(int x)
{
    return po(x,p-2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    int w[n][n];
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) w[i][j]=(a[i]*inv(a[i]+a[j]))%p;
    int ans=0;
    int sz=(1<<n);
    int o[sz];
    o[0]=1;
    for(int mask=1;mask<sz;++mask)
    {
        o[mask]=1;
        for(int mask1=mask;;mask1=(mask1-1) & mask)
        {
            if(mask1==0) break;
            if(mask1==mask) continue;
            int mask2=mask^mask1;
            int u=1;
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<n;++j)
                {
                    if((mask1 & (1<<i)) && (mask2 & (1<<j)))
                    {
                        u*=w[i][j];
                        u%=p;
                    }
                }
            }
            o[mask]-=o[mask1]*u;
            o[mask]%=p;
        }
        //cout<<mask<<" mask "<<o[mask]<<" o[mask] "<<endl;
        int u=1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if((mask & (1<<i)) && ((sz-1-mask) & (1<<j)))
                {
                    u*=w[i][j];
                    u%=p;
                }
            }
        }
        ans+=(((u*o[mask])%p)*(__builtin_popcount(mask)));
        ans%=p;
    }
    cout<<(ans%p+p)%p;
    return 0;
}