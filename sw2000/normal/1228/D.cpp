#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm=3e5+10;
const int maxn=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;

int u[maxm],v[maxm];
vector<int>to[maxn];
int ans[maxn];
bool vis[maxn];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        to[u[i]].push_back(v[i]);
        to[v[i]].push_back(u[i]);
    }
    for(int i=0;i<to[1].size();i++)
    {
        vis[to[1][i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])ans[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(!ans[i])
        {
            for(int j=0;j<to[i].size();j++)
            {
                if(vis[to[i][j]])ans[to[i][j]]=3;
            }
            break;
        }
    }
    ll c[3]={0};
    for(int i=1;i<=n;i++)
    {
        if(!ans[i])ans[i]=2;
        c[ans[i]-1]++;
    }
    for(int i=0;i<3;i++)
    {
        if(c[i]==0)
        {
            cout<<-1;
            return 0;
        }
    }
    if(c[0]*c[1]+c[0]*c[2]+c[1]*c[2]!=m)
    {
        cout<<-1;
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        if(ans[v[i]]==ans[u[i]])
        {
            cout<<-1;
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",ans[i]);
    }

    return 0;
}