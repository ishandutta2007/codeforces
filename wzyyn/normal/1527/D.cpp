#include<bits/stdc++.h>
using namespace std;

const int N=200005;
int fa[N][18];
int dfn[N],ed[N],dep[N],n;
long long f[N];
int chl,chr,sz[N];
vector<int> e[N];

void dfs(int x){
	dfn[x]=++*dfn;
	sz[x]=1;
	for (auto i:e[x])
		if (i!=fa[x][0]){
			fa[i][0]=x;
			dep[i]=dep[x]+1;
			dfs(i);
			sz[x]+=sz[i];
		}
	ed[x]=*dfn;
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	for (int i=17;i>=0;i--)
		if (tmp&(1<<i)) x=fa[x][i];
	for (int i=17;i>=0;i--)
		if (fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	return x==y?x:fa[x][0];	
}
bool isfa(int x,int y){
	return dfn[x]<=dfn[y]&&ed[y]<=ed[x];
}
int Jump(int x,int y){
	int tmp=dep[x]-dep[y]-1;
	for (int i=17;i>=0;i--)
		if (tmp&(1<<i)) x=fa[x][i];
	return x;
}
bool Insert(int p){
	if (!isfa(chl,chr)) swap(chl,chr);
	if (!isfa(chl,chr)){
		int L=LCA(chl,chr);
		if (!isfa(L,p)) return 0;
		if (isfa(p,chl)||isfa(p,chr)) return 1;
		if (isfa(chl,p)) return chl=p,1;
		if (isfa(chr,p)) return chr=p,1;
		return 0;
	}
	else{
		if (isfa(chl,p)){
			if (isfa(p,chr)) return 1;
			if (isfa(chr,p)) return chr=p,1;
			if (LCA(p,chr)==chl)
				return chl=p,1;
			return 0;
		}
		else
			return chl=p,1;
	}
}
long long Query(){
	if (!isfa(chl,chr)) swap(chl,chr);
	if (!isfa(chl,chr))
		return 1ll*sz[chl]*sz[chr];
	return 1ll*sz[chr]*(n-sz[Jump(chr,chl)]);
}
void solve(){
	scanf("%d",&n);
	for (int i=0;i<=n;i++){
		e[i].resize(0);
		dfn[i]=ed[i]=0;
	}
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		++x; ++y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1);
	for (int i=1;i<=17;i++)
		for (int j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	f[0]=1ll*n*(n-1)/2;
	f[1]=0;
	int s=1;
	for (auto i:e[1]){
		f[1]+=1ll*s*sz[i];
		s+=sz[i];
	}
	for (int i=2;i<=n+1;i++) f[i]=0;
	chl=1; chr=2; f[2]=Query();
	for (int i=3;i<=n;i++){
		if (!Insert(i)) break;
		f[i]=Query();
	}
	for (int i=0;i<=n;i++)
		printf("%lld ",f[i]-f[i+1]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}