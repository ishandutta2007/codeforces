#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
char grid[2000][2001];
queue<pair<int,int> > process;
bool in[2000][2000];

void check(int x, int y) {
    int ok = 0;
    if (x<0 || y<0 || x>=n || y>=m || grid[x][y]=='.' || in[x][y]) return;
    if (x>0 && y>0) if (grid[x-1][y-1]=='.' && grid[x-1][y]=='.' && grid[x][y-1]=='.') ok = 1;
    if (x>0 && y<m-1) if (grid[x-1][y+1]=='.' && grid[x-1][y]=='.' && grid[x][y+1]=='.') ok = 1;
    if (x<n-1 && y>0) if (grid[x+1][y-1]=='.' && grid[x+1][y]=='.' && grid[x][y-1]=='.') ok = 1;
    if (x<n-1 && y<m-1) if (grid[x+1][y+1]=='.' && grid[x+1][y]=='.' && grid[x][y+1]=='.') ok = 1;
    if (ok) process.push(make_pair(x,y)), in[x][y] = 1;
}

void fix(int x, int y) {
    grid[x][y] = '.';
    check(x-1,y-1); check(x-1,y); check(x-1,y+1);
    check(x,y-1); check(x,y+1);
    check(x+1,y-1); check(x+1,y); check(x+1,y+1);
    in[x][y] = 0;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf(" %s",&grid[i]);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) check(i,j);
    while (process.size()>0) fix(process.front().first,process.front().second), process.pop();
    for (int i=0;i<n;i++) printf("%s\n",grid[i]);

    return 0;
}