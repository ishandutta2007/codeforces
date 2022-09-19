#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=500005;
bool used[maxn];
int mipr[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    used[0]=true;
    used[1]=true;
    for(int i=0;i<maxn;++i)
    {
        mipr[i]=1e18;
    }
    mipr[0]=1e18;
    mipr[1]=1;
    for(int i=2;i<maxn;++i)
    {
        if(!used[i])
        {
        for(int j=2;(i*j)<maxn;++j)
        {
            used[i*j]=true;
            mipr[i*j]=min(i,mipr[i*j]);
        }
        }
    }
    for(int i=0;i<maxn;++i)
    {
        if(!used[i])
        {
            mipr[i]=i;
        }
    }
    int n;
    cin>>n;
    int mip[n+1];
    mip[0]=1e18;
    for(int i=1;i<=n;++i)
    {
        mip[i]=i/mipr[i];
    }
    sort(mip,mip+n+1);
    for(int i=2;i<=n;++i)
    {
        int low=0;
        int up=maxn+2;
        while(true)
        {
            if((up-low)==1)
            {
                cout<<up<<" ";
                break;
            }
            int k=(low+up)/2;
            if((upper_bound(mip,mip+n+1,k)-mip)>=i)
            {
                up=k;
            }
            else
            {
                low=k;
            }
        }
    }
    return 0;
}