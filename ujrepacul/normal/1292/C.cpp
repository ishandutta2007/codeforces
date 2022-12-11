#include <bits/stdc++.h>
using namespace std;
vector <long long> v[3003];
long long viz[3003],n;
long long sz[3003],k,poz[3003];
long long dp[3003][3003];
void dfsinit (long long pz)
{
    sz[pz]=1;
    poz[pz]=++k;
    viz[pz]=1;
    for(long long i=0;i<v[pz].size();++i)
    {
        if(!viz[v[pz][i]])
        {
            dfsinit(v[pz][i]);
            sz[pz]+=sz[v[pz][i]];
        }
    }
}
long long cat (long long a, long long ta)
{
    if(poz[ta]<poz[a])
        return sz[a];
    else
        return n-sz[ta];
}
long long dfs (long long a, long long ta, long long b, long long tb)
{
    if(dp[a][b]!=0)
        return dp[a][b];
    long long rzc=0;
    rzc=cat(a,ta)*cat(b,tb);
    long long mx=0;
    for(long long i=0;i<v[a].size();++i)
        if(v[a][i]!=ta)
            mx=max(mx,dfs(v[a][i],a,b,tb));
    for(long long i=0;i<v[b].size();++i)
        if(v[b][i]!=tb)
            mx=max(mx,dfs(a,ta,v[b][i],b));
    dp[a][b]=dp[b][a]=mx+rzc;
    return mx+rzc;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j=0;
    long long mx=0;
    cin>>n;
    for(i=1;i<n;++i)
    {
        long long a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfsinit(1);
    for(i=1;i<=n;++i)
    {
        for(long long j=0;j<v[i].size();++j)
            if(viz[v[i][j]]==1)
                mx=max(mx,dfs(i,v[i][j],v[i][j],i));
        viz[i]=2;
    }
    cout<<mx;
    return 0;
}