// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

struct itree {
	int b;
	vector<int> n_lo, n_hi;
	vector<cat> sum;

	itree(int N) : b(1) {
		while(b < N) b *= 2;
		n_hi.resize(2*b, 0);
		n_lo.resize(2*b);
		sum.resize(2*b, 0);
		n_lo[1] = b;
		for(int i = 1; i < b; i++)
			n_lo[2*i] = n_lo[2*i+1] = n_lo[i]/2;
	}

	void toggle(int pos, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		if(l+1 == r) {
			n_lo[cur]--, n_hi[cur]++;
			return;
		}
		if(pos < (l+r)/2) toggle(pos, 2*cur, l, (l+r)/2);
		else toggle(pos, 2*cur+1, (l+r)/2, r);
		n_lo[cur] = n_lo[2*cur] + n_lo[2*cur+1];
		n_hi[cur] = n_hi[2*cur] + n_hi[2*cur+1];
		sum[cur] = sum[2*cur] + sum[2*cur+1] + 1LL * n_hi[2*cur] * n_lo[2*cur+1];
	}

	struct info {
		int n_lo, n_hi;
		cat sum;
	};

	info get(int Il, int Ir, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		Il = max(Il, l);
		Ir = min(Ir, r);
		if(Il >= r || l >= Ir) return {0, 0, 0};
		if(Il == l && Ir == r) return {n_lo[cur], n_hi[cur], sum[cur]};
		info Rl = get(Il, Ir, 2*cur, l, (l+r)/2);
		info Rr = get(Il, Ir, 2*cur+1, (l+r)/2, r);
		info R = {Rl.n_lo+Rr.n_lo, Rl.n_hi+Rr.n_hi, Rl.sum+Rr.sum+1LL*Rl.n_hi*Rr.n_lo};
		return R;
	}
};

struct fin {
	vector<cat> T;
	fin(int N) : T(N+10, 0) {}

	int lastone(int x) {return x & (x ^ (x-1));}

	void put(int pos, int val) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i)) T[i] += val;
	}

	cat get(int pos) {
		cat ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret += T[i];
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> P(N), pos(N);
	for(int i = 0; i < N; i++) {
		cin >> P[i];
		pos[--P[i]] = i;
	}
	vector<cat> ans(N, 0);
	int l = pos[0], r = pos[0];
	fin F_inv(N);
	F_inv.put(pos[0], 1);
	cat n_inv = 0;
	set<int> S_lft, S_rt;
	S_lft.insert(pos[0]);
	itree Il(N), Ir(N);
	Il.toggle(pos[0]);
	Ir.toggle(N-1-pos[0]);
	for(int i = 1; i < N; i++) {
		n_inv += i - F_inv.get(pos[i]);
		F_inv.put(pos[i], 1);
		l = min(l, pos[i]);
		r = max(r, pos[i]);

		if(pos[i] < *rbegin(S_lft)) S_lft.insert(pos[i]);
		else S_rt.insert(pos[i]);
		if(S_rt.size() > S_lft.size()) {
			S_lft.insert(*begin(S_rt));
			S_rt.erase(begin(S_rt));
		}
		if(S_lft.size() > S_rt.size()+1) {
			S_rt.insert(*rbegin(S_lft));
			S_lft.erase(--end(S_lft));
		}
		int mid = *rbegin(S_lft); // [l, mid-1]: left, [mid+1, r]: right

		Il.toggle(pos[i]);
		Ir.toggle(N-1-pos[i]);
		ans[i] = n_inv + Il.get(l, mid).sum + Ir.get(N-1-r, N-1-mid).sum;
	}
	for(int i = 0; i < N; i++) cout << ans[i] << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing