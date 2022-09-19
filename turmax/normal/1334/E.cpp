#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int po(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    int u=po(a,b-1);
    return (a*u)%p;
}
int inv(int x)
{
    return po(x,p-2);
}
vector <int> rasl(int x)
{
    vector <int> v;
    if(x==1)
    {
        return v;
    }
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
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int fact[50];
    int invf[50];
    int u=1;
    for(int i=0;i<50;++i)
    {
        fact[i]=u;
        invf[i]=inv(u);
        u*=(i+1);
        u%=p;
    }
    int d;
    cin>>d;
    vector <int> z=rasl(d);
    int q;
    cin>>q;
    for(int i=0;i<q;++i)
    {
        int u,v;
        cin>>u>>v;
        int x=__gcd(u,v);
        int a=u/x;int b=v/x;
        vector <int> h1,h2;
        for(int i=0;i<z.size();++i)
        {
            if(a%z[i]==0)
            {
                a/=z[i];
                h1.push_back(z[i]);
            }
            if(b%z[i]==0)
            {
                b/=z[i];
                h2.push_back(z[i]);
            }
        }
        int ans=(fact[h1.size()]*fact[h2.size()])%p;
        sort(h1.begin(),h1.end());sort(h2.begin(),h2.end());
        vector <int> z1=h1;vector <int> z2=h2;
        z1.erase(unique(z1.begin(),z1.end()),z1.end());z2.erase(unique(z2.begin(),z2.end()),z2.end());
        for(int i=0;i<z1.size();++i)
        {
            int x=upper_bound(h1.begin(),h1.end(),z1[i])-lower_bound(h1.begin(),h1.end(),z1[i]);
            ans*=invf[x];
            ans%=p;
        }
        for(int i=0;i<z2.size();++i)
        {
            int x=upper_bound(h2.begin(),h2.end(),z2[i])-lower_bound(h2.begin(),h2.end(),z2[i]);
            ans*=invf[x];
            ans%=p;
        }
        cout<<ans<<endl;
    }
    return 0;
}