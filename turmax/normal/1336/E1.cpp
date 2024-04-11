#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int m;
vector <int> b;
vector <int> c;
map <pair<int,int>,vector <int> > o;
int po[63];
int popc(int x)
{
    int s=0;
    for(int i=0;i<m;++i)
    {
        if(x & po[i])
        {
            ++s;
        }
    }
    return s;
}
vector <int> basis(vector <int> a,int m)
{
    int n=a.size();
    if(m==0 || n==0) {vector <int> v;return v;}
    sort(a.begin(),a.end());reverse(a.begin(),a.end());
    if(a[0]<po[m-1])
    {
        return basis(a,m-1);
    }
    for(int i=1;i<n;++i)
    {
        a[i]=min(a[i],a[i]^a[0]);
    }
    vector <int> res;
    vector <int> a1;
    for(int i=1;i<n;++i) a1.push_back(a[i]);
    res=basis(a1,m-1);
    res.insert(res.begin(),a[0]);
    return res;
}
vector <int> slv(int n,int h)
{
    if(n==0)
    {
        int l=popc(h);
        vector <int> v;
        for(int i=0;i<=m;++i) v.push_back(0);
        v[l]=1;
        return v;
    }
    if(o.count({n,h})) return o[{n,h}];
    vector <int> v;
    vector <int> z1=slv(n-1,h);
    v=z1;
    vector <int> z2=slv(n-1,h^c[n-1]);
    for(int i=0;i<=(m-1);++i)
    {
        v[i+1]+=z2[i];
        v[i+1]%=p;
    }
    o[{n,h}]=v;
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int u1=1;
    for(int i=0;i<62;++i)
    {
        po[i]=u1;
        u1*=2;
    }
    int n;
    cin>>n>>m;
    vector <int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    b=basis(a,m);
    sort(b.begin(),b.end());reverse(b.begin(),b.end());
    while(!b.empty() && b.back()==0) b.pop_back();
    for(int cyc=0;cyc<b.size();++cyc)
    {
        for(int i=0;i<b.size();++i)
        {
            for(int j=(i+1);j<b.size();++j)
            {
                b[j]=min(b[j],b[j]^b[i]);
                b[i]=min(b[i],b[j]^b[i]);
            }
        }
    }
    /*for(auto h:b) cout<<h<<' ';
    cout<<endl;*/
    c.resize(b.size());
    for(int i=0;i<b.size();++i)
    {
        for(int k=0;k<m;++k)
        {
            if((b[i] & po[k]) && b[i]<po[k+1])
            {
                c[i]=b[i]-po[k];
            }
        }
    }
    /*for(auto h:c) cout<<h<<' ';
    cout<<endl;*/
    int sz=b.size();
    vector <int> res=slv(sz,0);
    int z=1;
    for(int i=b.size();i<n;++i) {z*=2;z%=p;}
    for(auto h:res) cout<<(h*z)%p<<' ';
    return 0;
}