#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Scayger { int x,y,t; };

int n,m,a,b;
char grid[25][25];
vector<Scayger> scaygers;

queue<int> frontier;
long long dist[1000][500];
int dX[4] = {-1,0,1,0};
int dY[4] = {0,-1,0,1};

const int source = 0;
const int sink = 1;
vector<int> adj[2000];
int res[2000][2000];
int visited[2000];

void solve(int id) {
    Scayger which = scaygers[id];
    for (int i=0;i<n*m;i++) dist[id][i] = 1000000000000000000LL;
    dist[id][which.x*m+which.y] = 0;
    frontier.push(which.x*m+which.y);
    while (frontier.size()>0) {
        int next = frontier.front();
        frontier.pop();
        for (int i=0;i<4;i++) {
            int nX = next/m+dX[i];
            int nY = next%m+dY[i];
            if (nX>=0 && nX<n && nY>=0 && nY<m && grid[nX][nY]=='.' && dist[id][nX*m+nY]==1000000000000000000LL) {
                dist[id][nX*m+nY] = dist[id][next]+which.t;
                frontier.push(nX*m+nY);
            }
        }
    }
}

void connect(int a, int b) { adj[a].push_back(b); adj[b].push_back(a); res[a][b] = 1; }
bool dfs(int x) {
    visited[x] = 1;
    if (x==1) return true;
    for (int i=0;i<adj[x].size();i++) {
        if (!visited[adj[x][i]] && res[x][adj[x][i]] && dfs(adj[x][i])) {
            res[x][adj[x][i]]-=1;
            res[adj[x][i]][x]+=1;
            return true;
        }
    }
    return false;
}

bool check(long long time) {
    for (int i=0;i<2+2*a+2*n*m;i++) for (int j=0;j<2+2*a+2*n*m;j++) res[i][j] = 0;
    for (int i=0;i<2+2*a+2*n*m;i++) adj[i].clear();
    for (int i=2;i<2+a;i++) connect(0,i);
    for (int i=2+a;i<2+2*a;i++) connect(i,1);
    for (int j=0;j<n*m;j++) connect(2+2*a+j,2+2*a+n*m+j);
    for (int i=2;i<2+a;i++) for (int j=0;j<n*m;j++) if (dist[i][j]<=time) connect(i,2+2*a+j);
    for (int i=2+a;i<2+2*a;i++) for (int j=0;j<n*m;j++) if (dist[i][j]<=time) connect(2+2*a+n*m+j,i);
    int flow = 0;
    while (true) {
        for (int i=0;i<2+2*a+2*n*m;i++) visited[i] = 0;
        if (dfs(0)) flow+=1;
        else break;
    }
    return flow==a;
}

int main() {
    scanf("%d%d%d%d",&n,&m,&a,&b);
    if (abs(a-b)!=1) return printf("-1\n"),0;
    for (int i=0;i<n;i++) scanf(" %s",&grid[i]);
    scaygers.push_back(Scayger());
    scaygers.push_back(Scayger());
    Scayger boss;
    scanf("%d%d%d",&boss.x,&boss.y,&boss.t);
    boss.x-=1; boss.y-=1;
    if (a<b) scaygers.push_back(boss);
    for (int i=0;i<a;i++) {
        Scayger next;
        scanf("%d%d%d",&next.x,&next.y,&next.t);
        next.x-=1; next.y-=1;
        scaygers.push_back(next);
    }
    if (b<a) scaygers.push_back(boss);
    for (int i=0;i<b;i++) {
        Scayger next;
        scanf("%d%d%d",&next.x,&next.y,&next.t);
        next.x-=1; next.y-=1;
        scaygers.push_back(next);
    }
    a = max(a,b);
    for (int i=2;i<2+2*a;i++) solve(i);
    long long low = -1;
    long long high = 1000000000000000LL;
    while (high-low>1) {
        if (check((low+high+1)/2)) high = (low+high+1)/2;
        else low = (low+high+1)/2;
    }
    if (high==1000000000000000LL) printf("-1\n");
    else printf("%I64d\n",high);

    return 0;
}