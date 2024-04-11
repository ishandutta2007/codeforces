#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, K;
struct segtree {
	int tree[530000];
	int rem[530000];

	void pd(int idx) {
		if (rem[idx]) {
			tree[idx*2] += rem[idx];
			tree[idx*2+1]+=rem[idx];
			rem[idx*2]+=rem[idx];
			rem[idx*2+1]+=rem[idx];
			rem[idx]=0;
		}
	}
	void pu(int idx) {
		tree[idx] = max(tree[idx*2],tree[idx*2+1]);
	}
	void upd(int S, int E, int val, int s=0, int e=N-1, int idx=1) {
		if (e<S||E<s) return;
		if (S<=s&&e<=E) {
			tree[idx]+=val;
			rem[idx]+=val;
			return;
		}
		int m = (s+e)/2;
		pd(idx);
		upd(S,E,val,s,m,idx*2);
		upd(S,E,val,m+1,e,idx*2+1);
		pu(idx);
	}
	int getm(int s=0, int e=N-1, int idx=1) {
		if (s==e) return s;
		int m = (s+e)/2;
		pd(idx);
		if (tree[idx*2]>tree[idx*2+1]) return getm(s,m,idx*2);
		return getm(m+1,e,idx*2+1);
	}
} seg;

vector<int> lis[200100];
int st[200100], en[200100], par[200100], lab[200100];

int tim;
void dfs(int here, int p) {
	st[here] = tim++;
	lab[tim-1] = here;
	par[here] = p;
	for (int &there : lis[here]) {
		if (there!=p) {
			dfs(there, here);
		}
	}
	en[here] = tim-1;
	seg.upd(st[here],en[here],1);
}

ll calc(int r, int b) {
	return 1LL*(N-r-b)*(r-b);
}

int col[200100];

int main() {
	scanf("%d%d",&N,&K);
	for (int i=0;i<N;i++) col[i] = 1;
	for (int i=0;i<N-1;i++) {
		int a, b;
		scanf("%d%d",&a,&b); a--; b--;
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
	dfs(0,-1);
	int bm = N/2;
	ll ans = calc(0,bm);
	int cnt = N;
	for (int r=1;r<=K;r++) {
		int cur = lab[seg.getm()];
//		printf("%d!!\n",cur+1);
		while(cur>=0 && col[cur]) {
			seg.upd(st[cur],en[cur],-1);
			col[cur] = 0;
//			printf("%d el\n",cur+1);
			cur = par[cur];
			cnt--;
		}
//		printf("%d, %d\n",r,cnt);
		ans = max(ans, calc(r, min(cnt,bm)));
	}
	printf("%lld\n",ans);

	return 0;
}