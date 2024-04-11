#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> rasl(int n)
{
    vector <int> v;
    if(n==1) return v;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            v=rasl(n/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(n);
    return v;
}
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2);
        if(u>(2e18/u))
        {
            return 2e18;
        }
        else 
        {
            return u*u;
        }
    }
    int u=po(a,b-1);
    if(u>(2e18/a))
    {
        return 2e18;    
    }
    else 
    {
        return u*a;
    }
    
}
vector <int> z[65];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=1;i<=64;++i)
    {
        z[i]=rasl(i);
    }
    int h[64];
    for(int i=2;i<=63;++i)
    {
        int low=1;int up=1e18+1;
        while(true)
        {
            if((up-low)==1)
            {
                h[i]=up;
                break;
            }
            int k=(low+up)/2;
            int z=po(k,i);
            if(z<=1e18)
            {
                low=k;
            }
            else 
            {
                up=k;
            }
        }
    }
    int u[64][64];
    for(int i=0;i<64;++i)
    {
        for(int j=0;j<64;++j)
        {
            u[i][j]=po(i,j);
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int ans=(n-1);
    for(int i=2;i<=60;++i)
    {
        vector <int> v=z[i];
        int sz=v.size();
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        if(v.size()!=sz) continue;
        int o=1;
        if(sz%2==1) o=(-1);
        int low=1;
        int up=h[i];
        while(true)
        {
            if((up-low)==1)
            {
                break;
            }
            int k=(low+up)/2;
            int z;
            if(i<64 && k<64)
            {
                z=u[k][i];
            }
            else {
            z=po(k,i);
            }
            if(z<=n)
            {
                low=k;
            }
            else
            {
                up=k;
            }
        }
        //cout<<i<<" i "<<o<<" o "<<low-1<<" low-1 "<<endl;
        ans+=(o*(low-1));
    }
    cout<<ans<<endl;
    }
    return 0;
}