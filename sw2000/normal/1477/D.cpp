#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=5e5+10;

unordered_set<int>edg[N],ans[N];
vector<int>edg2[N];
int p[N],q[N],father[N],n,m;
void solve()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edg[a].insert(b);
        edg[b].insert(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(edg[i].size()!=n-1)father[i]=i;
        else father[i]=0;
    }

    for(int i=1;i<=n;i++)if(father[i]==i&&edg2[i].empty())
    {
        for(int j=1;j<=n;j++)if(j!=i&&father[j]==j)
        {
            if(!edg[i].count(j))
            {
//                cout<<i<<' '<<j<<endl;
                edg2[i].push_back(j);
                edg2[j].push_back(i);
                break;
            }
        }
    }

    for(int i=1;i<=n;i++)if(ans[i].empty()&&father[i]==i)
    {
        for(auto j:edg2[i])if(father[j]==j)
        {
            ans[i].insert(j);
            father[j]=i;
        }

        if(ans[i].empty())
        {
            int u=edg2[i][0];
            ans[father[u]].erase(u);
            father[u]=u;
            for(int v:edg2[u])if(ans[v].empty()&&father[v]==v)
            {
                ans[u].insert(v);
                father[v]=u;
            }
        }
//        cout<<i<<' '<<ans[i].size()<<endl;
    }
//    for(int i=1;i<=n;i++)cout<<father[i]<<endl;

    int tot=0;
    for(int i=1;i<=n;i++)
    {
        if(!father[i])
        {
            p[i]=q[i]=++tot;
        }
        else if(ans[i].size())
        {
            p[i]=++tot;
            for(auto j:ans[i])
            {
//                cout<<i<<' '<<j<<endl;
                q[j]=tot;
                p[j]=++tot;
            }
            q[i]=tot;
        }
    }

    for(int i=1;i<=n;i++)cout<<p[i]<<' ';cout<<endl;
    for(int i=1;i<=n;i++)cout<<q[i]<<' ';cout<<endl;
    for(int i=1;i<=n;i++)
    {
        edg[i].clear();
        edg2[i].clear();
        ans[i].clear();
    }

}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)
        solve();
    return 0;
}