#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ff first
#define ss second
using namespace std;

using cat = int;

struct mon {
	int a, b, c;

	bool operator<(const mon & m) const {
		return a < m.a;
	}
};

struct itree {
	int b;
	vector<cat> val, add;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		val.resize(2*b, 0);
		add.resize(2*b, 0);
	}

	void upd(int cur) {
		if(!add[cur]) return;
		if(cur < b) {
			add[2*cur] += add[cur];
			add[2*cur+1] += add[cur];
		}
		val[cur] += add[cur];
		add[cur] = 0;
	}

	void put(int I_l, int I_r, cat v, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		upd(cur);
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= r || l >= I_r) return;
		if(I_l == l && I_r == r) {
			add[cur] += v;
			upd(cur);
			return;
		}
		put(I_l, I_r, v, 2*cur, l, (l+r)/2);
		put(I_l, I_r, v, 2*cur+1, (l+r)/2, r);
		val[cur] = max(val[2*cur], val[2*cur+1]);
	}

	cat get() {
		upd(1);
		return val[1];
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M, K;
	cin >> N >> M >> K;
	vector< pair<int, int> > A(N), B(M);
	for(int i = 0; i < N; i++) cin >> A[i].ff >> A[i].ss;
	for(int i = 0; i < M; i++) cin >> B[i].ff >> B[i].ss;
	sort(begin(A), end(A));
	sort(begin(B), end(B));
	vector<mon> V(K);
	for(int i = 0; i < K; i++) cin >> V[i].a >> V[i].b >> V[i].c;
	sort(begin(V), end(V));
	itree I(M);
	for(int i = 0; i < M; i++) I.put(i, i+1, -B[i].ss);
	I.put(M, I.b, -B[0].ss);
	int ans = -A[0].ss-B[0].ss;
	for(int i = 0, p = 0; i < N; i++) if(!i || A[i].ff != A[i-1].ff) {
		while(p < K && V[p].a < A[i].ff) {
			pair<int, int> pp = {V[p].b+1, 0};
			auto it = lower_bound(begin(B), end(B), pp);
			I.put(it-begin(B), M, V[p].c);
			p++;
		}
		int min_cost_A = A[i].ss;
		for(int j = i; j < N; j++) {
			if(A[j].ff != A[i].ff) break;
			min_cost_A = min(min_cost_A, A[j].ss);
		}
		ans = max(ans, I.get()-min_cost_A);
	}
	cout << ans << "\n";
}