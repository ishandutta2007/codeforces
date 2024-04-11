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

class fin {
public:
	fin() {}
	fin(int N) : T(vector<int>(N+10, 0)) {}

	void add(int pos, int val) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i)) T[i] += val;
	}

	int get(int pos) {
		int ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret += T[i];
		return ret;
	}

private:
	vector<int> T;

	static int lastone(int x) {return x&(x^(x-1));}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector<int> > A(N, vector<int>(N));
	for(int i = 0; i < N*N; i++) {
		cin >> A[i/N][i%N];
		A[i/N][i%N]--;
	}
	cat mod = 998244353;
	vector<cat> D(N+1, 0), F(N+1, 1);
	D[0] = 1;
	for(int i = 2; i <= N; i++) D[i] = (i-1) * (D[i-1] + D[i-2]) % mod;
	for(int i = 2; i <= N; i++) F[i] = F[i-1] * i % mod;
	vector< vector<cat> > dp(N+1, vector<cat>(N+1, 0));
	dp[0] = D;
	for(int i = 0; i <= N; i++) dp[i][0] = F[i];
	for(int l = 1; l <= N; l++) for(int k = 1; k <= N; k++) dp[l][k] = (dp[l-1][k] * l + dp[l][k-1] * k) % mod;
	cat ans = 0;
	// 1. number of lex. smaller permutations than A[0]
	for(int i = 0; i < N; i++) {
		int pos = A[0][i];
		for(int j = 0; j < i; j++) if(A[0][j] < A[0][i]) pos--;
		ans = (ans + pos * F[N-1-i]) % mod;
	}
	for(int i = 0; i < N-1; i++) ans = ans * D[N] % mod;
	fin cnt[] = {fin(N), fin(N), fin(N), fin(N)};
	for(int r = 1; r < N; r++) {
		// 2. number of lex. smaller permutations than A[r], different from A[r-1] everywhere
		vector<int> used(N, 0);
		cat cur = 0;
		for(int i = 0; i < N; i++) cnt[0].add(i, 1);
		int K = N, L = 0;
		for(int i = 0; i < N; i++) {
			if(used[A[r-1][i]] == 0) K--, L++;
			else if(used[A[r-1][i]] != 3) L--;

			int cnt1 = cnt[1].get(A[r][i]-1);
			cur = (cur + cnt1 * dp[(L-1)/2][K]) % mod;

			cnt[used[A[r-1][i]]].add(A[r-1][i], -1);
			used[A[r-1][i]] |= 1;
			cnt[used[A[r-1][i]]].add(A[r-1][i], 1);

			int cnt0 = cnt[0].get(A[r][i]-1);
			cur = (cur + cnt0 * dp[(L+1)/2][K-1]) % mod;

			if(used[A[r][i]] == 0) K--, L++;
			else if(used[A[r][i]] != 3) L--;

			cnt[used[A[r][i]]].add(A[r][i], -1);
			used[A[r][i]] |= 2;
			cnt[used[A[r][i]]].add(A[r][i], 1);
		}
		for(int i = 0; i < N-1-r; i++) cur = cur * D[N] % mod;
		ans = (ans + cur) % mod;
	}
	if(ans < 0) ans += mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing