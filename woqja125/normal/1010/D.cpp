#include <cstdio>
int ans[1000001];
int type[1000001];
int c[1000001][2];
int res[1000001];
char tmp[100];
int dfs1(int x) {
    int &re = res[x];
    if(type[x] == 'I') re = c[x][0];
    if(type[x] == 'N') re = !dfs1(c[x][0]);
    if(type[x] == 'A') re = dfs1(c[x][1]) & dfs1(c[x][0]);
    if(type[x] == 'O') re = dfs1(c[x][1]) | dfs1(c[x][0]);
    if(type[x] == 'X') re = dfs1(c[x][1]) ^ dfs1(c[x][0]);
    return re;
}
int o;
void dfs2(int x, int f) {
    if(type[x] == 'I') ans[x] = f;
    if(type[x] == 'N') dfs2(c[x][0], f);
    if(type[x] == 'A') {
        if(res[c[x][0]] == 1 && res[c[x][1]] == 1) {
            dfs2(c[x][0], f);
            dfs2(c[x][1], f);
        }
        if(res[c[x][0]] == 1 && res[c[x][1]] == 0) {
            dfs2(c[x][0], o);
            dfs2(c[x][1], f);
        }
        if(res[c[x][0]] == 0 && res[c[x][1]] == 1) {
            dfs2(c[x][0], f);
            dfs2(c[x][1], o);
        }
        if(res[c[x][0]] == 0 && res[c[x][1]] == 0) {
            dfs2(c[x][0], o);
            dfs2(c[x][1], o);
        }
    }
    if(type[x] == 'O') {
        if(res[c[x][0]] == 1 && res[c[x][1]] == 1) {
            dfs2(c[x][0], o);
            dfs2(c[x][1], o);
        }
        if(res[c[x][0]] == 1 && res[c[x][1]] == 0) {
            dfs2(c[x][0], f);
            dfs2(c[x][1], o);
        }
        if(res[c[x][0]] == 0 && res[c[x][1]] == 1) {
            dfs2(c[x][0], o);
            dfs2(c[x][1], f);
        }
        if(res[c[x][0]] == 0 && res[c[x][1]] == 0) {
            dfs2(c[x][0], f);
            dfs2(c[x][1], f);
        }
    }
    if(type[x] == 'X') {
        dfs2(c[x][0], f);
        dfs2(c[x][1], f);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%s%d", tmp, &c[i][0]);
        type[i] = tmp[0];
        if(type[i] != 'I' && type[i] != 'N') scanf("%d", &c[i][1]);
        ans[i] = -1;
    }
    o = dfs1(1);
    dfs2(1, !o);
    for(int i=1; i<=n; i++) if(ans[i] != -1) printf("%d", ans[i]);
    printf("\n");
    return 0;
}