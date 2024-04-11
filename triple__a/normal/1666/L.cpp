#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,s;
vector<int> G[MAXN];
bool vis[MAXN];
int pre[MAXN],belong[MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    queue<int> que;
    vis[s]=true;
    for(auto to:G[s])
    {
        belong[to]=to; pre[to]=s;
        vis[to]=true; que.push(to);
    }
    int x=-1,y=-1;
    while(que.size())
    {
        if(x!=-1) break;
        int v=que.front();
        que.pop();
        for(auto to:G[v])
        {
            if(to==s) continue;
            if(vis[to]&&pre[to]!=v&&belong[to]!=belong[v])
            {
                x=to; y=v;
                break;
            }
            else if(!vis[to])
            {
                vis[to]=true; pre[to]=v; belong[to]=belong[v];
                que.push(to);
            }
        }
    }
    if(x!=-1)
    {
        puts("Possible");
        vector<int> path1,path2;
        path2.push_back(x);
        while(y!=s)
        {
            path2.push_back(y);
            y=pre[y];
        }
        path2.push_back(s); reverse(path2.begin(),path2.end());
        while(x!=s)
        {
            path1.push_back(x);
            x=pre[x];
        }
        path1.push_back(s); reverse(path1.begin(),path1.end());
        printf("%d\n",(int)path1.size());
        for(auto x:path1) printf("%d ",x);
        puts("");
        printf("%d\n",(int)path2.size());
        for(auto x:path2) printf("%d ",x);
        puts("");
    }
    else puts("Impossible");
    return 0;
}