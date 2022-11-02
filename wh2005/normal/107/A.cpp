#include<bits/stdc++.h>
using namespace std;
int n,m,head[1009],tot;
struct pp{int nxt,to,len;}g[10009];
int l[1009],r[1009];
void add(int u,int v,int w){
	r[u]++,l[v]++;
	g[++tot].nxt=head[u],g[tot].to=v,g[tot].len=w,head[u]=tot;
}
int ansl[1009],ansr[1009],answ[1009],cnt;
void dfs(int u){
	if(head[u]==-1){
		ansr[cnt]=u;
		return ;
	}
	for(int i=head[u];i!=-1;i=g[i].nxt){
		int v=g[i].to;answ[cnt]=min(answ[cnt],g[i].len);dfs(v);
	}
}
int main(){
	memset(head,-1,sizeof(head));tot=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){int u,v,w;scanf("%d%d%d",&u,&v,&w);add(u,v,w);}
	cnt=0;
	for(int i=1;i<=n;i++)
		if(l[i]==0&&r[i]==1){
			answ[++cnt]=1e9,ansl[cnt]=i;dfs(i);
		}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++){
		printf("%d %d %d\n",ansl[i],ansr[i],answ[i]);
	}
	return 0;
}