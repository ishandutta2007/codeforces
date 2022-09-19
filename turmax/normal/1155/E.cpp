#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e6+3;
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
int f(int x,vector <int> v)
{
    int ans=0;
    int m=1;
    for(int i=0;i<v.size();++i)
    {
        ans+=m*v[i];
        ans%=p;
        m*=x;
        m%=p;
    }
    return ans;
}
vector <int> operator *(vector <int> a,vector <int> b)
{
    vector <int> c(a.size()+b.size());
    for(int i=0;i<c.size();++i)
    {
        c[i]=0;
    }
    for(int i=0;i<a.size();++i)
    {
        for(int j=0;j<b.size();++j)
        {
            c[i+j]+=a[i]*b[j];
            c[i+j]%=p;
        }
    }
    return c;
}
vector <int> operator +(vector <int> a,vector <int> b)
{
    int sz=max(a.size(),b.size());
    vector <int> c(sz);
    for(int i=a.size();i<sz;++i)
    {
        a.push_back(0);
    }
    for(int i=b.size();i<sz;++i)
    {
        b.push_back(0);
    }
    for(int i=0;i<sz;++i)
    {
        c[i]=a[i]+b[i];
        c[i]%=p;
    }
    return c;
}
vector <int> go(vector <pair<int,int> > v)
{
    vector <int> o;
    for(int i=0;i<v.size();++i)
    {
        int y=v[i].second;
        vector <int> u;
        u.push_back(y);
        int d=1;
        vector <int> z;
        z.push_back(1);
        for(int j=0;j<v.size();++j)
        {
            if(j==i)
            {
                continue;
            }
            d*=(v[i].first-v[j].first);
            d%=p;
            d+=p;
            d%=p;
            vector <int> g;
            g.push_back(-v[j].first);
            g.push_back(1);
            z=z*g;
        }
        vector <int> h;
        h.push_back(inv(d));
        z=z*h;
        z=z*u;
        o=o+z;
    }
    return o;
}
int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector <pair<int,int> > v;
    for(int i=0;i<15;++i)
    {
        cout<<"? "<<i<<endl;
        int x;
        cin>>x;
        v.push_back({i,x});
    }
    vector <int> a=go(v);
    for(int i=0;i<=(p-1);++i)
    {
        if(f(i,a)==0)
        {
            cout<<"! "<<i<<endl;
            exit(0);
        }
    }
    cout<<"! "<<(-1)<<endl;
    exit(0);
    return 0;
}