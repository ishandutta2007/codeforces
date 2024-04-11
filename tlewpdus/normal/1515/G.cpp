#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int N, M;
vector<pll> lis[200100], ris[200100];
int st[200100], en[200100];
ll dep[200100];

ll mgcd(ll a, ll b) {
	if(!a) return b;
	return mgcd(b%a,a);
}

ll G[200100];
int scc[200100];
int vis[200100];
vector<int> ord;
void idfs(int here) {
	vis[here]  = 1;
	for (pll &tmp : lis[here]) {
		if (vis[tmp.second]==0) idfs(tmp.second);
	}
	ord.push_back(here);
}
void rdfs(int here, int snum) {
	scc[here] = snum;
	vis[here] = 2;
	for (pll &tmp : ris[here]) {
		if (vis[tmp.second]==1) rdfs(tmp.second,snum);
	}
}

int tim;
void dfs(int here) {
	st[here] = tim++;
	for (pll &tmp : lis[here]) {
		if (st[tmp.second]==-1) {
			dep[tmp.second] = dep[here] + tmp.first;
			dfs(tmp.second);
		}
		else if (scc[tmp.second]==scc[here]) {
			G[scc[here]] = mgcd(G[scc[here]],abs(tmp.first+dep[here]-dep[tmp.second]));
		}
	}
	en[here] = tim-1;
}

int main () {
	memset(st,-1,sizeof(st));
	memset(en,-1,sizeof(en));
	scanf("%d%d",&N,&M);
	for (int i=0;i<M;i++) {
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c); --a; --b;
		lis[a].emplace_back(c,b);
		ris[b].emplace_back(c,a);
	}
	for (int i=0;i<N;i++) if (vis[i]==0) idfs(i);
	int snum = 0;
	reverse(ord.begin(),ord.end());
	vector<int> c;
	for (int &i : ord) {
		if (vis[i]==1) {
			rdfs(i,snum);
			c.push_back(i);
			snum++;
		}
	}
	reverse(c.begin(),c.end());
	for (int &i : c) {
		if (st[i]==-1) {
			dfs(i);
		}
	}
	int q;
	scanf("%d",&q);
	for (int i=0;i<q;i++) {
		int v;
		ll s, t;
		scanf("%d%lld%lld",&v,&s,&t); v--;
		ll g = mgcd(G[scc[v]],t);
		if (s%g==0) puts("YES");
		else puts("NO");
	}

	return 0;
}