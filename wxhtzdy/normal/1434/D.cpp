#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=501000;
int n,m,x[N],y[N],tp[N];
vector<PII> g[N];
struct ST{
	struct node{
		int lzy,c[2];
	}nd[8*N];
	void upd(int p) {
		nd[p].c[0]=max(nd[p*2].c[0],nd[p*2+1].c[0]);
		nd[p].c[1]=max(nd[p*2].c[1],nd[p*2+1].c[1]);
	}
	void push(int p) {
		if (nd[p].lzy) {
			swap(nd[p].c[0],nd[p].c[1]);
			nd[p*2].lzy^=1;
			nd[p*2+1].lzy^=1;
			nd[p].lzy=0;
		}
	}
	int tin[N],tout[N],t,ord[N],rem[N],dep[N];
	void dfs(int u,int f) {
		tin[u]=++t;
		ord[t]=u;
		for (auto x:g[u]) {
			if (x.fi==f) continue;
			rem[x.fi]=(rem[u]+x.se)%2;
			dep[x.fi]=dep[u]+1;
			dfs(x.fi,u);
		}
		tout[u]=t;
	}
	void build(int p,int l,int r) {
		if (l==r) {
			nd[p].c[rem[ord[l]]]=dep[ord[l]];
//			printf("%d %d %d\n",l,ord[l],rem[ord[l]]);
			nd[p].c[rem[ord[l]]^1]=0;
		} else {
			int md=(l+r)>>1;
			build(p*2,l,md);
			build(p*2+1,md+1,r);
			upd(p);
		}
	}
	void modify(int p,int l,int r,int tl,int tr) {
		push(p);
		if (l>tr||r<tl) return;
		if (tl<=l&&r<=tr) {
			nd[p].lzy^=1;
			push(p);
		} else {
			int md=(l+r)>>1;
			modify(p*2,l,md,tl,tr);
			modify(p*2+1,md+1,r,tl,tr);
			upd(p);
		}
	}
	void upd(int x,int y) {
		if (tin[x]<tin[y]) swap(x,y);
		modify(1,1,t,tin[x],tout[x]);
	}
}ST1,ST2;
int d[N];
void dfs(int u,int f) {
	d[u]=(f==0?0:d[f]+1);
	for (auto x:g[u]) {
		if (x.fi==f) continue;
		dfs(x.fi,u);
	}
}
int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d%d",x+i,y+i,tp+i);
		g[x[i]].pb(mp(y[i],tp[i]));
		g[y[i]].pb(mp(x[i],tp[i]));
	}
	dfs(1,0);
	int u=1;
	rep(i,1,n+1) if (d[i]>d[u]) u=i;
	dfs(u,0);
	int v=1;
	rep(i,1,n+1) if (d[i]>d[v]) v=i;
	ST1.dfs(u,0);
	ST2.dfs(v,0);
	ST1.build(1,1,ST1.t);
	ST2.build(1,1,ST2.t);
//	printf(":D %d %d\n",u,v);
	scanf("%d",&m);
	while (m--) {
		int id;
		scanf("%d",&id);
		ST1.upd(x[id],y[id]);
		ST2.upd(x[id],y[id]);
		printf("%d\n",max(ST1.nd[1].c[0],ST2.nd[1].c[0]));
	}
}