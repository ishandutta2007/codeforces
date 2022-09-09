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
int X[100100], Y[100100], C[100100];
int RX[100100], RY[100100], RC[100100];

struct segtree {
	int tree[100100];
	void init() {
		for (int i=0;i<=N;i++) tree[i] = 0;
	}
	void upd(int idx) {
		idx++;
		while(idx<=N) {
			tree[idx]++;
			idx += idx&-idx;
		}
	}
	int getr(int val) {
		int cur = 0;
		for (int i=18;i>=0;i--) {
			int jump = (1<<i);
			if (cur+jump<=N && tree[cur+jump]<=val) {
				val -= tree[cur+jump];
				cur += jump;
			}
		}
		return cur-1;
	}
	int getv(int idx) {
		idx++;
		int ans = 0;
		while(idx) {
			ans += tree[idx];
			idx -= idx&-idx;
		}
		return ans;
	}
} t23, t2;

int ord[100100];
int solveT() {
	iota(ord,ord+N,0);
	sort(ord,ord+N,[](int a, int b){
		return X[a]<X[b] || (X[a]==X[b] && C[a]>C[b]);
	});
	int n1 = N/3, k3 = 0, maxi = 0;
	t23.init();
	t2.init();
	for (int id=N-1;id>=0;id--) {
		int i = ord[id];

		int ty = t23.getr(k3-1);
		int v2 = t2.getv(ty), v2p = t2.getv(ty+1);
		int v23= t23.getv(ty), v23p = t23.getv(ty+1);
		maxi = max(maxi,min(n1,max(min(v2,k3-(v23-v2)),min(v2p,k3-(v23p-v2p)))));

		n1 -= (C[i]==1);
		k3 += (C[i]==3);
		if (C[i]==2) {t2.upd(Y[i]); t23.upd(Y[i]);}
		if (C[i]==3) {t23.upd(Y[i]);}
	}
	return maxi;
}

int solveI() {
	iota(ord,ord+N,0);
	sort(ord,ord+N,[](int a, int b){
		return X[a]<X[b] || (X[a]==X[b] && C[a]>C[b]);
	});
	int n1 = N/3, k3 = 0, maxi = 0;
	t23.init();
	t2.init();
	for (int id=N-1;id>=0;id--) {
		int i = ord[id];

		int ty = t23.getr(k3-1);
		int v2 = t2.getv(ty), v2p = t2.getv(ty+1);
		int v23= t23.getv(ty), v23p = t23.getv(ty+1);
		maxi = max(maxi,min(n1,max(min(v2,k3-(v23-v2)),min(v2p,k3-(v23p-v2p)))));

		n1 -= (C[i]==1);
		k3 += (C[i]==3);
		if (C[i]==2) {t2.upd(X[i]); t23.upd(X[i]);}
		if (C[i]==3) {t23.upd(X[i]);}
	}
	return maxi;

}

int main() {
	scanf("%d",&N);
	vector<int> comx, comy;
	for (int i=0;i<N;i++) {
		scanf("%d%d%d",&RX[i],&RY[i],&RC[i]);
		comx.push_back(RX[i]);
		comy.push_back(RY[i]);
	}
	sort(comx.begin(),comx.end()); comx.erase(unique(comx.begin(),comx.end()),comx.end());
	sort(comy.begin(),comy.end()); comy.erase(unique(comy.begin(),comy.end()),comy.end());
	for (int i=0;i<N;i++) {
		RX[i] = lower_bound(comx.begin(),comx.end(),RX[i])-comx.begin();
		RY[i] = lower_bound(comy.begin(),comy.end(),RY[i])-comy.begin();
		RC[i]--;
	}
	int perm[3] = {1,2,3};
	int ans = 0;
	do {
		for (int i=0;i<N;i++) X[i] = RX[i], Y[i] = RY[i];
		for (int i=0;i<N;i++) C[i] = perm[RC[i]];
		for (int j=0;j<4;j++) {
			ans = max(ans, solveT());
			if (j<2) ans = max(ans, solveI());
			for (int i=0;i<N;i++) {
				int x = X[i], y = Y[i];
				X[i] = N-1-y;
				Y[i] = x;
			}
		}
	} while(next_permutation(perm,perm+3));
	printf("%d\n",ans*3);

	return 0;
}