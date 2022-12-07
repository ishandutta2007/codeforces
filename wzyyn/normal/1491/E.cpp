#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=200005;

vector<pii> e[N],info;
int n,vis[N],sz[N],rt,f[55];
void GG(){
	puts("NO");
	exit(0);
}
void dfs(int x,int fa,int n){
	sz[x]=1;
	int mx=0;
	for (auto i:e[x])
		if (i.fi!=fa&&!vis[i.se]){
			dfs(i.fi,x,n);
			sz[x]+=sz[i.fi];
			mx=max(mx,sz[i.fi]);
		}
	if (sz[x]*2>=n&&mx*2<n)
		rt=x;
}
void dfs2(int x,int fa,int n){
	sz[x]=1;
	for (auto i:e[x])
		if (i.fi!=fa&&!vis[i.se]){
			dfs2(i.fi,x,n);
			sz[x]+=sz[i.fi];
			if (sz[i.fi]==n)
				info.PB(i);
		}
}
void solve(int x,int n){
	if (n<=3) return;
	int p=lower_bound(f+1,f+31,n)-f;
	if (f[p]!=n) GG();
	dfs(x,0,n); x=rt;
	info.resize(0);
	dfs2(x,0,f[p-2]);
	if (!info.size()) GG();
	for (auto i:info) vis[i.se]=1;
	if (info.size()==1){
		int p1=info[0].fi;
		solve(p1,f[p-2]);
		solve(x,f[p-1]);
	}
	else{
		int p1=info[0].fi;
		int p2=info[1].fi;
		solve(p1,f[p-2]);
		solve(p2,f[p-2]);
		solve(x,f[p-3]);
	}
}
int main(){
	f[0]=f[1]=1;
	For(i,2,30) f[i]=f[i-1]+f[i-2];
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(pii(y,i));
		e[y].PB(pii(x,i));
	}
	solve(1,n);
	puts("YES");
}