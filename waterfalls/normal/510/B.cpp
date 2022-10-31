#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,found;
char grid[50][51];
int visited[50][50];
int dX[4] = {-1,0,1,0};
int dY[4] = {0,-1,0,1};

void dfs(int x, int y, int from) {
    visited[x][y] = 1;
    for (int i=0;i<4;i++) {
        int nX = x+dX[i];
        int nY = y+dY[i];
        if (nX<0 || nY<0 || nX>=n || nY>=m || grid[x][y]!=grid[nX][nY]) continue;
        if (visited[nX][nY] && i!=from) found = 1;
        if (!visited[nX][nY]) dfs(nX,nY,(i+2)%4);
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf(" %s",&grid[i]);
    found = 0;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) visited[i][j] = 0;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (!visited[i][j]) dfs(i,j,-1);
    if (found) printf("Yes\n");
    else printf("No\n");

    return 0;
}