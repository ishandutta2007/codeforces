#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n,m,s,t,a,b;
int p[2013];
int road[2013][2013];
int visited[2013];
long long dist[2013][2];
set<long long> dsS,dtS;
vector<long long> ds,dt;
map<long long,int> dsM,dtM;
long long dp[2001][2001][2];
long long val[2001][2001];
long long sums[2001][2001];
int sums2[2001][2001];
long long best[2001][2];

void dij(int start, int which) {
    dist[start][which] = 0;
    for (int i=0;i<n;i++) {
        int best = -1;
        for (int j=0;j<n;j++) {
            if (visited[j]) continue;
            if (best==-1 || dist[j][which]<dist[best][which]) best = j;
        }
        visited[best] = 1;
        for (int j=0;j<n;j++) if (road[best][j]!=2147483647) {
            dist[j][which] = min(dist[j][which],dist[best][which]+road[best][j]);
        }
    }
}

int main() {
    scanf("%d%d%d%d",&n,&m,&s,&t);
    s-=1; t-=1;
    for (int i=0;i<n;i++) scanf("%d",&p[i]);
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) road[i][j] = 2147483647;
    for (int i=0;i<m;i++) {
        int v,u,w;
        scanf("%d%d%d",&v,&u,&w);
        v-=1; u-=1;
        if (v==u) continue;
        road[u][v] = min(road[u][v],w);
        road[v][u] = min(road[v][u],w);
    }
    for (int i=0;i<n;i++) dist[i][0] = 1000000000000000000LL, dist[i][1] = 1000000000000000000LL;
    dij(s,0);
    for (int i=0;i<n;i++) visited[i] = 0;
    dij(t,1);
    for (int i=0;i<n;i++) dsS.insert(dist[i][0]),dtS.insert(dist[i][1]);
    for (set<long long>::iterator it=dsS.begin();it!=dsS.end();it++) ds.push_back(*it);
    for (set<long long>::iterator it=dtS.begin();it!=dtS.end();it++) dt.push_back(*it);
    ds.insert(ds.begin(),-1); dt.insert(dt.begin(),-1);
    a = ds.size()-1;
    b = dt.size()-1;
    for (int i=0;i<=a;i++) dsM[ds[i]] = i;
    for (int i=0;i<=b;i++) dtM[dt[i]] = i;
    for (int i=0;i<n;i++) sums[dsM[dist[i][0]]][dtM[dist[i][1]]]+=p[i];
    for (int i=0;i<n;i++) sums2[dsM[dist[i][0]]][dtM[dist[i][1]]]+=1;
    for (int i=a;i>=0;i--) for (int j=b;j>=0;j--) {
        if (i!=a) sums[i][j]+=sums[i+1][j];
        if (j!=b) sums[i][j]+=sums[i][j+1];
        if (i!=a && j!=b) sums[i][j]-=sums[i+1][j+1];
        if (i!=a) sums2[i][j]+=sums2[i+1][j];
        if (j!=b) sums2[i][j]+=sums2[i][j+1];
        if (i!=a && j!=b) sums2[i][j]-=sums2[i+1][j+1];
    }
    for (int i=a-1;i>=0;i--) best[i][0] = sums[i+1][b];
    for (int j=b-1;j>=0;j--) best[j][1] = sums[a][j+1];
    for (int i=a-1;i>=0;i--) for (int j=b-1;j>=0;j--) {
        dp[i][j][0] = best[i][0];
        dp[i][j][1] = best[j][1];
        if (sums2[i+1][j]-sums2[i+1][j+1]) best[i][0] = sums[i+1][j]-sums[i+1][j+1]+max(best[i][0],sums[i+1][j+1]-dp[i][j][1]);
        if (sums2[i][j+1]-sums2[i+1][j+1]) best[j][1] = sums[i][j+1]-sums[i+1][j+1]+max(best[j][1],sums[i+1][j+1]-dp[i][j][0]);
    }
    long long tavas = dp[0][0][1];
    long long nafas = sums[0][0]-tavas;
    if (tavas<nafas) printf("Cry\n");
    if (tavas>nafas) printf("Break a heart\n");
    if (tavas==nafas) printf("Flowers\n");

    return 0;
}