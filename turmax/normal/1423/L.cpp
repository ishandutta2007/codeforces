#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define int long long
unordered_map <int,int> z1;
const int cnt=63;
const int cnt2=16;
int w[100];
int has(vector <int> v)
{
    int ans=0;
    for(int i=0;i<cnt2;++i)
    {
        ans+=v[i]*w[i];
    }
    return ans;
}
int po[64];
vector <int> nv;
vector <int> go(vector <int> v)
{
    vector <int> ans;
    for(int i=0;i<cnt2;++i)
    {
        ans.push_back(0);
    }
    for(auto h:v)
    {
        h--;
        ans[h/cnt]+=po[h%cnt];
    }
    return ans;
}
vector <int> to(vector <int> a,vector <int> b)
{
    vector <int> c(cnt2);
    for(int i=0;i<cnt2;++i) c[i]=a[i]^b[i];
    return c;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<100;++i) w[i]=rand()*1e9+rand();
    int u1=1;
    for(int i=0;i<64;++i)
    {
        po[i]=u1;
        u1*=2;
    }
    for(int i=0;i<cnt2;++i) nv.push_back(0);
    int n,s,d;
    cin>>n>>s>>d;
    vector <vector <int> > v;
    for(int i=0;i<s;++i)
    {
        int c;
        cin>>c;
        vector <int> h(c);
        for(int i=0;i<c;++i) cin>>h[i];
        v.push_back(go(h));
    }
    vector <vector<int> > v1,v2;
    for(int i=0;i<(s/2);++i) v1.push_back(v[i]);
    for(int i=(s/2);i<s;++i) v2.push_back(v[i]);
    vector <vector <int> > l1;
    vector <int> l0;
    for(int mask=0;mask<(1<<v1.size());++mask)
    {
        vector <int> u=nv;
        for(int i=0;i<v1.size();++i)
        {
            if(mask & (1<<i))
            {
                u=to(u,v1[i]);
            }
        }
        l1.push_back(u);
        l0.push_back(__builtin_popcount(mask));
    }
    for(int mask=0;mask<(1<<v2.size());++mask)
    {
        vector <int> u=nv;
        for(int i=0;i<v2.size();++i)
        {
            if(mask & (1<<i))
            {
                u=to(u,v2[i]);
            }
        }
        int ha=has(u);
        if(z1.count(ha)) z1[ha]=min(z1[ha],(int) __builtin_popcount(mask));
        else z1[ha]=__builtin_popcount(mask);
    }
    for(int i=0;i<d;++i)
    {
        int c;
        cin>>c;
        vector <int> h(c);
        for(int i=0;i<c;++i) cin>>h[i];
        vector <int> z=go(h);
        int ans=1e18;
        for(int i=0;i<l1.size();++i)
        {
            int has1=0;
            for(int j=0;j<cnt2;++j)
            {
                has1+=(l1[i][j]^z[j])*w[j];
            }
            if(z1.count(has1))
                ans=min(ans,z1[has1]+l0[i]);
        }
        if(ans==1e18) cout<<(-1)<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}