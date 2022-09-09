#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int N, Q;
struct segtree {
	int tree[1050000];
	void pu(int idx) {
		tree[idx] = tree[idx*2]+tree[idx*2+1];
	}
	void init(int s=0, int e=N+1, int idx=1) {
		if (s==e) {
			if (s==N+1) tree[idx] = INF;
			else if (s==0) tree[idx] = -1;
			else tree[idx] = 0;
			return;
		}
		int m = (s+e)/2;
		init(s,m,idx*2);
		init(m+1,e,idx*2+1);
		pu(idx);
	}
	void upd(int loc, int val, int s=0, int e=N+1, int idx=1) {
		if (s==e) {
			tree[idx] += val;
			return;
		}
		int m = (s+e)/2;
		if (loc<=m) upd(loc,val,s,m,idx*2);
		else upd(loc,val,m+1,e,idx*2+1);
		pu(idx);
	}
	void updl(int K, int s=0, int e=N+1, int idx=1) {
		if (s==e) {
			tree[idx]++;
			return;
		}
		int m = (s+e)/2;
		if (K<=tree[idx*2]) updl(K,s,m,idx*2);
		else updl(K-tree[idx*2],m+1,e,idx*2+1);
		pu(idx);
	}
	int getv(int S, int E, int s=0, int e=N+1, int idx=1) {
		if (e<S||E<s) return 0;
		if (S<=s&&e<=E) return tree[idx];
		int m = (s+e)/2;
		return getv(S,E,s,m,idx*2)+getv(S,E,m+1,e,idx*2+1);
	}
} seg;

int A[300100];
vector<pii> que[300100];
int ans[300100];

int main() {
	scanf("%d%d",&N,&Q);
	seg.init();
	for (int i=1;i<=N;i++) {
		scanf("%d",&A[i]);
	}
	for (int i=0;i<Q;i++) {
		int x, y;
		scanf("%d%d",&x,&y);
		que[N-y].emplace_back(N-x,i);
	}
	for (int i=1;i<=N;i++) {
		seg.upd(N-i+1,1);
		seg.upd(N-i+2,-1);
		if (i-A[i]>=0) {
			seg.updl(i-A[i]);
		}
		for (pii &e : que[i]) {
			ans[e.second] = seg.getv(0,e.first);
		}
	}
	for (int i=0;i<Q;i++) {
		printf("%d\n",ans[i]);
	}

	return 0;
}