#include <bits/stdc++.h>

using namespace std;
#define int long long
int dp[1<<18];
int sumweight[1<<18];
bool check[1<<18];
int rebr[1<<18];
bool is[18][18];
bool is1[18][18];
int pr[1<<18];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    pair <int,int> a[m];
    int b[n];
    for(int i=0;i<n;++i) b[i]=0;
    for(int i=0;i<m;++i)
    {
        cin>>a[i].first>>a[i].second;
        swap(a[i].first,a[i].second);
        a[i].first--;a[i].second--;
        is[a[i].first][a[i].second]=true;
        is1[a[i].second][a[i].first]=true;
        is[a[i].second][a[i].first]=true;
        int w;
        cin>>w;
        b[a[i].second]+=w;b[a[i].first]-=w;
    }
    int sz=(1<<n);
    for(int mask=0;mask<sz;++mask)
    {
        sumweight[mask]=0;
        for(int i=0;i<n;++i)
        {
            if(mask & (1<<i))
            {
                sumweight[mask]+=b[i];
            }
        }
    }
    for(int mask=0;mask<sz;++mask)
    {
        rebr[mask]=0;
        for(int i=0;i<n;++i)
        {
            if(mask & (1<<i))
            {
                for(int j=0;j<n;++j)
                {
                    if(is1[i][j])
                    {
                        rebr[mask] |= (1<<j);
                    }
                }
            }
        }
    }
    for(int mask=0;mask<sz;++mask)
    {
        check[mask]=true;
        for(int i=0;i<n;++i)
        {
        for(int j=0;j<i;++j)
        {
            if((mask & (1<<i)) && (mask & (1<<j)))
            {
                if(is[i][j])
                {
                    check[mask]=false;
                }
            }
        }
        }
    }
    for(int mask=0;mask<sz;++mask)
    {
        if(mask==0)
        {
            dp[mask]=0;
            continue;
        }
        dp[mask]=1e18;
        for(int mask2=mask;;mask2=(mask2-1) & mask)
        {
            if(check[mask2] && !((mask^mask2) & rebr[mask2]))
            {
                if((dp[mask^mask2]+sumweight[mask]-sumweight[mask2])<dp[mask])
                {
                    pr[mask]=mask2;
                    dp[mask]=dp[mask^mask2]+sumweight[mask]-sumweight[mask2];
                }
            }
            if(mask2==0)
            {
                break;
            }
        }
    }
    int res[n];
    int curr=0;
    int u=(sz-1);
    while(u!=0)
    {
        int x=pr[u];
        for(int i=0;i<n;++i)
        {
            if(x & (1<<i))
            {
                res[i]=curr;
            }
        }
        ++curr;
        u=u^x;
    }
    for(int i=0;i<n;++i) cout<<res[i]<<' ';
    return 0;
}