#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;vector<int> g[n];
        int s,t;cin>>s>>t;--s;--t;
        for(int i=0;i<m;++i) {int x,y;cin>>x>>y;--x;--y;g[x].push_back(y);g[y].push_back(x);}
        int dist1[n+1];for(int i=0;i<=n;++i) dist1[i]=1e9;int dist2[n+1];for(int i=0;i<=n;++i) dist2[i]=1e9;
        queue<int> q;q.push(s);int cnt1[n+1]={0};int cnt2[n+1]={0};cnt1[s]=1;dist1[s]=0;
        while(!q.empty())
        {
            int x=q.front();q.pop();
            for(int v:g[x]) {
                    if(dist1[v]==dist1[x]+1)
                    {
                        cnt1[v]+=cnt1[x];cnt1[v]%=p;
                    }
                else if(dist1[v]==1e9)
                {
                    dist1[v]=dist1[x]+1;
                    cnt1[v]+=cnt1[x];cnt1[v]%=p;
                    q.push(v);
                }
            }
        }
        q.push(t);cnt2[t]=1;dist2[t]=0;
        while(!q.empty())
        {
            int x=q.front();q.pop();
            for(int v:g[x]) {
                    if(dist2[v]==dist2[x]+1)
                    {
                        cnt2[v]+=cnt2[x];cnt2[v]%=p;
                    }
                else if(dist2[v]==1e9)
                {
                    dist2[v]=dist2[x]+1;
                    cnt2[v]=cnt2[x];
                    q.push(v);
                }
            }
        }
        int ans1=dist1[t];
        int ans=cnt1[t];
        for(int i=0;i<n;++i)
        {
            for(int v:g[i])
            {
                if(dist1[i]+dist2[v]==ans1 && dist1[i]+dist2[i]==ans1)
                {
                    ans+=(cnt1[i]*cnt2[v]);ans%=p;
                }
            }
        }
        cout<<(ans%p+p)%p<<'\n';
    }
    return 0;
}