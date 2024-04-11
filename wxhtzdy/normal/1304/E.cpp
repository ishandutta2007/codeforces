#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,q;
int lb[maxn];
int rb[maxn];
int de[maxn];
vector<int> a[maxn];
int lc[maxn][20];
int cv=1;
void dfs(int u,int p) {
    lc[u][0]=p;
    for(int k=1;k<20;k++) {
        if(lc[u][k-1]>0) lc[u][k]=lc[lc[u][k-1]][k-1];
    }
    lb[u]=rb[u]=cv;
    cv++;
    for(int v:a[u]) {
        if(v!=p) {
            de[v]=de[u]+1;
            dfs(v,u);
            lb[u]=min(lb[u],lb[v]);
            rb[u]=max(rb[u],rb[v]);
        }
    }
}
bool anc(int u,int v) {
    return lb[u]<=lb[v] && rb[v]<=rb[u];
}
int lca(int u,int v) {
    if(anc(u,v)) return u;
    if(anc(v,u)) return v;
    for(int k=19;k>=0;k--) {
        if(lc[u][k]>0 && !anc(lc[u][k],v)) {
            u=lc[u][k];
        }
    }
    return lc[u][0];
}
int dist(int u,int v) {
    return de[u]+de[v]-2*de[lca(u,v)];
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n-1;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,-1);
    scanf("%d",&q);
    while(q--) {
        int x,y,a,b,k;
        scanf("%d %d %d %d %d",&x,&y,&a,&b,&k);
        bool ok=false;
        int tmp=dist(a,b);
        ok|=(tmp<=k && tmp%2==k%2);
        tmp=min(dist(a,x)+dist(y,b),dist(a,y)+dist(x,b))+1;
        ok|=(tmp<=k && tmp%2==k%2);
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}