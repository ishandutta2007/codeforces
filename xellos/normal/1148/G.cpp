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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	vector<int> P;
	for(int i = 2; i < 3300; i++) {
		bool is_prime = true;
		for(int j = 2; j*j <= i; j++) if(i%j == 0) {
			is_prime = false;
			break;
		}
		if(is_prime) P.push_back(i);
	}
	constexpr int MX = 1e7;
	int N, K;
	cin >> N >> K;
	vector< vector<int> > A(N);
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A[i].dibs(8);
		for(auto p : P) {
			if(p*p > a) break;
			if(a%p == 0) {
				while(a%p == 0) a /= p;
				A[i].push_back(p);
			}
		}
		if(a > 1) A[i].push_back(a);
	}
	vector<int> roots, back_group(N, -1);
	uint64_t S[MX+1][2];
	memset(S, 0, sizeof(S));
	vector<int> S_sum(MX+1, 0);
	vector<int> prev(N, -1);
	char pop[256];
	for(int i = 0; i < 256; i++) {
		pop[i] = 0;
		for(int j = 0; j < 8; j++) pop[i] ^= (i>>j)&1;
	}
	for(int i = 0; i < N; i++) {
		vector<int> sub(1<<A[i].size(), 1);
		for(int j = 0, b = 0; j < 256; j++) {
			while((1<<b) <= j) b++;
			if(b == (int)A[i].size()) break;
			for(int k = b; k < (int)A[i].size(); k++)
				sub[j+(1<<k)] = sub[j] * A[i][k];
		}
		uint64_t mask[4] = {0, 0, 0, 0};
		for(int j = 0; j < (1<<A[i].size()); j++)
			for(int k = 0; k < 2; k++)
				mask[k] ^= S[sub[j]][k];
		int sum = 0;
		for(int j = 0; j < (1<<A[i].size()); j++)
			sum += (pop[j] ? 1 : -1) * S_sum[sub[j]];
		if(mask[0]|mask[1]) {
			int k = 0;
			while(!mask[k]) k++;
			uint64_t m = mask[k];
			k *= 64;
			while(m>>8) k += 8, m >>= 8;
			while(m>>1) k++, m >>= 1;
			back_group[i] = k;
		}
		else if(sum) {
			int a = 1;
			for(auto p : A[i]) a *= p;
			for(int j = 0; j < i; j++) {
				bool skip = false;
				for(auto p : A[j]) if(a%p == 0) {
					skip = true;
					break;
				}
				if(skip) continue;
				prev[i] = j;
				break;
			}
			if(prev[i] == -1) return 1;
		}
		else roots.push_back(i);
		int group = i & 127;
		for(int j = 0; j < (1<<A[i].size()); j++) {
			S[sub[j]][group>>6] ^= 1LL<<(group&63);
		}
		for(int j = 0; j < (1<<A[i].size()); j++)
			S_sum[sub[j]]++;
	}
	if((int)roots.size() >= K) {
		for(int i = 0; i < K; i++)
			cout << roots[i]+1 << ((i == K-1) ? "\n" : " ");
		return 0;
	}
	for(int g = 0; g < 128; g++) {
		vector<int> BG;
		BG.dibs(N/128);
		for(int i = g; i < N; i += 128) {
			int prod = 1;
			for(auto p : A[i]) prod *= p;
			BG.push_back(prod);
		}
		for(int i = 0; i < N; i++) if(back_group[i] == g) {
			const int * __restrict b_ptr = BG.data();
			const int * __restrict b_fin = b_ptr + BG.size();
			const int * __restrict f_ptr = A[i].data();
			int l = A[i].size();
			while(b_ptr != b_fin) {
				bool skip = false;
				for(int j = 0; j < l; j++) if((*b_ptr) % f_ptr[j] == 0) {
					skip = true;
					break;
				}
				if(!skip) break;
				b_ptr++;
			}
			if(b_ptr == b_fin) return 1;
			prev[i] = (b_ptr - BG.data()) * 128 + g;
		}
	}
	vector<int> ans;
	vector<char> used(N, 0);
	for(int i = 0; i < N; i++) if(prev[i] != -1 && !used[i]) {
		if(prev[prev[i]] != -1 || used[prev[i]] || (int)ans.size() >= K-1) continue;
		ans.push_back(prev[i]);
		ans.push_back(i);
		used[prev[i]] = used[i] = 1;
	}
	for(int i = 0; i < N; i++) if(prev[i] != -1 && !used[i]) {
		if(!used[prev[i]] || (int)ans.size() >= K) continue;
		ans.push_back(i);
		used[i] = 1;
	}
	if((int)ans.size() < K) return 1;
	for(int i = 0; i < K; i++)
		cout << ans[i]+1 << ((i == K-1) ? "\n" : " ");
}

// look at my code
// my code is amazing