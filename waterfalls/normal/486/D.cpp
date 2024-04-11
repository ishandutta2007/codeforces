#include <cstdio>
#include <vector>

using namespace std;

int d,n;
int a[2000];
int visited[2000];
vector<int> adj[2000];
int MOD = 1000000007;

int dfs(int x, int start) {
    visited[x] = 1;
    int r = 1;
    for (int i=0;i<adj[x].size();i++) {
        int next = adj[x][i];
        if (!visited[next] && (a[next]>a[start] || (a[next]==a[start] && next<start)) && a[next]-a[start]<=d) {
            r = ((long long) r*((long long) dfs(next,start)+1))%MOD;
        }
    }
    return r;
}

int main() {
    scanf("%d%d",&d,&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        visited[i] = 0;
    }
    for (int i=0;i<n-1;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    int ans = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) visited[j] = 0;
        ans = (ans+dfs(i,i))%MOD;
    }
    printf("%d\n",ans);

    return 0;
}