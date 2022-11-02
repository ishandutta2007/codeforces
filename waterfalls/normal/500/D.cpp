#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,q;
int roads[100000][3];
int changes[100000][2];
double sides[100000][2];
double ex[100000];
int visited[100000];
int sums[100000];
vector<vector<int> > adj;

int dfs(int x) {
    visited[x] = 1;
    int sum = 1;
    for (int i=0;i<adj[x].size();i++) if (!visited[adj[x][i]]) sum+=dfs(adj[x][i]);
    sums[x] = sum;
    return sum;
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) adj.push_back(vector<int>());
    for (int i=0;i<n-1;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        roads[i][0] = a-1;
        roads[i][1] = b-1;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
        roads[i][2] = c;
    }
    scanf("%d",&q);
    for (int i=0;i<q;i++) scanf("%d%d",&changes[i][0],&changes[i][1]);
    for (int i=0;i<n;i++) visited[i] = 0;
    dfs(0);
    for (int i=0;i<n-1;i++) {
        if (sums[roads[i][0]]>sums[roads[i][1]]) swap(roads[i][0],roads[i][1]);
        sides[i][0] = sums[roads[i][0]];
        sides[i][1] = n-sides[i][0];
    }
    double expect = 0;
    for (int i=0;i<n-1;i++) {
        ex[i] = (sides[i][0]*sides[i][1]*2)/n/(n-1)*3;
        expect+=roads[i][2]*ex[i];
    }
    for (int i=0;i<q;i++) {
        int which = changes[i][0]-1;
        expect-=ex[which]*(roads[which][2]-changes[i][1]);
        roads[which][2] = changes[i][1];
        printf("%1.12f\n",expect);
    }

    return 0;
}