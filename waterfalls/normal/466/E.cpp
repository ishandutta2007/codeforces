#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int p[100000];
int h[100000];
int queries[100000][3];
vector<pair<int,int> > type3[100000];
vector<int> adj[100000];
int visited[100000];
vector<int> who;
int top[100000];
int ok[100000];
vector<pair<int,int> > need[100000];
int which[100000];

int findSet(int x) {
    if (p[x]==x) return x;
    return p[x] = findSet(p[x]);
}

void mergeSet(int x, int y) {
    int r1 = findSet(x);
    int r2 = findSet(y);
    if (h[r1]>h[r2]) p[r2] = r1;
    else if (h[r2]>h[r1]) p[r1] = r2;
    else {
        p[r1] = r2;
        h[r2]+=1;
    }
}

bool sameSet(int x, int y) { return findSet(x)==findSet(y); }

void dfs(int x) {
    visited[x] = 1;
    for (int i=0;i<type3[x].size();i++) if (visited[type3[x][i].first]==1) ok[type3[x][i].second] = 1;
    for (int i=0;i<adj[x].size();i++) if (!visited[adj[x][i]]) dfs(adj[x][i]);
    visited[x] = 2;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) {
        top[i] = 1;
        p[i] = i;
    }
    for (int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&queries[i][0],&a);
        if (queries[i][0]!=2) scanf("%d",&b);
        queries[i][1] = a-1;
        queries[i][2] = b-1;
        if (queries[i][0]==1) {
            adj[b-1].push_back(a-1);
            top[a-1] = 0;
        }
        if (queries[i][0]==2) {
            who.push_back(a-1);
            which[who.size()-1] = i;
        }
        if (queries[i][0]==3) {
            type3[who[b-1]].push_back(make_pair(a-1,i));
            need[which[b-1]].push_back(make_pair(a-1,i));
        }
    }
    for (int i=0;i<n;i++) if (top[i]) dfs(i);
    for (int i=0;i<m;i++) {
        if (queries[i][0]==1) mergeSet(queries[i][1],queries[i][2]);
        if (queries[i][0]==2) for (int j=0;j<need[i].size();j++) if (!sameSet(queries[i][1],need[i][j].first)) ok[need[i][j].second] = 0;
        if (queries[i][0]==3) {
            if (ok[i]) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}