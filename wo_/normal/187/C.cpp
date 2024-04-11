#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

const int inf=1<<29;

struct UnionFind{
    int par[100100],rank[100100];
    void init(int N)
    {
        for(int i=0;i<N;i++)
        {
            par[i]=i;
            rank[i]=0;
        }
    }
    int find(int x)
    {
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    void unite(int x,int y)
    {
        x=find(x),y=find(y);
        if(x==y) return;
        if(rank[x]<rank[y]) par[x]=y;
        else par[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
    bool same(int x,int y)
    {
        return find(x)==find(y);
    }
};

int dis[100100],root[100100];

vector<int> G[100100];

UnionFind uf;

vector<int> marked;
int N,M,K;
int s,t;

bool judge(int q)
{
    uf.init(N);
    for(int i=0;i<N;i++)
    {
        dis[i]=inf;
        root[i]=-1;
    }
    queue<P> que;
    for(int i=0;i<marked.size();i++)
    {
        dis[marked[i]]=0;
        root[marked[i]]=marked[i];
        que.push(P(0,marked[i]));
    }
    int m=(q+1)/2;
    while(!que.empty())
    {
        P p=que.front();
        que.pop();
        int d=p.first,v=p.second;
        int r=root[v];
        if(dis[v]<d) continue;
        if(d>=m) continue;
        for(int i=0;i<G[v].size();i++)
        {
            int nv=G[v][i];
            int nd=d+1;
            if(dis[nv]+nd<=q)
            {
                uf.unite(r,root[nv]);
            }
            if(dis[nv]<=nd) continue;
            dis[nv]=nd;
            root[nv]=r;
            que.push(P(nd,nv));
        }
    }
    return uf.same(s,t);
}

int main()
{
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0;i<K;i++)
    {
        int v;
        scanf("%d",&v);
        v--;
        marked.push_back(v);
    }
    for(int i=0;i<M;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    scanf("%d%d",&s,&t);
    s--;t--;
    marked.push_back(s),marked.push_back(t);
    sort(marked.begin(),marked.end());
    marked.erase(unique(marked.begin(),marked.end()),marked.end());
    int ub=M+2,lb=0;
    while(ub-lb>1)
    {
        int mid=(ub+lb)/2;
        if(judge(mid))
        {
            ub=mid;
        }
        else lb=mid;
    }
    if(ub<=M) printf("%d\n",ub);
    else printf("-1\n");
    return 0;
}