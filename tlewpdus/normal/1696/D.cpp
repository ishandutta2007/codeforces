#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
int A[300100];

struct idxtree {
	int tree[530000];
	int key;
	void init() {
		key = 1;
		while(key<N) key*=2;
		for (int i=0;i<key*2;i++) tree[i] = -INF;
	}
	void upd(int idx, int val) {
		idx += key;
		while(idx) {
			tree[idx] = max(tree[idx],val);
			idx /= 2;
		}
	}
	int getv(int s, int e) {
		s+=key;e+=key;
		int ans = -INF;
		while(s<=e) {
			if (s&1) ans = max(ans,tree[s]);
			if (~e&1) ans = max(ans,tree[e]);
			s =(s+1)/2;
			e =(e-1)/2;
		}
		return ans;
	}
	int getl(int idx, int val) {
		if (getv(idx,N-1)<=val) return N;
		idx += key;
		while(tree[idx]<=val) {
			idx = (idx+1)/2;
		}
		while(idx<key) {
			if (tree[idx*2]>val) idx=idx*2;
			else idx=idx*2+1;
		}
		return idx-key;
	}
} segmin, segmax;

int loc[300100];

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) {
			scanf("%d",&A[i]);
			loc[A[i]] = i;
		}
		if (N==1) {
			puts("0");
			continue;
		}
		segmin.init();
		segmax.init();
		for (int i=0;i<N;i++) {
			segmax.upd(i,A[i]);
			segmin.upd(i,-A[i]);
		}
		int cur = 0, jump = 0;
		while(cur<N-1) {
			if (A[cur]<A[cur+1]) {
				int r = segmin.getl(cur,-A[cur]);
				if (r==cur) cur++;
				else {
					cur = loc[segmax.getv(cur,r-1)];
				}
//				printf("%d, %d\n",r,cur);
				jump++;
			}
			else {
				int r = segmax.getl(cur,A[cur]);
				if (r==cur) {
					cur++;
				}else {
					cur = loc[-segmin.getv(cur, r - 1)];
				}
//				printf("%d, %d\n",r,cur);
				jump++;
			}
		}
		printf("%d\n",jump);
	}

	return 0;
}