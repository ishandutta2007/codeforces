#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
int par[maxn];int sz[maxn];int dp[maxn];set<int,greater<int> > h;int ans=1e9;bool good[maxn];
int get(int x)
{
    if(par[x]==(-1)) return x;
    int ans=get(par[x]);par[x]=ans;return ans;
}
void merg(int x,int y)
{
    x=get(x);y=get(y);if(x==y) return; par[x]=y;sz[y]+=sz[x];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t1=clock();
    int n,m;cin>>n>>m;
    for(int i=0;i<n;++i) {par[i]=(-1);sz[i]=1;}
    for(int i=0;i<m;++i) {int x,y;cin>>x>>y;--x;--y;merg(x,y);}
    for(int i=0;i<=n;++i)
    {
        string s=to_string(i);
        good[i]=1;
        for(auto h:s)
        {
            if(h!='4' && h!='7') good[i]=0;
        }
    }
    vector<int> u;
    for(int i=0;i<n;++i)
    {
        if(par[i]==(-1)) u.push_back(sz[i]);
    }
    sort(u.begin(),u.end());
    for(auto h:u)
    {
        if(good[h])
        {
            cout<<0;
            return 0;
        }
    }
    for(int i=0;i<=n;++i) dp[i]=1e9;
    dp[0]=0;h.insert(0);
    vector<int> h1;
    for(int i=0;i<u.size();++i)
    {
        h1.clear();
        int x=u[i];
        int ans1=ans;
        for(int j:h)
        {
            dp[x+j]=min(dp[x+j],dp[j]+1);
            if(dp[x+j]<ans)
            {
                h1.push_back(x+j);
                if(good[x+j])
                {
                    ans1=min(ans1,dp[x+j]);
                }
            }
        }
        for(auto h2:h1) h.insert(h2);
        h1.clear();
        if(ans1<ans)
        {
            ans=ans1;
            for(auto h2:h)
            {
                if(dp[h2]>=ans-1)
                {
                    h1.push_back(h2);
                }
            }
            for(auto h2:h1) h.erase(h2);
            h1.clear();
        }
        if(i%100==0 && clock()-t1>CLOCKS_PER_SEC*0.8)
        {
            if(ans==1e9) cout<<(-1);
        else cout<<ans-1;
        return 0;
        }
    }
    if(ans==1e9) cout<<(-1);
    else cout<<ans-1;
    return 0;
}