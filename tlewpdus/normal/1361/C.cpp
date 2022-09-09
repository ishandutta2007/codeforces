#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

void pung() {
	puts("-1");
	exit(0);
}

struct UNF {
	int par[1130000];
	int c;
	void init(int n) {
		for (int i=0;i<n;i++) par[i] = i;
		c = n;
	}
	int fin(int a) {
		return par[a] = (par[a]==a?a:fin(par[a]));
	}
	void uni(int a, int b) {
		a = fin(a); b = fin(b);
		if (a==b) return;
		par[fin(a)] = fin(b);
		c--;
	}
} unf;

int n;
vector<pii> lis[1130000];
int idx[1130000];
int echk[1130000];
int arr[1100000];

void init() {
	for (int i=0;i<1100000;i++) {
		idx[i] = -1;
		lis[i].clear();
		echk[i] = 0;
	}
}

vector<int> st;
void dfs(int here) {
//	printf("%d : %d\n",here,idx[here]);
//	printf("%d!!\n",(int)lis[here].size());
	for (++idx[here];idx[here]<(int)lis[here].size();idx[here]++) {
//		printf("%d!\n",idx[here]);
		if (echk[lis[here][idx[here]].first]) continue;
		echk[lis[here][idx[here]].first] = 1;
//		printf(" -> %d (%d)\n",lis[here][idx[here]].second,idx[here]);
		dfs(lis[here][idx[here]].second);
	}
//	printf("push %d\n",here);
	st.push_back(here);
}

void solve() {
	init();
	int a, b;
	scanf("%d%d",&a,&b);
	for (int i=0;i<b;i++) {
		int e, q;
		scanf("%d%d",&e,&q); e--; q--;
		lis[e].push_back({i,q});
		lis[q].push_back({i,e});
	}
	dfs(0);
	for (int i=0;i<b;i++) {
		printf("%d ",st[i]+1);
	}puts("");
	exit(0);
}

int cnt[1130000];
int main(){
//	solve();
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d%d",&arr[i*2],&arr[i*2+1]);
	}
	int k = 0;
	for (k=1;k<=20;k++) {
		unf.init(1<<k);
		int mod = (1<<k);
		for (int i=0;i<mod;i++) cnt[i] = 0;
		for (int i=0;i<n;i++) {
			unf.uni(arr[2*i]%mod,arr[2*i+1]%mod);
			cnt[arr[2*i]%mod]++;
			cnt[arr[2*i+1]%mod]++;
		}
		int mang = 0, tp = -1;
		for (int i=0;i<mod;i++) {
			if (cnt[i]%2) mang = 1;
			if (cnt[i]) {
				if (tp!=-1 && tp!=unf.fin(i)) mang = 1;
				tp = unf.fin(i);
			}
		}
		if (mang) break;
	}
	printf("%d\n",k-1);
	int mod = (1<<(k-1));
	for (int i=0;i<mod;i++) cnt[i] = 0;
	multimap<pii,int> mpi;
	init();
	for (int i=0;i<n;i++) {
		int u = arr[2*i]%mod, v = arr[2*i+1]%mod;
//		printf("%d <-> %d\n",u,v);
		lis[u].push_back({i,v});
		lis[v].push_back({i,u});
		mpi.insert(pair<pii,int>({u,v},i+1));
		mpi.insert(pair<pii,int>({v,u},-i-1));
		cnt[u]++; cnt[v]++;
	}
	for (int i=0;i<mod;i++) {
		if (!cnt[i]) continue;
		dfs(i);
		break;
	}
	for (int i=0;i<=n;i++) cnt[i] = 0;
	for (int i=0;i<n;i++) {
		int u = st[i], v = st[(i+1)%n];
		auto it = mpi.find({u,v});
		while(cnt[abs(it->second)]) {
			mpi.erase(it);
			it = mpi.find({u,v});
		}
		cnt[abs(it->second)] = 1;
		if (it->second>0) {
			printf("%d %d ",it->second*2-1,it->second*2);
		}
		else {
			printf("%d %d ",-it->second*2,-it->second*2-1);
		}
		mpi.erase(it);
	}

	return 0;
}