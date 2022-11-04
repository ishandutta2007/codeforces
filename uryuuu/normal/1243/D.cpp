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
const ll Mod=1e9+7;

const int maxn=100010;
set<int>g[maxn],s;
int vis[maxn];
void bfs(int x)
{
    queue<int>q;
    q.push(x);
    s.erase(x);
    while(q.size()>0)
    {
        int y=q.front();
        q.pop();
        if(vis[y])
            continue;
        vis[y]=1;
        for(auto it=s.begin();it!=s.end();)
        {
            int v=*it;
            it++;
            if(g[y].find(v)==g[y].end())
            {
                q.push(v);
                s.erase(v);
            }
        }
    }
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        s.insert(i);
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].insert(y);
        g[y].insert(x);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            bfs(i);
            ans++;
        }
    }
    cout<<ans-1<<endl;
    return 0;
}