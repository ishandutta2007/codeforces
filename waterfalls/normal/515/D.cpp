#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m;
char grid[2000][2001];
char ans[2000][2001];
queue<pair<int,int> > process;
int dX[4] = {-1,0,1,0};
int dY[4] = {0,-1,0,1};

int neighbors(int x, int y) {
    if (grid[x][y]=='*') return 0;
    int r = 0;
    for (int i=0;i<4;i++) {
        int nX = x+dX[i];
        int nY = y+dY[i];
        if (nX<0 || nY<0 || nX>=n || nY>=m) continue;
        if (ans[nX][nY]=='.') r+=1;
    }
    return r;
}

void addTile(int x, int y) {
    if (ans[x][y]!='.') return;
    for (int i=0;i<4;i++) {
        int nX = x+dX[i];
        int nY = y+dY[i];
        if (nX<0 || nY<0 || nX>=n || nY>=m || ans[nX][nY]!='.') continue;
        if (i==0) {
            ans[x][y] = 'v';
            ans[nX][nY] = '^';
        } else if (i==1) {
            ans[x][y] = '>';
            ans[nX][nY] = '<';
        } else if (i==2) {
            ans[x][y] = '^';
            ans[nX][nY] = 'v';
        } else {
            ans[x][y] = '<';
            ans[nX][nY] = '>';
        }
        for (int j=0;j<4;j++) {
            int nnX = nX+dX[j];
            int nnY = nY+dY[j];
            if (nnX<0 || nnY<0 || nnX>=n || nnY>=m || ans[nnX][nnY]!='.') continue;
            if (neighbors(nnX,nnY)==1) process.push(make_pair(nnX,nnY));
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf(" %s",&grid[i]);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) ans[i][j] = grid[i][j];
    for (int i=0;i<n;i++) ans[i][m] = '\0';
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (neighbors(i,j)==1) process.push(make_pair(i,j));
    while (process.size()>0) {
        addTile(process.front().first,process.front().second);
        process.pop();
    }
    int ok = 1;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (ans[i][j]=='.') ok = 0;
    if (ok) for (int i=0;i<n;i++) printf("%s\n",ans[i]);
    else printf("Not unique\n");

    return 0;
}