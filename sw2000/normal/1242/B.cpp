#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;

set<int>in[maxn],s;

void bfs(int o)
{
    s.erase(o);
    queue<int>q;q.push(o);
    while(!q.empty())
    {
        vector<int>v;
        int x=q.front();q.pop();
        for(auto i:s)
        {
            if(!in[x].count(i))
            {
                q.push(i);
                v.push_back(i);
            }
        }
        for(auto i:v)
        {
            s.erase(i);
        }
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        in[a].insert(b);
        in[b].insert(a);
    }
    for(int i=1;i<=n;i++)
    {
        s.insert(i);
    }

    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        if(s.count(i))
        {
            ans++;
            bfs(i);
        }
    }
    printf("%d",ans);
}