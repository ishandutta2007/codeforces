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
#define y1 fdhjksa
using namespace std;
const int N=500005;
int n,p1,p2;
vector<int> e[N];
int find_dis(int S,int T){
	static int dis[N],q[N];
	int h=0,t=1;
	For(i,1,n) dis[i]=-1;
	q[1]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x])
			if (dis[i]==-1){
				dis[i]=dis[x]+1;
				q[++t]=i;
			}
	}
	return dis[T];
}
pii mx1[N],mx2[N],mx3[N];
int vfa[N];
void dfs1(int x,int fa){
	mx1[x]=pii(0,x);
	mx2[x]=mx3[x]=pii(-1,0);
	for (auto i:e[x])
		if (i!=fa){
			dfs1(i,x);
			pii tmp(mx1[i].fi+1,i);
			if (tmp>mx1[x]) swap(mx1[x],tmp);
			if (tmp>mx2[x]) swap(mx2[x],tmp);
			if (tmp>mx3[x]) swap(mx3[x],tmp);
		}
}
void dfs2(int x,int fa){
	for (auto i:e[x]) if (i!=fa){
		vfa[i]=max(vfa[x],mx1[x].se==i?mx2[x].fi:mx1[x].fi)+1;
		dfs2(i,x);
	}
}
int mx[N],dfn[N],ed[N];
int fa[N][18],dep[N];
int jump(int x,int y){
	Rep(i,16,0)
		if (y&(1<<i))
			x=fa[x][i];
	return x;
}
void dfs3(int x){
	mx[x]=x;
	dfn[x]=++*dfn;
	for (auto i:e[x])
		if (i!=fa[x][0]){
			fa[i][0]=x;
			dep[i]=dep[x]+1;
			dfs3(i);
			if (dep[mx[x]]<dep[mx[i]])
				mx[x]=mx[i];
		}
	ed[x]=*dfn;
}
bool isson(int x,int y){
	return dfn[x]<=dfn[y]&&ed[y]<=ed[x];
}
void solve(){
	scanf("%d%d%d",&n,&p1,&p2);
	For(i,1,n) e[i].resize(0);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	int L=find_dis(p1,p2);
	dfs1(1,0); dfs2(1,0);
	int p=-1;
	For(i,1,n){
		int sum=0;
		sum+=(mx1[i].fi>=L);
		sum+=(mx2[i].fi>=L);
		sum+=(mx3[i].fi>=L);
		sum+=(vfa[i]>=L);
		//cout<<i<<' '<<sum<<' '<<L<<endl;
		if (sum>=3) p=i;
	}
	if (p==-1) return puts("NO"),void(0);
	*dfn=dep[p]=0; fa[p][0]=p;
	dfs3(p);
	For(i,1,16) For(j,1,n)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	For(i,1,n){
		if (isson(p1,p2)||isson(p2,p1))
			return puts("YES"),void(0);
		int del=dep[mx[p1]]-dep[p1];
		p1=mx[p1]; p2=jump(p2,del);
		swap(p1,p2);
	}
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}