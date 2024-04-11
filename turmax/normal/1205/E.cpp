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
vector <int> rasl(int x)
{
    vector <int> v;
    if(x==1) return v;
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            v=rasl(x/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(x);
    return v;
}
vector <int> del(int x)
{
    vector <int> v;
    for(int i=1;i*i<=x;++i)
    {
        if(x%i==0)
        {
            v.push_back(i);
            if((i*i)!=x)
            {
                v.push_back(x/i);
            }
        }
    }
    return v;
}
int slv1(int x)
{
    int ans=0;
    for(int i=1;i<x;++i)
    {
        vector <int> v=rasl(i);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        int sz=v.size();
        for(int mask=0;mask<(1<<sz);++mask)
        {
            int u=1;
            int z=1;
            for(int i=0;i<sz;++i)
            {
                if(mask & (1<<i))
                {
                    z*=v[i];
                    u*=(-1);
                }
            }
            ans+=(((x-i)/z)*u);
            ans%=p;
        }
    }
    ans%=p;ans+=p;ans%=p;
    return ans;
}
int f(int l,int r,int x)
{
    int ans=0;
    vector <int> v=rasl(x);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int sz=v.size();
    for(int mask=0;mask<(1<<sz);++mask)
    {
        int u=1;
        int z=1;
        for(int i=0;i<sz;++i)
        {
            if(mask & (1<<i))
            {
                z*=v[i];
                u*=(-1);
            }
        }
        ans+=u*((r/z)-((l-1)/z));
        ans%=p;
    }
    ans%=p;ans+=p;ans%=p;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    int l=inv(k);
    int po[n+1];
    po[0]=1;
    for(int i=1;i<=n;++i)
    {
        po[i]=po[i-1]*l;
        po[i]%=p;
    }
    int ans=0;
    for(int i=1;i<n;++i)
    {
        ans+=po[n-i];
        ans%=p;
    }
    for(int d=1;d<n;++d)
    {
        int x=((n-1)/d+1);
        int u=slv1(x);
        u--;
        u%=p;
        ans+=u*po[n-d];
        ans%=p;
    }
    for(int x=n;x<(2*n-1);++x)
    {
        vector <int> z=del(x);
        for(auto d:z)
        {
            int l=(x+d-n+1);int r=(n-1);
            if(l>r) continue;
            r/=d;l+=(d-1);l/=d;
            if(l>r) continue;
            ans+=f(l,r,(x/d)+1)*po[2*n-x-d];
            ans%=p;
        }
    }
    /*for(int i=1;i<n;++i)
    {
        for(int j=1;j<n;++j)
        {
            if(i==j) continue;
            if((i+j)<=n)
            {
                ans+=po[n-__gcd(i,j)];
                ans%=p;
            }
            /*if(((i+j)-__gcd(i,j))>=n)
            {
                ans+=po[n-max(i+j-n,__gcd(i,j))];
                ans%=p;
            }
        }
    }*/
    cout<<ans;
    return 0;
}