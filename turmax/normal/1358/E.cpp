#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int sz=(n+1)/2;
    int a[sz];
    for(int i=0;i<sz;++i)
    {
        cin>>a[i];
    }
    int x;
    cin>>x;
    int pr[sz+1];
    pr[0]=0;
    for(int i=0;i<sz;++i)
    {
        pr[i+1]=pr[i]+a[i];
    }
    if(x<0)
    {
        int y=abs(x);
        int g[sz];
        for(int i=0;i<sz;++i)
        {
            int o=(pr[sz]-pr[i]);
            int curr1=(sz-i);
            //cout<<o<<" o "<<curr1<<" curr1 "<<endl;
            if(o<=0)
            g[i]=(-1);
            else
            g[i]=curr1+(o-1)/y;
        }
        int mi=1e18;
        for(int i=0;i<sz;++i)
        {
            //cout<<i<<" i "<<g[i]<<" g[i] "<<endl;
            int k=(n-i);
            mi=min(mi,g[i]);
            if(k<=mi)
            {
                cout<<k;
                return 0;
            }
        }
        cout<<(-1);
        return 0;
    }
    if(x>=0)
    {
        int u=pr[sz];
        for(int i=0;i<(n-sz);++i)
        {
            u+=x;
        }
        if(u>0)
        {
            cout<<n;
            return 0;
        }
        else
        {
            cout<<(-1);
            return 0;
        }
    }
    return 0;
}