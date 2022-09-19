#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x;
    cin>>n>>x;
    int a[2*n];
    int h[2*n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        a[n+i]=a[i];
        h[i]=(a[i]*(a[i]+1))/2;
        h[n+i]=h[i];
    }
    n*=2;
    int pra[n+1];
    int prh[n+1];
    pra[0]=0;prh[0]=0;
    for(int i=0;i<n;++i)
    {
        pra[i+1]=pra[i]+a[i];
        prh[i+1]=prh[i]+h[i];
    }
    int ans=(-1);
    for(int i=0;i<=n;++i)
    {
        int curr=pra[i];
        //cout<<i<<" "<<curr<<endl;
        int o=(curr-x);
        if(o<0)
        {
            continue;
        }
        int u=upper_bound(pra,pra+n+1,o)-pra-1;
        int z=o-pra[u];
        //cout<<z<<" z "<<i<<" i "<<u<<" u "<<endl;
        ans=max(ans,prh[i]-prh[u]-z*(z+1)/2);
    }
    cout<<ans;
    return 0;
}