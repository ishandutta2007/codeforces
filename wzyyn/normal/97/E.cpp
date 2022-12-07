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
const int N=100005;
int n,m,Q,fa[N],f[N][18];
int dep[N],S[N],fl[N];
vector<int> e[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void dfs1(int x){
	dep[x]=dep[f[x][0]]+1;
	for (auto i:e[x])
		if (!dep[i]){
			f[i][0]=x; dfs1(i);
			if (get(x)==get(i)) fl[x]|=fl[i];
		}
		else if (dep[i]+1<dep[x]){
			if ((dep[i]+dep[x]+1)&1) fl[x]=1;
			for (int y=get(x);dep[y]>dep[i]+1;y=get(y)) fa[y]=f[y][0];
		}
}
void dfs2(int x){
	S[x]+=fl[x];
	for (auto i:e[x])
		if (dep[i]==dep[x]+1){
			if (get(x)==get(i)) fl[i]|=fl[x];
			S[i]=S[x]; dfs2(i);
		}
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	Rep(i,16,0) if (tmp&(1<<i)) x=f[x][i];
	Rep(i,16,0)
		if (f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return x==y?x:f[x][0];
}
bool ask(int x,int y){
	int L=LCA(x,y);
	//cout<<L<<endl;
	if (!L) return 0;
	if ((dep[x]+dep[y])&1) return 1;
	return S[x]+S[y]-2*S[L];
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,1,n) fa[i]=i;
	For(i,1,n) if (!dep[i])
		dfs1(i),dfs2(i);
	For(i,1,16) For(j,1,n)
		f[j][i]=f[f[j][i-1]][i-1];
	scanf("%d",&Q);
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		puts(ask(x,y)?"Yes":"No");
	}
}