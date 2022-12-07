#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;

const int N=250005;
vector<int> e1[N],e2[N];
int n,f[N],fa[N][18];
int dep[N],deg[N],q[N];
void dfs(int x){
	dep[x]=dep[fa[x][0]]+1;
	for (auto i:e1[x])
		if (i!=fa[x][0]){
			fa[i][0]=x;
			dfs(i);
		}
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	Rep(i,17,0)
		if (tmp&(1<<i))
			x=fa[x][i];
	Rep(i,17,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int get(int x){
	return !f[x]?x:f[x]=get(f[x]);
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e1[x].PB(y);
		e1[y].PB(x);
	}
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e2[x].PB(y);
		e2[y].PB(x);
		++deg[x];
		++deg[y];
	}
	deg[1]=-23333; dfs(1);
	printf("%d\n",n-1);
	int h=0,t=0;
	For(i,1,n) if (deg[i]==1) q[++t]=i;
	For(i,1,17) For(j,1,n)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	while (h!=t){
		int x=q[++h],y;
		if (!deg[x]) continue;
		--deg[x];
		for (auto i:e2[x]) if (deg[i]) y=i;
		if ((--deg[y])==1) q[++t]=y;
		int L=LCA(x,y),a=get(x);
		if (dep[a]>dep[L]){
			printf("%d %d %d %d\n",a,fa[a][0],x,y);
			f[a]=get(fa[a][0]);
		}
		else{
			int b=y;
			Rep(i,17,0)
				if (dep[fa[b][i]]>dep[L]&&get(fa[b][i])!=a)
					b=fa[b][i];
			f[b]=a;
			printf("%d %d %d %d\n",b,fa[b][0],x,y);
		}
	}
}