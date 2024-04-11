#include <cstdio>
#include <cstring>
#define max_n 200000
#define max_m max_n-1<<1
using namespace std;
struct note {
    int before,v;
};
struct edge_set {
    note edge[max_m + 1];
    int last[max_n + 1];
    int cnt;
    void build() {
        cnt = 0;
        memset(last,-1,sizeof(last));
    }
    edge_set(int n){
        cnt = 0;
        memset(last,-1,sizeof(last));
    }
    edge_set(){
    }
    void add(int u,int v) {
        cnt ++;
        edge[cnt].v = v;
        edge[cnt].before = last[u];
        last[u] = cnt;
    }
};
edge_set map1;
edge_set tmp;
int n;
int color[max_n+1];
int f[max_n],p[max_n];
bool vis[max_n+1];
struct disjoint_set{
    int p[max_n+1];
    void build(int n){
        for(register int i = 1; i <= n; i ++)
            p[i]=i;
    }
    int find(int x){
        if(x == p[x])
            return x;
        return p[x]=find(p[x]);
    }
    void merge(int x,int y){
        p[find(x)]=find(y);
    }
};
disjoint_set st;
int dfs(int u,int p){
    vis[u]=1;
    int v,i;
    for(i = tmp.last[u]; ~i; i = tmp.edge[i].before){
        v = tmp.edge[i].v;
        if(v == p)
            continue;
        if(color[v]!=color[u])
            continue;
        if(vis[v])
            continue;
        st.merge(u,v);
        dfs(v,u);
    }
}
void input(){
    int u,v,i;
    scanf("%d",& n);
    for(i = 1; i <= n; i ++)
    	scanf("%d",color+i);
    tmp.build();
    for(i = 1; i < n; i ++){
        scanf("%d%d",& u,& v);
        tmp.add(u,v);
        tmp.add(v,u);
        f[i]=u;
        p[i]=v;
    }
    st.build(n);
    for(i = 1; i <= n; i ++)
    	if(! vis[i])
    		dfs(i,0);
    for(i = 1; i <= n; i ++)
    	st.p[i]=st.find(i);
    map1.build();
    for(i= 1; i < n; i ++)
    	if(st.p[f[i]]!=st.p[p[i]])
    		map1.add(st.find(f[i]),st.find(p[i])),map1.add(st.find(p[i]),st.find(f[i]));
}
int away(edge_set& map1,int n,int s,int &dis,int p=0){
    int d=0,ret=s,v,x,i;
    for(i = map1.last[s]; ~i; i = map1.edge[i].before){
        if(map1.edge[i].v == p)
            continue;
        v = away(map1,n,map1.edge[i].v,x,s);
        if(x >= d){
            d = x+1;
            ret = v;
        }
    }
    dis = d;
    return ret;
}
int diameter(edge_set& map1,int n){
    int ret;
    away(map1,n,away(map1,n,st.p[1],ret),ret);
    return ret;
}
int main(){
    input();
    printf("%d\n",(diameter(map1,n)+1)>>1);
    return 0;
}