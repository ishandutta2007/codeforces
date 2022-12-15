#include<bits/stdc++.h>
#define MAX   300300
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
struct edge {
    int u,v,w;
    edge() {
        u=v=w=0;
    }
    void input(void) {
        scanf("%d%d%d",&u,&v,&w);
    }
    bool operator < (const edge &x) const {
        return (w<x.w);
    }
};
inline void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
edge e[MAX];
int f[MAX],mf[MAX];
int n,m;
void loadgraph(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,m) e[i].input();
    sort(e+1,e+m+1);
}
void optimize(void) {
    int j=1;
    FOR(i,1,m) {
        while (j<i && e[j].w<e[i].w) {
            maximize(mf[e[j].v],f[j]);
            j++;
        }
        f[i]=mf[e[i].u]+1;
    }
    int res=0;
    FOR(i,1,m) maximize(res,f[i]);
    printf("%d",res);
}
int main(void) {
    loadgraph();
    optimize();
    return 0;
}