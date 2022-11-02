#include<bits/stdc++.h>
using namespace std;
const int N=3005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot;
int vis[N],q[N],V;
int deg[N],n,sz;
double ans;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int A,int B){
	deg[x]==2?B++:A++; vis[x]=V;
	if (B==sz) ans+=1.0/(A+2);
	else if (B<=2) ans+=1.0/(A+B);
	else ans+=1.0/(A+B)+1.0/(A+sz-B+2)-1.0/(A+sz);
	for (int i=head[x];i;i=e[i].next)
		if (vis[e[i].to]!=V) dfs(e[i].to,A,B);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		++x; ++y; deg[x]++; deg[y]++;
		add(x,y); add(y,x);
	}
	int t=0;
	for (int i=1;i<=n;i++)
		if (deg[i]==1) q[++t]=i;
	for (;t;){
		int x=q[t--];
		for (int i=head[x];i;i=e[i].next)
			if ((--deg[e[i].to])==1) q[++t]=e[i].to;
	}
	for (int i=1;i<=n;i++)
		if (deg[i]==2) ++sz;
	for (V=1;V<=n;V++) dfs(V,0,0);
	printf("%.10lf\n",ans);
}