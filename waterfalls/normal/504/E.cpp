#include <bits/stdc++.h>
using namespace std;

#define hash hash_
#define MP make_pair
#define A first
#define B second
typedef long long ll;

#define MAXN 300013
#define MAXM 1000013

struct Query { int a,b,c,d,l1,l2; };

const int MOD = 1000000123;
const int BASE = 29;
const int INV = 758620783;
int powB[MAXN],powI[MAXN];

int n,m;
char s[MAXN];
vector<int> adj[MAXN];

int up[19][MAXN];
int h[MAXN];
inline int go(int a, int d) {
	int i = 0;
	while (d) {
		if (d&1) a = up[i][a];
		d>>=1, i+=1;
	}
	return a;
}
inline int lca(int a, int b) {
	if (h[a]>h[b]) swap(a,b);
	b = go(b,h[b]-h[a]);
	if (a==b) return a;
	for (int i=18;i>=0;i--) if (up[i][a]!=up[i][b]) a = up[i][a], b = up[i][b];
	return up[0][a];
}

vector<int> topo;
int hash[MAXN],hsah[MAXN];
inline void dfs(int x, int p=0) {
	up[0][x] = p;
	h[x] = h[p]+1;
	topo.push_back(x);
	hash[x] = ((ll) (s[x]-'a'+1)*powB[h[x]]+hash[p])%MOD;
	hsah[x] = ((ll) hsah[p]*BASE+(s[x]-'a'+1))%MOD;
	for (int i: adj[x]) if (i!=p) dfs(i,x);
}

inline void build() {
	powB[0] = 1;
	for (int i=1;i<MAXN;i++) powB[i] = ((ll) BASE*powB[i-1])%MOD;
	powI[0] = 1;
	for (int i=1;i<MAXN;i++) powI[i] = ((ll) INV*powI[i-1])%MOD;
	h[0] = -1;
	dfs(1);
	for (int i=1;i<19;i++) for (int j=1;j<=n;j++) {
		up[i][j] = up[i-1][up[i-1][j]];
	}
}

inline int get(int a, int l, int b, int len) {
	if (len<=h[a]-h[l]+1) {
		b = up[0][b];
		return ((ll) (hash[a]-hash[b]+MOD)*powI[h[b]+1])%MOD;
	} else {
		int p = l;
		l = up[0][l];
		int fac = (h[b]-2*h[l]-2>=0) ? powB[h[b]-2*h[l]-2] : powI[2*h[l]+2-h[b]];
		int res = ((ll) (hash[a]-hash[p])*fac+hsah[b]-(ll) hsah[l]*powB[h[b]-h[l]])%MOD;
		if (res<0) res+=MOD;
		return res;
	}
}

Query q[MAXM];
pair<int,int> bound[MAXM];
int len[MAXM][2];
int res[2*MAXM];
int last[MAXN];
vector<pair<int,int> > need[MAXN];
inline void solve() {
	for (int i=0;i<m;i++) {
		q[i].l1 = lca(q[i].a,q[i].b);
		q[i].l2 = lca(q[i].c,q[i].d);
		len[i][0] = h[q[i].a]+h[q[i].b]-2*h[q[i].l1]+1;
		len[i][1] = h[q[i].c]+h[q[i].d]-2*h[q[i].l2]+1;
		bound[i] = MP(0,min(len[i][0],len[i][1])+1);
	}
	for (int r=0;r<19;r++) {
		for (int i=1;i<=n;i++) need[i].clear();
		for (int i=0;i<m;i++) if (bound[i].B-bound[i].A>1) {
			int mid = (bound[i].A+bound[i].B)/2;
			if (mid<=h[q[i].a]-h[q[i].l1]+1) need[q[i].a].push_back(MP(mid-1,i*2));
			else need[q[i].b].push_back(MP(len[i][0]-mid,i*2));
			if (mid<=h[q[i].c]-h[q[i].l2]+1) need[q[i].c].push_back(MP(mid-1,i*2+1));
			else need[q[i].d].push_back(MP(len[i][1]-mid,i*2+1));
		}
		for (int i: topo) {
			last[h[i]] = i;
			for (auto j: need[i]) {
				res[j.B] = last[h[i]-j.A];
			}
		}
		for (int i=0;i<m;i++) if (bound[i].B-bound[i].A>1) {
			int mid = (bound[i].A+bound[i].B)/2;
			int one = get(q[i].a,q[i].l1,res[2*i],mid);
			int two = get(q[i].c,q[i].l2,res[2*i+1],mid);
			if (one==two) bound[i].A = mid;
			else bound[i].B = mid;
		}
	}
}

inline int readint() {
	char c;
	while ((c=getchar())<'0') continue;
	int ress = c-'0';
	while ((c=getchar())>='0') ress = ress*10+c-'0';
	return ress;
}

int main() {
	n = readint();
	for (int i=1;i<=n;i++) s[i] = getchar();
	for (int i=1;i<n;i++) {
		int u = readint(), v = readint();
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	build();
	m = readint();
	for (int i=0;i<m;i++) {
		q[i].a = readint(), q[i].b = readint(), q[i].c = readint(), q[i].d = readint();
	}
	solve();
	for (int i=0;i<m;i++) printf("%d\n",bound[i].A);

	return 0;
}