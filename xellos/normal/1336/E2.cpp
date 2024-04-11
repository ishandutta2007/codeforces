#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector<cat> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	int Z = 0;
	cat mask = (1LL<<M)-1;
	for(int i = 0; i < M; i++) {
		for(int j = i; j < N; j++) {
			if(!A[j]) {
				swap(A[j], A[N-1]);
				N--, Z++;
				j--;
				continue;
			}
			swap(A[j], A[i]);
			break;
		}
		if(i == N) break;
		int b = 0;
		while(!((A[i]>>b)&1)) b++;
		mask ^= 1LL<<b;
		for(int j = 0; j < N; j++) if(j != i) {
			cat x = (A[j]>>b) & 1;
			A[j] ^= A[i] & (-x);
		}
	}
	while(N && A[N-1] == 0) N--, Z++; 
	vector<int> B(N, 0);
	for(int i = 0; i < N; i++) {
		for(int j = 0, k = 0; j < M; j++) if((mask>>j)&1) {
			B[i] |= ((A[i]>>j)&1)<<k;
			k++;
		}
	}
	cat mod = 998244353;
	vector<cat> ans(M+1, 0);
	if(N <= 31) {
		if(N <= 24) {
			vector<cat> X(1<<N, 0);
			for(int i = 0, b = 0; i < (1<<N); i++) {
				while((1<<b) <= i) b++;
				for(int j = b; j < N; j++) X[i|(1<<j)] = X[i] ^ A[j];
			}
			for(int i = 0; i < (1<<N); i++)
				ans[__builtin_popcountll(X[i])]++;
		}
		else {
			vector<int> X_l(1<<(N/2), 0), X_r(1<<(N-N/2), 0), pop(1<<(N-N/2), 0);
			for(int i = 0, b = 0; i < (1<<(N/2)); i++) {
				while((1<<b) <= i) b++;
				for(int j = b; j < N/2; j++) X_l[i|(1<<j)] = X_l[i] ^ B[j];
			}
			for(int i = 0, b = 0; i < (1<<(N-N/2)); i++) {
				while((1<<b) <= i) b++;
				for(int j = b; j < N-N/2; j++) X_r[i|(1<<j)] = X_r[i] ^ B[j+N/2];
				pop[i] = __builtin_popcount(i);
			}
			for(int i = 0; i < (1<<(N/2)); i++)
				for(int j = 0; j < (1<<(N-N/2)); j++)
					ans[__builtin_popcount(X_l[i]^X_r[j])+pop[i]+pop[j]]++;
		}
	}
	else {
		if(N == 32) {
			vector< vector<int> > cnt(N+1, vector<int>(1<<(M-N), 0));
			cnt[0][0] = 1;
			for(int i = 0; i < N; i++)
				for(int k = i; k >= 0; k--)
					for(int j = 0; j < (1<<(M-N)); j++)
						cnt[k+1][j] += cnt[k][j^B[i]];
			for(int k = 0; k <= N; k++)
				for(int j = 0; j < (1<<(M-N)); j++)
					ans[k+__builtin_popcount(j)] += cnt[k][j];
			for(int k = 0; k <= M; k++) ans[k] %= mod;
		}
		else {
			vector< vector<cat> > cnt(N+1, vector<cat>(1<<(M-N), 0));
			cnt[0][0] = 1;
			for(int i = 0; i < N; i++)
				for(int k = i; k >= 0; k--)
					for(int j = 0; j < (1<<(M-N)); j++)
						cnt[k+1][j] += cnt[k][j^B[i]];
			for(int k = 0; k <= N; k++)
				for(int j = 0; j < (1<<(M-N)); j++)
					ans[k+__builtin_popcount(j)] += cnt[k][j];
			for(int k = 0; k <= M; k++) ans[k] %= mod;
		}
	}
	cat pw2 = 1;
	for(int i = 0; i < Z; i++) pw2 = pw2 * 2 % mod;
	for(int i = 0; i <= M; i++) {
		ans[i] = ans[i] * pw2 % mod;
		cout << ans[i] << ((i == M) ? "\n" : " ");
	}
	return 0;
}

// look at my code
// my code is amazing