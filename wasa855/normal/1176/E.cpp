#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    int ans=0;
    while(isdigit(ch))
    {
        ans=ans*10+ch-48;
        ch=getchar();
    }
    return ans;
}
#define N 200005
struct Edge
{
    int to,nxt;
};
Edge edge[N*2];
int fir[N],ss;
void add(int u,int v)
{
    ss++; edge[ss].to=v; edge[ss].nxt=fir[u]; fir[u]=ss;
    ss++; edge[ss].to=u; edge[ss].nxt=fir[v]; fir[v]=ss;
}
int dep[N];
void bfs()
{
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=fir[u];i!=0;i=edge[i].nxt)
        {
            int to=edge[i].to;
            if(dep[to]!=0) continue;
            dep[to]=dep[u]+1;
            q.push(to);
        }
    }
}
void work()
{
    ss=0;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fir[i]=0;
        dep[i]=0;
    }
    int u,v;
    for(int i=1;i<=m;i++)
    {
        u=read(),v=read();
        add(u,v);
    }
    bfs();
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(dep[i]%2==1) sum++;
    }
    if(sum<=n/2)
    {
        cout<<sum<<endl;
        for(int i=1;i<=n;i++)
        {
            if(dep[i]%2==1) cout<<i<<" ";
        }
        cout<<"\n";
    }
    else
    {
        cout<<n-sum<<endl;
        for(int i=1;i<=n;i++)
        {
            if(dep[i]%2==0) cout<<i<<" ";
        }
        cout<<"\n";
    }
}
signed main()
{
    int T;
    cin>>T;
    while(T--) work();
    return 0;
}
//svcuinryiudrs