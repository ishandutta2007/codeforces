#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;
typedef long long lli;
typedef pair<lli,int> pli;

const int MAX=1<<17;
struct seg_tr{
	lli tr[MAX<<1],lz[MAX<<1];
	seg_tr() {
		for(int i=1;i<MAX+MAX;i++) tr[i]=lz[i]=0;
	}
	void push(int cur,int s,int f) {
		tr[cur]+=lz[cur]*(f-s+1);
		if(cur<MAX) {
			lz[cur<<1]+=lz[cur];
			lz[(cur<<1)+1]+=lz[cur];
		}
		lz[cur]=0;
	}
	lli upd(int cur,int s,int f,int l,int r,lli val) {
		push(cur,s,f);
		if(f<l || s>r) return tr[cur];
		else if(l<=s && f<=r) {
			lz[cur]+=val;
			push(cur,s,f);
			return tr[cur];
		}
		else {
			int nx=cur<<1,md=(s+f)>>1;
			return tr[cur]=upd(nx,s,md,l,r,val)+upd(nx+1,md+1,f,l,r,val);
		}
	}
	lli find(int cur,int s,int f,int l,int r) {
		push(cur,s,f);
		if(f<l || s>r) return 0;
		else if(l<=s && f<=r) return tr[cur];
		else {
			int nx=cur<<1,md=(s+f)>>1;
			return find(nx,s,md,l,r)+find(nx+1,md+1,f,l,r);
		}
	}
	void upd(int l,int r,lli val) {
		if(l>r) return;
		upd(1,0,MAX-1,l,r,val);
	}
	lli query(int l,int r) {
		if(l>r) return 0;
		else return find(1,0,MAX-1,l,r);
	}
}tr;

int pa[100001][18],ll[100001],rr[100001],dist[100001],root=1,idx,n;
vector<int> adj[100001];
lli arr[100001];

void init_dfs(int cur,int p,int d) {
	pa[cur][0]=p;
	dist[cur]=d;
	ll[cur]=idx++;
	
	int pp=p,a=1;
	while(pp) {
		pa[cur][a]=pa[pp][a-1];
		pp=pa[pp][a-1]; a++;
	}

	for(auto &it:adj[cur]) {
		if(it==p) continue;
		init_dfs(it,cur,d+1);
	}
	rr[cur]=idx-1;
}
int lca(int u,int v) {
	if(dist[u]>dist[v]) swap(u,v);
	int d=dist[v]-dist[u];
	for(int i=0;1<<i <= d; i++) {
		if(d>>i & 1) v=pa[v][i];
	}
	
	if(u==v) return v;
	for(int i=17;i>=0;i--) if(pa[u][i]!=pa[v][i]) {
		u=pa[u][i]; v=pa[v][i];
	}
	return pa[v][0];
}
int lca2(int u,int v) {
	if(dist[u]>dist[v]) swap(u,v);
	int d=dist[v]-dist[u]-1;
	for(int i=0;1<<i <=d; i++) {
		if(d>>i & 1) v=pa[v][i];
	}
	return v;
}

int main() {
	int q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%lld",arr+i);
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	init_dfs(root,0,1);
	for(int i=1;i<=n;i++) tr.upd(ll[i],ll[i],arr[i]);

	while(q--) {
		int t,u,v;
		lli x;
		scanf("%d",&t);
		if(t==1) {
			scanf("%d",&u);
			root=u;
		}
		else if(t==2) {
			scanf("%d%d%lld",&u,&v,&x);
			
			int pp=lca(u,v);
			if(pp==root) {
				tr.upd(0,n-1,x);
			}
			else if(ll[pp]<=ll[root] && rr[root]<=rr[pp]) {
				int p1=lca(root,u),p2=lca(root,v);
				if(dist[p1]<dist[p2]) swap(p1,p2);
				if(p1==root) tr.upd(ll[1],rr[1],x);
				else {
					pp=lca2(p1,root);
					tr.upd(0,n-1,x);
					tr.upd(ll[pp],rr[pp],-x);
				}
			}
			else {
				tr.upd(ll[pp],rr[pp],x);
			}
		}
		else {
			scanf("%d",&v); 
			if(v==root) {
				printf("%lld\n",tr.query(0,n-1));
			}
			else if(ll[v]<=ll[root] && rr[root]<=rr[v]) {
				v=lca2(v,root);
				printf("%lld\n",tr.query(0,n-1)-tr.query(ll[v],rr[v]));
			}
			else {
				printf("%lld\n",tr.query(ll[v],rr[v]));
			}
		}
	}
	
	return 0;
}