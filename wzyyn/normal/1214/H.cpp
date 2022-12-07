#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=200005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot;
int n,k,vis[N],lvl[N];
int dep[N],fa[N][20];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x][0]){
			fa[e[i].to][0]=x;
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to);
		}
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	Rep(i,18,0)
		if (tmp&(1<<i))
			x=fa[x][i];
	Rep(i,18,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
int findmx(int x){
	int mxv=-1,mxid;
	For(i,1,n){
		int val=dis(x,i);
		if (val>mxv) mxv=val,mxid=i;
	}
	return mxid;
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1);
	if (k==2){
		puts("Yes");
		For(i,1,n) printf("%d ",dep[i]%2+1);
		return 0;
	}
	For(i,1,18) For(j,1,n)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	int S=findmx(1);
	int T=findmx(S);
	int dia=dis(S,T);
	For(i,1,n){
		int d1=dis(S,i),d2=dis(T,i);
		if (d1+d2==dia) vis[i]=1,lvl[i]=d1;
	}
	For(i,1,n) if (!vis[i]){
		int d1=dis(S,i),d2=dis(T,i);
		if (d1>=k-1&&d2>=k-1) return puts("No"),0;
		if (d1>=d2) lvl[i]=d1;
		else lvl[i]=dia-d2;
	}
	puts("Yes");
	For(i,1,n) printf("%d ",lvl[i]%k+1);
}