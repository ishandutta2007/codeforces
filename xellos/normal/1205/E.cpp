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

constexpr cat mod = 1'000'000'007;

cat pw(cat a, cat e) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2);
	x = x * x % mod;
	if(e&1) x = x * a % mod;
	return x;
}

cat inv(cat a) {
	return pw(a, mod-2);
}

int gcd(int a, int b) {
	if(a > b) swap(a, b);
	return (a == 0) ? b : gcd(b%a, a);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, K;
	cin >> N >> K;
	vector<cat> cnt(N+1, 0);
	for(int i = 2; i <= N/2; i++) {
		cnt[N-2*i+1]++;
		cnt[N-i]--;
	}
	for(int i = 0; i < N; i++) cnt[i+1] += cnt[i];
	vector< vector<int> > prime_divs(2*N+1);
	for(int s = 1; s <= 2*N; s++) {
		int x = s;
		for(int i = 2; i*i <= x; i++) if(x%i == 0) {
			prime_divs[s].push_back(i);
			while(x%i == 0) x /= i;
		}
		if(x > 1) prime_divs[s].push_back(x);
	}
	vector<int> sz(1<<15, 0);
	for(int i = 0; i < (1<<15); i++) for(int j = 0; j < 15; j++) {
		if((i>>j)&1) continue;
		sz[i|(1<<j)] = sz[i]+1;
	}
	for(int g = 1; g <= N; g++) for(int s = 1; s <= N/g*2; s++) {
		int cnt_cur = 0;
		int l = max(s-(N-1)/g, 1), r = min((s-1)/2, (N-1)/2/g);
		if(l > r) continue;
		// for(int i = l; i <= r; i++) if(gcd(i, s) == 1) cnt_cur++;
		for(int i = 0; i < (1<<prime_divs[s].size()); i++) {
			int x = 1;
			for(int j = 0; j < (int)prime_divs[s].size(); j++)
				if((i>>j)&1) x *= prime_divs[s][j];
			int cnt_div = r/x - (l-1)/x;
			if(sz[i]&1) cnt_cur -= cnt_div;
			else cnt_cur += cnt_div;
		}
		if(N/g+1 >= s) cnt[g] += cnt_cur;
		else cnt[g*s-N] += cnt_cur;
	}
	for(int i = 0; i <= N; i++) cnt[i] *= 2;
	for(int i = 1; i < N; i++) cnt[i]++;
	for(int i = 0; i <= N; i++) cnt[i] %= mod;
	vector<cat> pw_K(N+1, 1);
	for(int i = 1; i <= N; i++) pw_K[i] = pw_K[i-1] * K % mod;
	cat ans = 0;
	for(int i = 0; i <= N; i++) ans = (ans + pw_K[i] * cnt[i]) % mod;
	ans = ans * pw(inv(K), N) % mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing