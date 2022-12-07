#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n;
vector<pair<int,int>> e[N];
int sz[N],fa[N],fav[N],dep[N];
int dfn[N],ed[N],pos[N],top[N];
void dfs(int x){
	sz[x]=1;
	for (auto i:e[x])
		if (i.first!=fa[x]){
			fa[i.first]=x;
			fav[i.first]=i.second;
			dep[i.first]=dep[x]+1;
			dfs(i.first);
			sz[x]+=sz[i.first];
		}
}
void dfs(int x,int tp){
	top[x]=tp;
	dfn[x]=++*dfn;
	pos[*dfn]=x;
	int k=0;
	for (auto i:e[x])
		if (i.first!=fa[x]&&sz[i.first]>sz[k])
			k=i.first;
	if (k) dfs(k,tp);
	for (auto i:e[x])
		if (i.first!=fa[x]&&i.first!=k)
			dfs(i.first,i.first);
	ed[x]=*dfn;
}

struct Tree{
	int tg[N*4];
	int s0[N*4],s1[N*4];
	long long v0[N*4],v1[N*4];
	void build(int k,int l,int r){
		memset(tg,0,sizeof(tg));
	}
	void rev(int k){
		swap(s0[k],s1[k]);
		swap(v0[k],v1[k]);
		tg[k]^=1;
	}
	void pushdown(int k){
		if (tg[k]){
			rev(k*2);
			rev(k*2+1);
			tg[k]=0;
		}
	}
	void pushup(int k){
		s0[k]=s0[k*2]+s0[k*2+1];
		s1[k]=s1[k*2]+s1[k*2+1];
		v0[k]=v0[k*2]+v0[k*2+1];
		v1[k]=v1[k*2]+v1[k*2+1];
	}
	void ins(int k,int l,int r,int p,int v){
		if (l==r){
			++s1[k]; v1[k]+=v;
			return;
		}
		pushdown(k);
		int mid=(l+r)/2;
		if (p<=mid) ins(k*2,l,mid,p,v);
		else ins(k*2+1,mid+1,r,p,v);
		pushup(k);
	}
	void rev(int k,int l,int r,int x,int y){
		if (x<=l&&r<=y)
			return rev(k);
		pushdown(k);
		int mid=(l+r)/2;
		if (x<=mid) rev(k*2,l,mid,x,y);
		if (y>mid) rev(k*2+1,mid+1,r,x,y);
		pushup(k);
	}
}Tr;
int f[N],q[N];
int mat[N],vis[N];
int get(int x){
	return x==f[x]?x:f[x]=get(f[x]);
}
void solve(int x){
	for (auto i:e[x])
		if (i.first!=fa[x]&&vis[i.first]){
			solve(i.first);
			if (!mat[i.first])
				mat[i.first]=mat[x]=1,q[++*q]=i.second;
		}
}
void Activ(int x){
	vis[x]=1;
	Tr.ins(1,1,n,dfn[x],fav[x]);
	for (x=fa[x];x;x=fa[top[x]])
		Tr.rev(1,1,n,dfn[top[x]],dfn[x]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(pair<int,int>(y,i));
		e[y].push_back(pair<int,int>(x,i));
	}
	dfs(1);
	dfs(1,1);
	Tr.build(1,1,n);
	for (int i=1;i<=n;i++) f[i]=i;
	Activ(1);
	for (;;){
		int tp,x;
		scanf("%d",&tp);
		if (tp==1){
			scanf("%d",&x);
			Activ(x);
			printf("%lld\n",Tr.s0[1]==Tr.s1[1]?Tr.v1[1]:0);
		}
		if (tp==2){
			*q=0;
			if (Tr.s0[1]==Tr.s1[1]){
				memset(mat,0,sizeof(mat));
				solve(1);
			}
			sort(q+1,q+*q+1);
			//printf("ANS=");
			for (int i=0;i<=*q;i++)
				printf("%d%c",q[i],i==*q?'\n':' ');
		}
		if (tp==3||tp==0) return 0;
		fflush(stdout);
	}
	/*

	*/
}