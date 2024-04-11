#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Edge {
    int y, next;
} edge[200022];
int x, y, n, m, idx[100011], l, an, an1, ans[444444], ans1[444444], a[111111], s;
bool vst[111111];
int dfs(int v, int par) {
    vst[v] = true;
    ans[++an] = v;
    a[v] ^= 1;
    for(int p = idx[v]; p; p = edge[p].next) if(!vst[edge[p].y]){
        dfs(edge[p].y, v);
        ans[++an] = v;
        a[v] ^= 1;
    }
    if(v != s and a[v]) {
        ans[++an] = par;
        ans[++an] = v;
        a[v] ^= 1;
        a[par] ^= 1;
    }
}
void build(int x, int y) {
    edge[++l].y = y;
    edge[l].next = idx[x];
    idx[x] = l;
}
int main()
{
    scanf("%d%d", &n, &m);
    fill(idx + 1, idx + 1 + n, 0);
    fill(vst + 1, vst + 1 + n, false);
    l = 0;
    for(int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        build(x, y);
        build(y, x);
    }
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) if(a[i] == 1) {
        s = i;
        break;
    }
    an = 0;
    dfs(s, 0);
    if(a[s]) an--, a[s] = 0;
    bool flag(true);
    for(int i = 1; i <= n; i++) if(a[i]) {
        flag = false;
        break;
    }
    if(!flag) printf("-1\n");
    else {
        printf("%d\n", an);
        for(int i = 1; i <= an; i++) printf("%d%c", ans[i], i == an?'\n':' ');
    }
    fclose(stdin);
    return 0;
}