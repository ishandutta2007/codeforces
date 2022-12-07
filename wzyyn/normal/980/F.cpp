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
const int N=1000005;
int n,m,nd;
int par[N],sub[N];
int q[N],qq[N],v[N];
int dep[N],fa[N],vis[N];
vector<int> e[N],E[N];
void dfs(int x){
	dep[x]=dep[fa[x]]+1;
	for (auto i:e[x])
		if (i!=fa[x]){
			if (!dep[i]){
				fa[i]=x;
				dfs(i);
				if (!vis[i]){
					E[x].PB(i);
					E[i].PB(x);
				}
			}
			else if (dep[i]<dep[x]){
				++nd;
				for (int y=x;;y=fa[y]){
					E[nd].PB(y);
					E[y].PB(nd);
					if (y==i) break;
					vis[y]=1;
				}
			}
		}
}
void dfs1(int x){
	for (auto i:E[x])
		if (i!=fa[x]){
			fa[i]=x;
			dfs1(i);
		}
	if (x>n){
		int sz=E[x].size();
		For(i,0,sz-2)
			sub[x]=max(sub[x],sub[E[x][i]]+min(sz-2-i,i));
	}
	else
		for (auto i:E[x]) if (i!=fa[x])
			sub[x]=max(sub[x],sub[i]+1);
}
void dfs2(int x){
	if (x<=n){
		int mx1=par[x],mx2=0;
		for (auto i:E[x])
			if (i!=fa[x])
				if (sub[i]+1>mx1) mx2=mx1,mx1=sub[i]+1;
				else mx2=max(mx2,sub[i]+1);
		for (auto i:E[x]) if (i!=fa[x])
			par[i]=(sub[i]+1==mx1?mx2:mx1)+(i<=n?1:0);
	}
	else{
		assert(E[x][E[x].size()-1]==fa[x]);
		int sz=E[x].size(),h=1,t=0;
		//cout<<sz<<endl;
		For(i,0,sz-1) q[i]=E[x][i],v[i]=(i==sz-1?par[x]:sub[q[i]]);
		Rep(i,sz/2+sz,sz){
			for (;h<=t&&v[i%sz]+i>v[qq[t]%sz]+qq[t];--t);
			qq[++t]=i;
		}
		Rep(i,sz-1,0){
			if (qq[h]-i>sz/2) ++h;
			assert(h<=t);
			if (i%sz!=sz-1) par[q[i]]=max(par[q[i]],v[qq[h]%sz]+qq[h]-i);
			for (;h<=t&&v[i%sz]+i>v[qq[t]%sz]+qq[t];--t);
			qq[++t]=i;
		}
		//For(i,0,sz-1) cout<<q[i]<<' '<<v[i]<<' '<<par[q[i]]<<endl;
		//puts("Bili");
		h=1; t=0;
		For(i,0,sz/2){
			for (;h<=t&&v[i%sz]-i>v[qq[t]%sz]-qq[t];--t);
			qq[++t]=i;
		}
		For(i,sz/2+1,sz/2+sz){
			if (i-qq[h]>sz/2) ++h;
			assert(h<=t);
			if (i%sz!=sz-1)	par[q[i%sz]]=max(par[q[i%sz]],v[qq[h]%sz]-qq[h]+i);
			for (;h<=t&&v[i%sz]-i>v[qq[t]%sz]-qq[t];--t);
			qq[++t]=i;
		}
		//For(i,0,sz-1) cout<<q[i]<<' '<<v[i]<<' '<<par[q[i]]<<endl;
		//puts("King");
	}
	for (auto i:E[x])
		if (i!=fa[x]) dfs2(i);
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	nd=n;
	dfs(1);
	dfs1(1);
	dfs2(1);
	For(i,1,n)
		printf("%d ",max(sub[i],par[i]));
}