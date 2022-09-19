#include <bits/stdc++.h>

using namespace std;
#define int long long
int mul(int a,int b,int p)
{
    if(b==0) return 0;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=mul(a,b/2,p);
        return (u+u)%p;
    }
    else
    {
        int u=mul(a,b-1,p);
        return (a+u)%p;
    }
}
int po(int a,int b,int p)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2,p);
        return mul(u,u,p);
    }
    else
    {
        int u=po(a,b-1,p);
        return mul(u,a,p);
    }
}
vector <int> rasl(int m)
{
    vector <int> v;
    if(m==1) return v;
    for(int i=2;i*i<=m;++i)
    {
        if(m%i==0)
        {
            v=rasl(m/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(m);
    return v;
}
vector <int> del(int m)
{
    vector <int> v;
    for(int i=1;i*i<=m;++i)
    {
        if(m%i==0)
        {
            v.push_back(i);
            if(i*i!=m)
            {
                v.push_back(m/i);
            }
        }
    }
    return v;
}
int fi(int m)
{
    vector <int> v=rasl(m);
    sort(v.begin(),v.end());
    int ans=1;
    for(int i=0;i<v.size();++i)
    {
        if(i==0 || v[i]!=v[i-1])
        {
            ans*=(v[i]-1);
        }
        else
        {
            ans*=v[i];
        }
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,x;
    cin>>m>>x;
    vector <int> z=del(m);
    int f=fi(m);
    vector <int> h=del(f);
    sort(h.begin(),h.end());sort(z.begin(),z.end());
    unordered_map <int,int> d;
    for(int i=0;i<h.size();++i)
    {
        int o=po(x,h[i],m);
        //cout<<o<<" o "<<endl;
        int l=__gcd(o-1,m);
        //cout<<h[i]<<" h[i] "<<l<<" l "<<endl;
        if(!d.count(l))
        {
            vector <int> z1=del(l);
            for(auto v:z1)
            {
                if(!d.count(v))
                d[v]=h[i];
            }
        }
    }
    int ans=0;
    for(int i=0;i<z.size();++i)
    {
        //cout<<z[i]<<" z[i] "<<endl;
        //cout<<d[z[i]]<<" d[z[i]] "<<endl;
        ans+=fi(z[i])/d[z[i]];
    }
    cout<<ans;
    return 0;
}