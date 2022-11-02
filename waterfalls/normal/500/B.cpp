#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int p[300];
char row[300];
int A[300][300];
int visited[300];

void dfs(int x) {
    visited[x] = 1;
    for (int i=0;i<n;i++) {
        if (A[x][i] && !visited[i]) dfs(i);
    }
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&p[i]);
    for (int i=0;i<n;i++) {
        scanf(" %s",&row);
        for (int j=0;j<n;j++) A[i][j] = row[j]-'0';
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) visited[j] = 0;
        dfs(i);
        int best = i;
        for (int j=i+1;j<n;j++) if (visited[j] && p[j]<p[best]) best = j;
        swap(p[i],p[best]);
    }
    for (int i=0;i<n;i++) printf("%d ",p[i]);

    return 0;
}