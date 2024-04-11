#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int T,n,head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){
	g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
int f[N];
vector<int >a;
void dfs(int u,int fa){
	int siz=0;
	for(int i=head[u];i!=-1;i=g[i].nxt){
		int v=g[i].to;if(v==fa) continue;
		dfs(v,u);siz+=(f[v]==0);
	}
	if(siz){
		f[u]=1;
		a.push_back(siz);
	}
	else f[u]=0;
	return ;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) head[i]=-1,f[i]=0;tot=0;
		for(int i=1;i<n;i++){
			int u,v;scanf("%d%d",&u,&v);
			add(u,v);add(v,u);
		}
		a.clear();
		dfs(1,0);
		int ans=1;
		for(int i=0;i<(int)a.size();i++) ans+=a[i]-1;
		printf("%d\n",ans);
	}
	return 0;
}