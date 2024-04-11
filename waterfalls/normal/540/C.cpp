#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,r1,c1,r2,c2;
char cave[513][513];
bool visited[513][513];
int dX[4] = {-1,0,1,0};
int dY[4] = {0,-1,0,1};

void dfs(int x, int y) {
    visited[x][y] = 1;
    if (cave[x][y]=='X' && (x!=r1 || y!=c1)) return;
    for (int i=0;i<4;i++) {
        int nx = x+dX[i];
        int ny = y+dY[i];
        if (nx<0 || ny<0 || nx>=n || ny>=m || visited[nx][ny]) continue;
        dfs(nx,ny);
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf(" %s",&cave[i]);
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    r1-=1; c1-=1; r2-=1; c2-=1;
    if (r1==r2 && c1==c2) {
        int ok = 0;
        for (int i=0;i<4;i++) {
            int nx = r1+dX[i];
            int ny = c1+dY[i];
            if (nx<0 || ny<0 || nx>=n || ny>=m || cave[nx][ny]=='X') continue;
            ok = 1;
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    } else {
        dfs(r1,c1);
        if (!visited[r2][c2]) printf("NO\n");
        else if (cave[r2][c2]=='X') printf("YES\n");
        else {
            int cnt = 0;
            for (int i=0;i<4;i++) {
                int nx = r2+dX[i];
                int ny = c2+dY[i];
                if (nx<0 || ny<0 || nx>=n || ny>=m || (cave[nx][ny]=='X' && (nx!=r1 || ny!=c1))) continue;
                cnt+=1;
            }
            if (cnt>1) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}