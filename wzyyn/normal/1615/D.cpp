#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,m,bad;
int fa[N],fav[N];
int ex[N],ey[N],ev[N];
int get(int x){
	if (x==fa[x]) return x;
	int y=fa[x];
	fa[x]=get(fa[x]);
	fav[x]^=fav[y];
	return fa[x];
}
int bic(int x){
	int s=0;
	for (;x;x-=x&(-x)) s++;
	return s;
}
void merge(int x,int y,int v){
	int px=get(x),py=get(y);
	if (px!=py){
		fa[py]=px;
		fav[py]=fav[x]^fav[y]^v;
	}
	else
		if (fav[x]^fav[y]^v)
			bad=1;
}
void solve(){
	bad=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		fa[i]=i,fav[i]=0;
	for (int i=1;i<n;i++){
		scanf("%d%d%d",&ex[i],&ey[i],&ev[i]);
		if (ev[i]!=-1) merge(ex[i],ey[i],bic(ev[i])&1);
	}
	for (int i=1;i<=m;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		merge(x,y,v);
	}
	if (bad) puts("NO");
	else{
		puts("YES");
		for (int i=1;i<=n;i++) get(i);
		for (int i=1;i<n;i++)
			printf("%d %d %d\n",ex[i],ey[i],ev[i]==-1?fav[ex[i]]^fav[ey[i]]:ev[i]);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}