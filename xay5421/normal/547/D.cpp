#include<cstdio>
#include<vector>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=200005;
int n,used[N],col[N];std::vector<int>f[N],g[N];
struct ed{ed*nxt;int to;}pool[N<<1],*p=pool,*lnk[N];
void ae(int u,int v){*++p=(ed){lnk[u],v},lnk[u]=p;}
void dfs(int u){
	used[u]=1;
	for(ed*i=lnk[u];i;i=i->nxt)if(!used[i->to])col[i->to]=col[u]^1,dfs(i->to);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int x,y;scanf("%d%d",&x,&y);
		f[x].push_back(i);
		g[y].push_back(i);
	}
	rep(i,1,N-1)for(int j=0;j<(int)f[i].size()-1;j+=2)ae(f[i][j],f[i][j+1]),ae(f[i][j+1],f[i][j]);
	rep(i,1,N-1)for(int j=0;j<(int)g[i].size()-1;j+=2)ae(g[i][j],g[i][j+1]),ae(g[i][j+1],g[i][j]);
	rep(i,1,n)if(!used[i])dfs(i);
	rep(i,1,n)putchar(col[i]?'r':'b');
	return 0;
}