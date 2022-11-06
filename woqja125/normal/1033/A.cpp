#include <cstdio>
int map[1001][1001];
int _x, _y, n;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
void dfs(int x, int y) {
    map[x][y] = 1;
    for(int d=0; d<8; d++){
        int xx = x + dx[d];
        int yy = y + dy[d];
        if(xx <= 0 || yy <= 0 || xx > n || yy > n || map[xx][yy] != 0) continue;
        if(xx == _x || yy == _y || xx+yy == _x+_y || xx-yy == _x-_y) continue;
        dfs(xx, yy);
    }
}
int main() {
    int a, b, u, v;
    scanf("%d%d%d%d%d%d%d", &n, &_x, &_y, &a, &b, &u, &v);
    dfs(a, b);
    printf(map[u][v]?"YES\n":"NO\n");
    return 0;
}