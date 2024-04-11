#include <bits/stdc++.h>
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

void solve(uint32_t V[1<<16][64], int cur, int cur_val, auto & ans, int K) {
	for(int i = 0; i < 16; i++) if(cur == (1<<i)) return;
	while(cur_val <= 2000) {
		for(int i = 1; i < cur; i++) if((cur&i) == i)
			for(int j = 0; j <= cur_val; j++)
				if((V[i][j/32]>>(j%32))&(V[cur-i][(cur_val-j)/32]>>((cur_val-j)%32))&1) {
					ans.push_back({j, cur_val-j});
					solve(V, i, j, ans, K);
					solve(V, cur-i, cur_val-j, ans, K);
					return;
				}
		cur_val *= K;
	}
	assert(false);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];

	uint32_t V[1<<16][64];
	int max_nonzero[1<<16];
	memset(V, 0, sizeof(V));
	memset(max_nonzero, 0, sizeof(max_nonzero));
	for(int i = 0; i < N; i++) {
		V[1<<i][A[i]/32] |= 1<<(A[i]%32);
		max_nonzero[1<<i] = max(max_nonzero[1<<i], A[i]/32);
	}
	for(int i = 1; i < (1<<N); i++) {
		int pop = __builtin_popcount(i);
		if(pop == 1 || pop > N/2) continue;
		if(i > (1<<N)-1-i && 2*pop == N) continue;
		static vector<int> bits;
		bits.clear();
		for(int j = 0; j < N; j++) if((i>>j)&1) bits.push_back(j);
		int B = bits.size();
		vector<int> S(1<<B, 0);
		for(int j = 0, b = 0; j < (1<<B)/2; j++) {
			while((1<<b) <= j) b++;
			for(int k = b; k < B; k++) S[j+(1<<k)] = S[j] + (1<<bits[k]);
		}
		static uint32_t sums[64];
		memset(sums, 0, sizeof(sums));
		for(int j = 1; j < (1<<(B-1)); j++) for(int k = 0; k <= min(62, max_nonzero[S[j]]); k++) {
			if(V[S[j]][k] == 0) continue;
			uint32_t * ptr2 = V[i-S[j]];
			uint32_t vi = V[S[j]][k];
			uint32_t * sums_ptr = sums + k;
			uint32_t * ptr2_fin = ptr2 + min(63-k, max_nonzero[i-S[j]]+1);
			if((vi & (vi-1)) == 0) {
				int e = 0;
				while(vi != 1) vi >>= 1, e++;
				while(ptr2 != ptr2_fin) {
					if(*ptr2) {
						uint64_t vm = *ptr2;
						vm <<= e;
						*sums_ptr |= vm;
						*(++sums_ptr) |= vm >> 32;
					}
					else sums_ptr++;
					ptr2++;
				}
			}
			else {
				while(ptr2 != ptr2_fin) {
					if(*ptr2) {
						uint64_t vm = 0;
						uint32_t v1 = vi;
						for(uint64_t v2 = *ptr2; v1; v1 >>= 1, v2 <<= 1) if(v1&1) vm |= v2;
						*sums_ptr |= vm;
						*(++sums_ptr) |= vm >> 32;
					}
					else sums_ptr++;
					ptr2++;
				}
			}
		}
		for(int j = 2047-2047%K; j >= 0; j -= K) if((sums[j/32]>>(j%32))&1)
			sums[j/32] ^= 1<<(j%32), sums[(j/K)/32] |= 1<<((j/K)%32);
		for(int j = 0; j < 64; j++) {
			V[i][j] |= sums[j];
			if(V[i][j]) max_nonzero[i] = max(max_nonzero[i], j);
		}
	}

	uint32_t goal[1<<16][64];
	memset(goal, 0, sizeof(goal));
	for(int k = 1; k <= 2000; k *= K) goal[(1<<N)-1][k/32] |= 1<<(k%32);
	bool found = false;
	for(int i = (1<<N)-1; i >= 1; i--) {
		if(found) break;
		if(__builtin_popcount(i) < N/2) continue;
		if(__builtin_popcount(i)*2 == N && i <= (1<<N)-1-i) continue;
		static vector<int> bits;
		bits.clear();
		for(int j = 0; j < N; j++) if((i>>j)&1) bits.push_back(j);
		int B = bits.size();
		vector<int> S(1<<B, 0);
		for(int j = 0, b = 0; j < (1<<B)/2; j++) {
			while((1<<b) <= j) b++;
			for(int k = b; k < B; k++) S[j+(1<<k)] = S[j] + (1<<bits[k]);
		}
		int pop = __builtin_popcount(i);
		for(int j = 1; j < (1<<B)-1; j++) {
			if(found) break;
			int pop_j = __builtin_popcount(S[j]);
			if(2*pop_j > pop || (2*pop_j == pop && S[j] > i-S[j])) continue;
			for(int k = 0; k < 64; k++) {
				if(goal[i][k] == 0) continue;
				for(int l = 0; l < k; l++) {
					uint64_t vd = 0;
					for(uint64_t v1 = (1LL*goal[i][k]) << 32, v2 = V[S[j]][l]; v2; v2 >>= 1, v1 >>= 1)
						if(v2&1) vd |= v1;
					goal[i-S[j]][k-l-1] |= vd;
					goal[i-S[j]][k-l] |= vd >> 32;
				}
				for(int l = 0; l < 64; l++) if((V[S[j]][k]>>l)&1)
					goal[i-S[j]][0] |= goal[i][k]>>l;
			}
			for(int k = 0; k < 64; k++) if(goal[i-S[j]][k]) {
				for(int l = 0; l < 32; l++) if((goal[i-S[j]][k]>>l)&1) {
					if((32*k+l)*K > 2000) break;
					goal[i-S[j]][((32*k+l)*K)/32] |= 1<<((32*k+l)*K%32);
				}
				if(goal[i-S[j]][k] & V[i-S[j]][k]) {
					found = true;
					break;
				}
			}
		}
	}

	if(!found) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for(int i = 1; i < (1<<N); i++) for(int j = 0; j <= 2000; j++) if(((goal[i][j/32]&V[i][j/32])>>(j%32))&1) {
		vector< pair<int, int> > ans, ans_fin;
		solve(V, i, j, ans, K);
		int cur = i, cur_val = j;
		while(cur != (1<<N)-1) {
			bool stop = false;
			for(int k = 1; k < (1<<N); k++) if((k&cur) == 0) {
				if(stop) break;
				for(int l = 0; l <= 2000-cur_val; l++) if((V[k][l/32]>>(l%32))&1) {
					if(((goal[k+cur][(l+cur_val)/32]>>((l+cur_val)%32))&1) == 0) continue;
					solve(V, k, l, ans, K);
					ans_fin.push_back({cur_val, l});
					cur += k;
					cur_val += l;
					while(cur_val%K == 0) cur_val /= K;
					stop = true;
					break;
				}
			}
		}
		reverse(begin(ans), end(ans));
		for(auto p : ans_fin) ans.push_back(p);
		for(int k = 0; k < N-1; k++) cout << ans[k].ff << " " << ans[k].ss << "\n";
		return 0;
	}
	return 0;
}

// look at my code
// my code is amazing