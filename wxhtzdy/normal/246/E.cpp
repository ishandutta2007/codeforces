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

const int N=101000;
int n,q,a[N],nxt,l[N],r[N],tsz,ans[N],dep[N],lst[N],t,rt;
map<string,int> hs;
VI e[N];
vector<PII> all[N];
vector<tuple<int,int,int>> qs[N];

struct node {
	int cc;
} nd[4*N];

void modify(int p,int l,int r,int tl,int x) {
	nd[p].cc+=x;
	if (l==r) {
	} else {
		int mid=l+r>>1;
		if (tl<=mid) modify(p*2,l,mid,tl,x);
		else modify(p*2+1,mid+1,r,tl,x);
	}
}

int get(int p,int l,int r,int tl,int tr) {
	if (l>r||l>tr||r<tl) return 0;
	if (tl<=l&&r<=tr) return nd[p].cc;
	int mid=l+r>>1;
	return get(p*2,l,mid,tl,tr)+get(p*2+1,mid+1,r,tl,tr);
}

void dfs(int u,int f) {
	l[u]=++t;
	for (int v:e[u]) if (v!=f) dep[v]=dep[u]+1,dfs(v,u);
	r[u]=t;
}

int main() {
	cin>>n;
	rep(i,1,n+1) {
		string s; cin>>s;
		if (!hs[s]) hs[s]=++nxt;
		a[i]=hs[s];
		int par; cin>>par;
		e[par].pb(i);
	}
	dfs(0,0);
	rep(i,1,n+1) all[dep[i]].pb({a[i],l[i]});
	cin>>q;
	rep(i,1,q+1) {
		int v,k;
		cin>>v>>k;
		if(dep[v]+k<=n) qs[dep[v]+k].pb({l[v],r[v],i});
	}
	rep(i,1,n+1) {
		vector<tuple<int,int,int,int>> ev;
		for (auto pp:all[i]) {
			ev.pb({1,pp.se,pp.fi,0});
		}
		for (auto pp:qs[i]) {
			ev.pb({2,get<1>(pp),get<0>(pp),get<2>(pp)});
		}
		sort(all(ev),[&](tuple<int,int,int,int> x,tuple<int,int,int,int> y) {
			if (get<1>(x)==get<1>(y)) return get<0>(x)<get<0>(y);
			else return get<1>(x)<get<1>(y);
		});
		VI todo;
		for (auto pp:ev) {
			if (get<0>(pp)==1) {
				modify(1,1,n,get<1>(pp),1);
				if (lst[get<2>(pp)]) modify(1,1,n,lst[get<2>(pp)],-1);
				lst[get<2>(pp)]=get<1>(pp);
				todo.pb(get<2>(pp));
			} else {
				ans[get<3>(pp)]=get(1,1,n,get<2>(pp),get<1>(pp));
			}
		}
		for (auto pp:todo) {
			if (lst[pp]>0) {
				modify(1,1,n,lst[pp],-1);
				lst[pp]=0;
			}
		}
	}
	rep(i,1,q+1) cout<<ans[i]<<"\n";
}