#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=4000;
int n,m,tsz=1,pv[N],q;
vector<PII> pp[N];
PII que[N];
struct edge{
	int to,cap;
};
vector<edge> e[N];
int idx[N][N];
bool was[N];
int bfs(int s,int t) {
	rep(i,0,t+1) was[i]=0;
	q=0,que[q]=mp(s,1e9);
	was[s]=1;
	rep(b,0,q+1) {
		int x=que[b].fi,flow=que[b].se;
		rep(i,0,SZ(e[x])) {
			edge p=e[x][i];
			if (!was[p.to]&&p.cap>0) {
				int new_flow=min(flow,p.cap);
				que[++q]=mp(p.to,new_flow);
				was[p.to]=1;
				pv[p.to]=x;
				if (p.to==t) return new_flow;
			}
		}
	}
	return 0;
}

int solve(int s,int t) {
	int flow=0,new_flow=0;
	while (new_flow=bfs(s,t)) {
		flow+=new_flow;
		int x=t;
		while (x!=s) {
			e[pv[x]][idx[pv[x]][x]].cap-=new_flow;
			e[x][idx[x][pv[x]]].cap+=new_flow;
			x=pv[x];
		}
	}
	return flow;
}

void adde(int x,int y,int c) {
//	printf("adde %d %d %d\n",x,y,c);
//	fflush(stdout);
	idx[x][y]=SZ(e[x]);
	e[x].pb({y,c});
	idx[y][x]=SZ(e[y]);
	e[y].pb({x,0});
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		int x;
		scanf("%d",&x);
		for (int j=2;j*j<=x;j++) {
			while (x%j==0) {
				pp[i].pb(mp(tsz,j)),++tsz,x/=j;
			}
		}
		if (x>1) pp[i].pb(mp(tsz,x)),++tsz;
	}
	while (m--) {
		int x,y;
		scanf("%d%d",&x,&y);
		--x; --y;
		if (x&1) swap(x,y);
		for (auto& px:pp[x]) for (auto& py:pp[y]) {
			if (px.se==py.se) adde(px.fi,py.fi,1);
		}
	}
	int src=0,sink=tsz;
	rep(i,0,n)  {
		for (auto& p:pp[i]) {
			if (i%2==0) adde(src,p.fi,1);
			else adde(p.fi,sink,1);
		}
	}
	printf("%d",solve(src,sink));
}