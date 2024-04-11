#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=1e5+5;
int e[maxn];
vector <int> z[maxn];
vector <int> g[maxn];
int cnt[maxn];
vector <int> d[maxn];
int ans=0;
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
            if(x!=(i*i)) v.push_back(x/i);
        }
    }
    return v;
}
int eul(vector <int> v)
{
    sort(v.begin(),v.end());
    int ans=1;
    for(int i=0;i<v.size();++i)
    {
        if(i==0 || v[i]!=v[i-1]) ans*=(v[i]-1);
        else ans*=v[i];
    }
    return ans;
}
int go(vector <int> o)
{
    vector <int> r;
    for(int i=0;i<o.size();++i)
    {
        for(auto h:d[o[i]+1])
        {
            if(!cnt[h])
            {
                r.push_back(h);
            }
            ++cnt[h];
        }
    }
    int ans=0;
    for(auto h:r) {ans+=cnt[h]*cnt[h]*e[h];ans%=p;cnt[h]=0;}
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=1;i<maxn;++i) {d[i]=del(i);z[i]=rasl(i);e[i]=eul(z[i]);}
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i)
    {
        vector <int> h=d[a[i]];
        for(auto h1:h)
        {
            g[h1].push_back(i);
        }
    }
    for(int i=1;i<maxn;++i)
    {
        vector <int> o=g[i];
        if(!o.empty())
        {
            int val=go(o);
            ans+=val*e[i];ans%=p;
        }
    }
    cout<<ans;
    return 0;
}