#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;

const int N=200005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n,m,Q,E_cnt;
int f[N],dep[N],fa[N][20];
int S1[N],S2[N],S3[N];
pii E[N];
int get(int x){
	return x==f[x]?x:f[x]=get(f[x]);
}
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
	For(i,0,17) if (tmp&(1<<i)) x=fa[x][i];
	Rep(i,17,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
void getsum(int x){	
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x][0]){
			getsum(e[i].to);
			S1[x]+=S1[e[i].to];
			S2[x]+=S2[e[i].to];
			S3[x]+=S3[e[i].to];
		}
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n) f[i]=i;
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		if (get(x)!=get(y)){
			add(x,y),add(y,x);
			f[get(x)]=get(y);
		}
		else
			E[++E_cnt]=pii(x,y);
	}
	For(i,1,n)
		if (get(i)==i){
			add(i,n+1);
			add(n+1,i);
		}
	dfs(n+1);
	For(i,1,17) For(j,1,n+1)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	For(i,1,E_cnt){
		int x=E[i].fi,y=E[i].se;
		S1[x]++; S1[y]++; S1[LCA(x,y)]-=2;
	}
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		++S2[x]; --S2[LCA(x,y)];
		++S3[y]; --S3[LCA(x,y)];
	}
	getsum(n+1);
	For(i,1,n){
		if (S2[i]&&S3[i]&&!S1[i])
			return puts("No"),0;
		if ((S2[i]||S3[i])&&fa[i][0]==n+1)
			return puts("No"),0;
	}
	puts("Yes");
}