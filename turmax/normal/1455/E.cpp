#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx","avx2","fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#include <bits/stdc++.h>

using namespace std;
#define int long long
int abs1(int x,int y)
{
    if(x>=y) return (x-y);
    return (y-x);
}
long long go(vector <int> x1,vector <int> y1,int x,int y,int t)
{
    if(t<0 || x<0 || y<0) return 1e18;
    pair <int,int> v[4];
    for(int i=0;i<4;++i) v[i]={x1[i],y1[i]};
    sort(v,v+4);
    long long sum=0;
    sum+=abs1(v[0].first,x)+abs1(v[0].second,y);
    sum+=abs1(v[1].first,x+t)+abs1(v[1].second,y);
    sum+=abs1(v[2].first,x)+abs1(v[2].second,y+t);
    sum+=abs1(v[3].first,x+t)+abs1(v[3].second,y+t);
    long long ans=sum;
    while(next_permutation(v,v+4))
    {
        if(v[2].first>v[3].first) continue;
        if(v[1].first<v[0].first) continue;
        if(v[3].second<v[1].second) continue;
        if(v[2].second<v[0].second) continue;
        sum=0;
        sum+=abs1(v[0].first,x)+abs1(v[0].second,y);
        sum+=abs1(v[1].first,x+t)+abs1(v[1].second,y);
        sum+=abs1(v[2].first,x)+abs1(v[2].second,y+t);
        sum+=abs1(v[3].first,x+t)+abs1(v[3].second,y+t);
        ans=min(ans,sum);
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    srand(getpid());
    int t;
    cin>>t;
    while(t--)
    {
        vector <int> x1(4);vector <int> y1(4);
        for(int i=0;i<4;++i) cin>>x1[i]>>y1[i];
        long long ans=1e18;
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<4;++j)
            {
                int x=x1[i];
                int y=y1[j];
                for(int k=0;k<4;++k)
                {
                    if(k==i) continue;
                    int t=(x1[k]-x);
                    ans=min(ans,go(x1,y1,x,y,t));
                }
                for(int k=0;k<4;++k)
                {
                    if(k==j) continue;
                    int t=(y1[k]-y);
                    ans=min(ans,go(x1,y1,x,y,t));
                }
            }
        }
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<4;++j)
            {
                int x=x1[i];
                if(i==j) continue;
                int t=x1[j]-x;
                for(int k=0;k<4;++k)
                {
                    int y=(y1[k]-t);
                    ans=min(ans,go(x1,y1,x,y,t));
                }
            }
        }
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<4;++j)
            {
                if(i==j) continue;
                int y=y1[i];
                int t=y1[j]-y;
                for(int k=0;k<4;++k)
                {
                    int x=(x1[k]-t);
                    ans=min(ans,go(x1,y1,x,y,t));
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}