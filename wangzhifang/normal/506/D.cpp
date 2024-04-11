#include <cstdio>
#include <unordered_map>
#define max_n 100000
using namespace std;
typedef const int& ci;
unordered_map<int,int> par[max_n+1],ans[max_n+1];
int getfa(ci x,ci col){
	int&tmp=par[x][col];
	return tmp==x?x:(tmp=getfa(tmp,col));
}
inline void merge(int x,int y,ci col){
	par[x].count(col)?(x=getfa(x,col)):(par[x][col]=x);
	par[y].count(col)?(y=getfa(y,col)):(par[y][col]=y);
	x!=y&&(par[x][col]=y);
}
int main(){
	int n,m,q,u,v,ret;
	scanf("%d%d",&n,&m);
	for(int i=m+1,a,b,c; --i; merge(a,b,c))
		scanf("%d%d%d",&a,&b,&c);
	scanf("%d",&q);
	for(++q; --q; ){
		scanf("%d%d",&u,&v);
		par[u].size()>par[v].size()&&(swap(u,v),1);
		if(ans[u].count(v)){
			printf("%d\n",ans[u][v]);
			continue;
		}
		ret=0;
		for(pair<int,int>p:par[u])
			ret+=(par[v].count(p.first)&&getfa(u,p.first)==getfa(v,p.first));
		printf("%d\n",ans[u][v]=ret);
	}
	return 0;
}