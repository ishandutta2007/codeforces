#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MP make_pair
#define A first
#define B second

using namespace std;

int n,m,u;
vector<pair<int,pair<int,int> > > adj[300013];
pair<long long,int> best[300013];
int done[3000013];
priority_queue<pair<pair<long long,int>,pair<int,int> > > frontier;
vector<int> edges;

int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) best[i].A = 1e18;
    for (int i=1;i<=m;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back(MP(b,MP(c,i)));
        adj[b].push_back(MP(a,MP(c,i)));
    }
    scanf("%d",&u);
    long long ans = 0;
    best[u] = MP(0,0);
    frontier.push(MP(MP(0,0),MP(u,0)));
    while (frontier.size()>0) {
        int x = frontier.top().B.A;
        int which = frontier.top().B.B;
        frontier.pop();
        if (done[x]) continue;
        ans+=best[x].B;
        done[x] = 1;
        if (which) edges.push_back(which);
        for (int i=0;i<adj[x].size();i++) {
            if (done[adj[x][i].A]) continue;
            if (MP(best[x].A+adj[x][i].B.A,adj[x][i].B.A)<best[adj[x][i].A]) {
                best[adj[x][i].A] = MP(best[x].A+adj[x][i].B.A,adj[x][i].B.A);
                frontier.push(MP(MP(-best[adj[x][i].A].A,-best[adj[x][i].A].B),MP(adj[x][i].A,adj[x][i].B.B)));
            }
        }
    }
    printf("%I64d\n",ans);
    for (int i=0;i<edges.size();i++) printf("%d ",edges[i]);
    printf("\n");

    return 0;
}