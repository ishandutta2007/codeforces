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
const int N=400005;
vector<int> e[N];
int n,k,R,nd,Q;
int f[N][19],dep[N];
int fa[N],dis[N],co[N];
int q[N],a[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void dfs(int x){
	for (auto i:e[x])
		if (i!=f[x][0]){
			f[i][0]=x;
			dep[i]=dep[x]+1;
			dfs(i);
		}
}
int jump(int x,int k){
	Rep(i,18,0)
		if (k&(1<<i))
			x=f[x][i];
	return x;
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	x=jump(x,dep[x]-dep[y]);
	Rep(i,18,0)
		if (f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return x==y?x:f[x][0];
}
void SSSP(){
	int h=0,t=0;
	For(i,1,nd) dis[i]=-1;
	For(i,1,R) dis[a[i]]=0,co[a[i]]=i,q[++t]=a[i];
	while (h!=t){
		int x=q[++h];
		if (dis[x]==k) continue;
		for (auto i:e[x])
			if (dis[i]==-1){
				dis[i]=dis[x]+1;
				co[i]=co[x];
				q[++t]=i;
			}
			else
				fa[get(co[i])]=get(co[x]);
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&R);
	nd=n;
	For(i,1,n-1){
		int x,y; ++nd;
		scanf("%d%d",&x,&y);
		e[x].PB(nd); e[nd].PB(x);
		e[y].PB(nd); e[nd].PB(y);
	}
	dfs(1);
	For(i,1,18) For(j,1,nd)
		f[j][i]=f[f[j][i-1]][i-1];
	For(i,1,R){
		scanf("%d",&a[i]);
		fa[i]=i;
	}
	SSSP();
	scanf("%d",&Q);
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int L=LCA(x,y),d=dep[x]+dep[y]-2*dep[L];
		if (d<=2*k) puts("YES");
		else{
			int nx=(dep[x]-dep[L]>=k?jump(x,k):jump(y,d-k));
			int ny=(dep[y]-dep[L]>=k?jump(y,k):jump(x,d-k));
			if (!co[nx]||!co[ny]) puts("NO");
			else puts(get(co[nx])==get(co[ny])?"YES":"NO");
		}
	}
}