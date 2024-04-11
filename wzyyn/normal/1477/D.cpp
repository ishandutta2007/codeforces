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
const int N=500005;
int n,m,deg[N];
int vis[N],q[N],rem;
int ban[N],qq[N];
int perm1[N],perm2[N];
vector<int> e[N],vq[N],E[N],f[N];

int dfs(int x,int fa){
	f[x].PB(x);
	for (auto i:E[x])
		if (i!=fa){
			int v=dfs(i,x);
			if (v) f[x].PB(v);
		}
	if (f[x].size()==1) return x;
	return 0;
}
void solve(int x){
	int h=0,t=1;
	qq[t]=x; vis[x]=1;
	while (h!=t){
		int x=qq[++h];
		for (auto i:e[x]) ban[i]=1;
		int nt=0;
		For(i,1,*q)
			if (!ban[q[i]]){
				if (!vis[q[i]]){
					vis[q[i]]=1;
					qq[++t]=q[i];
					E[q[i]].PB(x);
					E[x].PB(q[i]);
				}
			}
			else q[++nt]=q[i];
		*q=nt;
		for (auto i:e[x]) ban[i]=0;
	}
	For(i,1,t) f[qq[i]].resize(0);
	if (dfs(qq[1],0))
		if (f[qq[1]].size()==1)
			f[E[qq[1]][0]].PB(qq[1]);
	For(i,1,t) if (f[qq[i]].size()!=1){
		//for (auto j:f[qq[i]]) cout<<j<<endl;
		For(j,0,f[qq[i]].size()-1){
			int p1=j,p2=(j+1)%f[qq[i]].size();
			perm1[f[qq[i]][p1]]=rem;
			perm2[f[qq[i]][p2]]=rem;
			--rem; 
		}
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) e[i].resize(0);
	For(i,1,n) E[i].resize(0);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,0,n) vq[i].resize(0);
	For(i,1,n) deg[i]=e[i].size(),vis[i]=0;
	For(i,1,n) vq[deg[i]].PB(i);
	rem=n;
	for (;rem;){
		int p=-1;
		for (auto i:vq[rem-1])
			if (deg[i]==rem-1)
				p=i;
		if (p==-1) break;
		perm1[p]=perm2[p]=rem;
		vis[p]=1; --rem;
		for (auto i:e[p])
			vq[--deg[i]].PB(i);
	}
	*q=0;
	For(i,1,n) if (!vis[i]) q[++*q]=i;
	For(i,1,n) if (!vis[i]) solve(i);
	For(i,1,n) printf("%d ",perm1[i]); puts("");
	For(i,1,n) printf("%d ",perm2[i]); puts(""); 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}