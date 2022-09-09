#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9+7;

int n;
vector<int> lis[500100];
int nxt[1000100], pre[1000100];
int dep[500100];
int tar[500100];
int cnt[1000100];
int fir[500100], last[500100];
ll fac[500100];
int sps[500100][20];

void pung() {
	puts("0");
	exit(0);
}

void dfs(int here, int p) {
	sort(lis[here].begin(),lis[here].end());
	dep[here] = (~p?dep[p]:-1)+1;
	sps[here][0] = p;
	for (int &there : lis[here]) {
		if (there!=p) dfs(there,here);
	}
}

int lca(int u, int v) {
	if (dep[u]>dep[v]) swap(u,v);
	int td = dep[v]-dep[u];
	for (int i=0;i<20;i++) if (td>>i&1) v = sps[v][i];
	if (u==v) return u;
	for (int i=19;i>=0;i--) {
		if (sps[u][i]!=sps[v][i]) u=sps[u][i],v=sps[v][i];
	}
	return sps[u][0];
}

int dis(int u, int v) {
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}

map<pii,int> e_num;
void mark(int u, int v) {
	vector<int> ord;
	int l = lca(u,v);
	int sz = dep[u]-dep[l];
	while(l!=u) {
		ord.push_back(u);
		u = sps[u][0];
	}
	while(l!=v) {
		ord.push_back(v);
		v = sps[v][0];
	}
	ord.push_back(l);
	reverse(ord.begin()+sz,ord.end());
	int c = e_num[{ord[0],ord[1]}];
	if (~pre[c]&&pre[c]!=0) pung();
	pre[c] = 0;
	fir[ord[0]] = ord[1];
	c = e_num[{ord.back(),ord[(int)ord.size()-2]}];
	if (~nxt[c]&&nxt[c]!=1) pung();
	last[ord.back()] = ord[(int)ord.size()-2];
	nxt[c] = 1;
	for (int i=1;i+1<ord.size();i++) {
		int c1 = e_num[{ord[i],ord[i-1]}];
		int c2 = e_num[{ord[i],ord[i+1]}];
		if (~nxt[c1]&&nxt[c1]!=c2) pung();
		if (~pre[c2]&&pre[c2]!=c1) pung();
		nxt[c1] = c2; pre[c2] = c1;
	}
	for (int &v : ord) cnt[v]++;
}

int chk[1000100];
int main() {
	scanf("%d",&n);
	for (int i=0;i<n-1;i++) {
		int a, b;
		scanf("%d%d",&a,&b); --a; --b;
		lis[a].push_back(b);
		lis[b].push_back(a);
		e_num[pii(a,b)] = i*2+2;
		e_num[pii(b,a)] = i*2+3;
	}
	memset(tar,-1,sizeof(tar));
	memset(nxt,-1,sizeof(nxt));
	memset(pre,-1,sizeof(pre));
	memset(fir,-1,sizeof(fir));
	memset(last,-1,sizeof(last));
	for (int i=0;i<n;i++) {
		scanf("%d",&tar[i]); tar[i]--;
	}
	dfs(0,-1);
	for (int j=1;j<20;j++) {
		for (int i=0;i<n;i++) sps[i][j] = (~sps[i][j-1]?sps[sps[i][j-1]][j-1]:-1);
	}
	ll sum = 0;
	for (int i=0;i<n;i++) {
		if (~tar[i]) sum += dis(i,tar[i]);
		if (i==tar[i]) pung();
	}
	if (sum>2*n) pung();
	for (int i=0;i<n;i++) {
		if (~tar[i]) mark(i,tar[i]);
	}
	fac[0] = 1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;

	for (int i=0;i<n;i++) {
		for (int &j : lis[i]) {
			int v = e_num[{i,j}];
			if (chk[v]) continue;
			int rv = v;
			do {
				chk[v]  = 1;
				v = nxt[v];
			} while(~v&&!chk[v]);
			if (v==rv) pung();
		}
	}
	for (int i=0;i<n;i++) {
		if (fir[i]<0||last[i]<0) continue;
		int v = e_num[{i,fir[i]}], c = 1, lv = e_num[{i,last[i]}];
		while(v!=lv&&v>=0) {
			v=nxt[v];
			c++;
		}
		if (v==lv&&c!=lis[i].size()) pung();
	}

	ll res = 1;
	for (int i=0;i<n;i++) {
		res = res*fac[max(0,(int)lis[i].size()-cnt[i])]%MOD;
	}
	printf("%lld\n",res);

	return 0;
}