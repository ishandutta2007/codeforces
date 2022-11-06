#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, M;
int a[400010],b[400010];
struct edge {
    int L, R;
    LL W;
}e[400010];
int MM = 0;
bool cmp(edge e1, edge e2) {
    return e1.W > e2.W;
}
int fa[400010];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d%d",&M,&N);
    for (int i=1;i<=M;i++) scanf("%d",&a[i]);
    for (int i=1;i<=N;i++) scanf("%d",&b[i]);
    LL sum = 0;
    for (int i=1;i<=M;i++) {
        int s;
        scanf("%d",&s);
        for (int j=1;j<=s;j++) {
            int u;
            scanf("%d",&u);
            e[++MM] = (edge){i, M + u, LL(a[i] + b[u])};
            sum += (a[i] + b[u]);
        }
    }
    sort(e+1,e+MM+1,cmp);
    for (int i=1;i<=N+M;i++) fa[i] = i;
    for (int i=1;i<=MM;i++) {
        if (find(e[i].L) != find(e[i].R)) {
            fa[find(e[i].L)] = find(e[i].R);
            sum -= e[i].W;
        }
    }
    printf("%lld\n",sum);
}