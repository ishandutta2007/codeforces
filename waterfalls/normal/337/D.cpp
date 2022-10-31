#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,d,colored;
int p[100000];
int visited[100000];
int maxTot[100000];
vector<int> maxD[100000];
vector<int> adj[100000];

void pull_up(int x) {
    visited[x] = 1;
    for (int j=0;j<adj[x].size();j++) {
        int i = adj[x][j];
        if (visited[i]) continue;
        pull_up(i);
        maxD[x][j] = max(maxD[x][j],1+maxTot[i]);
        maxTot[x] = max(maxTot[x],maxD[x][j]);
    }
}

void push_down(int x) {
    visited[x] = 1;
    int best = 0;
    for (int i=0;i<adj[x].size();i++) if (maxD[x][i]>maxD[x][best]) best = i;
    if (x==0 && adj[x].size()==1) {
        if (colored) {
            int next = adj[x][0];
            int which;
            for (which=0;which<adj[next].size();which++) if (adj[next][which]==0) break;
            maxD[next][which] = max(maxD[next][which],1);
            maxTot[next] = max(maxTot[next],1);
        }
    }
    for (int j=0;j<adj[x].size();j++) {
        int i = adj[x][j];
        if (visited[i]) continue;
        int which;
        for (which=0;which<adj[i].size();which++) if (adj[i][which]==x) break;
        if (j!=best) {
            maxD[i][which] = max(maxD[i][which],1+maxD[x][best]);
            maxTot[i] = max(maxTot[i],maxD[i][which]);
        } else if (x!=0 || adj[x].size()>1) {
            int second = 0;
            if (best==0) second+=1;
            for (int f=0;f<adj[x].size();f++) if (f!=j && maxD[x][f]>maxD[x][second]) second = f;
            maxD[i][which] = max(maxD[i][which],1+maxD[x][second]);
            maxTot[i] = max(maxTot[i],maxD[i][which]);
        }
        push_down(i);
    }
}

int main() {
    scanf("%d%d%d",&n,&m,&d);
    for (int i=0;i<m;i++) scanf("%d",&p[i]);
    for (int i=0;i<n-1;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a-=1; b-=1;
        adj[a].push_back(b);
        adj[b].push_back(a);
        maxD[a].push_back(-10000000);
        maxD[b].push_back(-10000000);
    }
    for (int i=0;i<n;i++) maxTot[i] = -10000000;
    colored = 0;
    for (int i=0;i<m;i++) {
        for (int j=0;j<adj[p[i]-1].size();j++) maxD[p[i]-1][j] = 0;
        maxTot[p[i]-1] = 0;
        if (p[i]-1==0) colored = 1;
    }
    for (int i=0;i<n;i++) visited[i] = 0;
    pull_up(0);
    for (int i=0;i<n;i++) visited[i] = 0;
    push_down(0);
    int ans = 0;
    for (int i=0;i<n;i++) if (maxTot[i]<=d) ans+=1;
    printf("%d\n",ans);

    return 0;
}