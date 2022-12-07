#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N=300005;
int n,m,Q,fa[N],dep[N];
int f[N],qx[N],qy[N],q[N];
vector<int> e[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void dfs(int x,int f){
	for (auto i:e[x])
		if (i!=f){
			fa[i]=x;
			dep[i]=dep[x]+1;
			dfs(i,x);
		}
}
void printpath(int x,int y){
	int px=x,py=y;
	for (;px!=py;)
		if (dep[px]>dep[py])
			px=fa[px];
		else
			py=fa[py];
	*q=0;
	for (int i=x;;i=fa[i]){
		q[++*q]=i;
		if (i==px) break;
	}
	int tmp=*q;
	for (int i=y;i!=px;i=fa[i])
		q[++*q]=i;
	reverse(q+tmp+1,q+*q+1);
	printf("%d\n",*q);
	for (int i=1;i<=*q;i++)
		printf("%d ",q[i]);
	puts("");
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		fa[i]=i;
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int px=get(x),py=get(y);
		if (px!=py){
			fa[px]=py;
			e[x].push_back(y);
			e[y].push_back(x);
		}
	}
	dfs(1,fa[1]=0);
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++){
		scanf("%d%d",&qx[i],&qy[i]);
		f[qx[i]]^=1;
		f[qy[i]]^=1;
	}
	int s=0;
	for (int i=1;i<=n;i++)
		if (f[i]) ++s;
	if (s){
		puts("NO");
		printf("%d\n",s/2);
		return 0;
	}
	puts("YES");
	for (int i=1;i<=Q;i++)
		printpath(qx[i],qy[i]);
}