#include <cstdio>
#include <algorithm>
#define cs const
#define max_m 2000000
#define max_n 2000
using namespace std;
typedef cs int& ci;
int res[max_m+1],color[max_n+1][max_n+1],pos[max_n+1][max_n+1],tot=1;
struct node{
	int u,v;
	node(){}
	node(ci _u,ci _v):u(_u),v(_v){}
};
node g[max_m+1];
template<typename T>void maxify(T&x,cs T&y){
	y>x&&(x=y);
}
void dfs(ci u,ci v,ci now,ci pre){
    if(now==pre){
        color[u][now]=v,color[v][now]=u;
        return;
    }
    int vv=color[v][now];
    color[u][now]=v,color[v][now]=u;
    if(!vv)
		color[v][pre]=0;
    else
		dfs(v,vv,pre,now);
}
int main(){
    int a,b,m;
	scanf("%d%d%d",&a,&b,&m);
	for(int i=-1,u,v; ++i<m; g[i]=node(u,v),pos[u][v]=i){
		scanf("%d%d",&u,&v);
		u+=b;
	}
    int ans=0;
	for(int i=-1,cnt1,cnt2,u,v; ++i<m; maxify(ans,max(cnt1,cnt2)),dfs(u,v,cnt1,cnt2)){
        for(cnt1=cnt2=1,u=g[i].u,v=g[i].v; color[u][cnt1]; ++cnt1);
        for(; color[v][cnt2]; ++cnt2);
	}
	for(int i=0; ++i<=a; )
		for(int x=b+i,j=0; ++j<=ans; color[x][j]&&(res[pos[x][color[x][j]]]=j));
    printf("%d\n",ans);
    for(int i=0; i<m; ++i)
        printf("%d ",res[i]);
    return 0;
}