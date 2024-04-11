#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
typedef long long ll;

const int MOD = 1e9+7;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int sub(int a, int b) { return a-b+(a-b<0)*MOD; }
int mult(int a, int b) { return (1LL*a*b)%MOD; }

int p[100013];
int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int a, int b) { p[find(a)] = find(b); }

int n,m;
vector<pair<int,ll> > adj[100013];
vector<pair<pair<int,int>,ll> > extra;

vector<pair<pair<int,int>,ll> > edges[100013];
ll path[100013];

vector<ll> basis;
int has[60][2];

void dfs(int x, int p=0) {
	for (int i=0;i<60;i++) {
		has[i][(path[x]&(1LL<<i))>0]+=1;
	}
	for (auto i: adj[x]) if (i.A!=p) {
		path[i.A] = path[x]^i.B;
		dfs(i.A,x);
	}
}

void insert(ll x) {
	for (ll i: basis) {
		if (x&i&-i) x^=i;
	}
	if (!x) return;
	for (ll& i: basis) {
		if (i&x&-x) i^=x;
	}
	basis.push_back(x);
}

int solve(int x) {
	memset(has,0,sizeof has);
	dfs(x);
	basis.clear();
	for (auto e: edges[x]) {
		ll cyc = path[e.A.A]^path[e.A.B];
		insert(cyc^e.B);
	}
	int res = 0;
	ll all = 0;
	for (ll i: basis) all|=i;
	for (int i=0;i<60;i++) {
		int cur = mult(has[i][0],has[i][1]);
		int num = basis.size();
		if (all&(1LL<<i)) {
			cur = (1LL*(has[i][0]+has[i][1])*(has[i][0]+has[i][1]-1)/2)%MOD;
			num-=1;
		}
		for (int j=0;j<num+i;j++) cur = mult(cur,2);
		res = add(res,cur);
	}
	return res;
}

int main() {
	scanf("%d%d",&n,&m);
	iota(p,p+n+1,0);
	while (m--) {
		int a,b;
		ll c;
		scanf("%d%d%lld",&a,&b,&c);
		if (find(a)==find(b)) {
			extra.push_back(MP(MP(a,b),c));
		} else {
			adj[a].push_back(MP(b,c));
			adj[b].push_back(MP(a,c));
			merge(a,b);
		}
	}
	for (auto e: extra) {
		edges[find(e.A.A)].push_back(e);
	}
	int ans = 0;
	for (int i=1;i<=n;i++) if (find(i)==i) {
		ans = add(ans,solve(i));
	}
	printf("%d\n",ans);

	return 0;
}