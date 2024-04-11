#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<set>
#include<queue>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;
ll c[4][maxn],s[maxn],a[maxn],b[maxn],w[maxn];

vector<int>g[maxn];
int cnt=0;
void dfs(int v,int fa)
{
    a[cnt++]=v;
    for(int i=0;i<g[v].size();i++)
    {
        int u=g[v][i];
        if(u==fa)
            continue;
        dfs(u,v);
    }
}
int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=0;i<3;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>c[i][j];
    }
    int u,v;
    int st=0;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++)
    {
        if(g[i].size()>2)
        {
            cout<<-1<<endl;
            return 0;
        }
        if(g[i].size()==1)
            st=i;
    }
    cnt=1;
    dfs(st,0);
    int d1=0,d2=1;
    ll ans=2e18;
    ll sum=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            sum=0;
            if(i==j)
                continue;
            int x=i,y=j,z=3-i-j;
            sum+=c[i][a[1]]+c[j][a[2]];
            for(int k=3;k<=n;k++)
            {
                z=3-x-y;
                sum+=c[z][a[k]];
                x=y;
                y=z;
            }
            if(sum<ans)
            {
                ans=sum;
                d1=i;
                d2=j;
            }
        }
    }
    cout<<ans<<endl;
    w[a[1]]=d1;
    w[a[2]]=d2;
    int x=d1,y=d2,z=3-x-y;
    for(int i=3;i<=n;i++)
    {
        z=3-x-y;
        w[a[i]]=z;
        x=y;
        y=z;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<w[i]+1<<' ';
    }
    cout<<endl;
    return 0;
}