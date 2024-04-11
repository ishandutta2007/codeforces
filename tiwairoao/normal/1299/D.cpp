#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD = int(1E9) + 7;

int pow_mod(int b, int p) {
	int ret = 1;
	for(int i=p;i;i>>=1,b=1LL*b*b%MOD)
		if( i & 1 ) ret = 1LL*ret*b%MOD;
	return ret;
}

struct node{
	int a[5], siz; node() {siz = 0; for(int i=0;i<5;i++) a[i] = 0;}
	friend bool operator < (node a, node b) {
		if( a.siz < b.siz ) return true;
		else if( a.siz > b.siz ) return false;
		for(int i=0;i<=4;i++) {
			if( a.a[i] < b.a[i] ) return true;
			else if( a.a[i] > b.a[i] ) return false;
		}
		return false;
	}
	bool insert(int x) {
		for(int i=4;i>=0;i--) {
			if( (x >> i) & 1 ) {
				if( a[i] ) x ^= a[i];
				else {
					a[i] = x; siz++;
					return true;
				}
			}
		}
		return false;
	}
	void maintain() {
		for(int i=4;i>=0;i--)
			if( a[i] ) {
				for(int j=i-1;j>=0;j--)
					if( (a[j] >> i) & 1 ) a[j] ^= a[i];
			}
	}
};

vector<node>vec;
map<node, int>mp; int cnt;
void dfs(node a) {
	a.maintain();
	if( mp.count(a) ) return ;
	mp[a] = (int)vec.size(), vec.push_back(a);
	for(int i=0;i<32;i++) {
		node b = a; b.insert(i);
		dfs(b);
	}
}
void init() {
	node t; dfs(t); cnt = vec.size(); sort(vec.begin(), vec.end());
	for(int i=0;i<vec.size();i++)
		mp[vec[i]] = i;
}

const int MAXN = 100000;

struct edge{
	int to, val;
	edge *nxt;
}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt = edges;
void addedge(int u, int v, int w) {
	edge *p = (++ecnt);
	p->to = v, p->val = w, p->nxt = adj[u], adj[u] = p;
	p = (++ecnt);
	p->to = u, p->val = w, p->nxt = adj[v], adj[v] = p;
}

node nd[MAXN + 5]; bool is[MAXN + 5]; int nw;
int tag[MAXN + 5], tmp[MAXN + 5], val[MAXN + 5];
int arr[MAXN + 5], dfn[MAXN + 5], dcnt = 0;

void dfs2(int x, int fa) {
	dfn[x] = (++dcnt);
	for(edge *p=adj[x];p;p=p->nxt) {
		if( p->to == fa || p->to == 1 ) continue;
		if( dfn[p->to] ) {
			if( dfn[p->to] < dfn[x] ) {
				int k = arr[x] ^ arr[p->to] ^ p->val;
				if( !nd[nw].insert(k) )
					is[nw] = true;
			}
		}
		else arr[p->to] = arr[x] ^ p->val, dfs2(p->to, x);
	}
}

int n, m;

int dp[5000], f[5000], num[5000], num2[5000];
int main() {
	init();
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
	}
	for(int i=1;i<=n;i++)
		tmp[i] = tag[i] = -1;
	for(edge *p=adj[1];p;p=p->nxt)
		tmp[p->to] = p->val, tag[p->to] = 0;
	for(int i=1;i<=n;i++) {
		if( tag[i] == -1 ) continue;
		if( tag[i] == 1 )
			nw = i, dfs2(i, 0);
		else {
			for(edge *p=adj[i];p;p=p->nxt) {
				if( tag[p->to] == 0 ) {
					tag[p->to] = 1, tag[i] = 2;
					val[p->to] = tmp[i] ^ tmp[p->to] ^ p->val;
					break;
				}
			}
			if( tag[i] == 0 )
				nw = i, dfs2(i, 0);
		}
	}
	
	int t = 1;
	for(edge *p=adj[1];p;p=p->nxt) {
		if( tag[p->to] == 0 ) {
			if( is[p->to] ) continue;
			if( nd[p->to].siz == 0 ) t = (2LL * t) % MOD;
			else num[mp[nd[p->to]]]++;
		}
		else if( tag[p->to] == 1 ) {
			if( is[p->to] ) continue;
			if( nd[p->to].siz == 0 ) num2[val[p->to]]++;
			else {
				num[mp[nd[p->to]]] += 2;
				if( nd[p->to].insert(val[p->to]) )
					num[mp[nd[p->to]]]++;
			}
		}
	}
	
	dp[0] = 1;
	for(int j=0;j<cnt;j++) {
		if( !num[j] ) continue;
		for(int i=cnt-1;i>=0;i--) {
			if( !dp[i] ) continue;
			if( vec[i].siz + vec[j].siz <= 5 ) {
				bool flag = true; node p = vec[j];
				for(int k=0;k<5;k++)
					if( vec[i].a[k] )
						flag &= p.insert(vec[i].a[k]);
				if( flag ) {
					int l = mp[p];
					dp[l] = (dp[l] + 1LL*num[j]*dp[i]%MOD)%MOD;
				}
			}
		}
	}
	for(int j=0;j<32;j++) {
		if( !num2[j] ) continue;
		for(int i=cnt;i>=0;i--) {
			node p = vec[i];
			if( p.insert(j) )
				dp[mp[p]] = (dp[mp[p]] + 1LL*num2[j]*dp[i]%MOD*pow_mod(3, num2[j]-1)) % MOD;
			dp[i] = 1LL * pow_mod(3, num2[j]) * dp[i] % MOD;
		}
	}
	int ans = 0;
	for(int i=0;i<cnt;i++)
		ans = (ans + dp[i]) % MOD;
	printf("%lld\n", 1LL*ans*t%MOD);
}