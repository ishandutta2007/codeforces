#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,s1,t1,l1,s2,t2,l2;
vector<int> adj[3000];
int dist[3000][3000];
queue<int> frontier;

void solve(int x) {
    dist[x][x] = 0;
    frontier.push(x);
    while (frontier.size()>0) {
        int next = frontier.front(); frontier.pop();
        for (int i=0;i<adj[next].size();i++) if (dist[x][adj[next][i]]==10000) {
            frontier.push(adj[next][i]);
            dist[x][adj[next][i]] = dist[x][next]+1;
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a-=1; b-=1;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) dist[i][j] = 10000;
    for (int i=0;i<n;i++) solve(i);
    scanf("%d%d%d%d%d%d",&s1,&t1,&l1,&s2,&t2,&l2);
    s1-=1; t1-=1; s2-=1; t2-=1;
    if (dist[s1][t1]>l1 || dist[s2][t2]>l2) printf("-1\n");
    else {
        int ans = dist[s1][t1]+dist[s2][t2];
        for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
            if (dist[s1][i]+dist[i][j]+dist[j][t1]<=l1 && dist[s2][i]+dist[i][j]+dist[j][t2]<=l2) {
                ans = min(ans,dist[s1][i]+dist[s2][i]+dist[i][j]+dist[j][t1]+dist[j][t2]);
            }
        }
        swap(s2,t2);
        for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
            if (dist[s1][i]+dist[i][j]+dist[j][t1]<=l1 && dist[s2][i]+dist[i][j]+dist[j][t2]<=l2) {
                ans = min(ans,dist[s1][i]+dist[s2][i]+dist[i][j]+dist[j][t1]+dist[j][t2]);
            }
        }
        printf("%d\n",m-ans);
    }

    return 0;
}