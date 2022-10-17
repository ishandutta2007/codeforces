#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

pair<int, int> es[500005];
bool vis[300005],vis2[300005];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=3*n;++i) vis[i]=0;
        ij vis2[i]=0;
        ij
        {
            int u,v;
            cin>>u>>v;
            es[i]={u,v};
        }
        int cnt=0;
        ij
        {
            int u=es[i].first,v=es[i].second;
            if(vis[u] || vis[v]) continue;
            else
            {
                cnt++;
                vis[u]=vis[v]=1;
                vis2[i]=1;
            }
        }
        int k=n;
        if(cnt>=n)
        {
            cout<<"Matching"<<endl;
            for(int i=1;i<=m;++i)
            {
                if(vis2[i])
                {
                    cout<<i<<" ";
                    if(--k == 0) break;
                }
            }
        }
        else
        {
            cout<<"IndSet"<<endl;
            for(int i=1;i<=3*n;++i)
            {
                if(!vis[i])
                {
                    cout<<i<<" ";
                    if(--k == 0) break;
                }
            }
        }
        cout<<endl;
    }
}