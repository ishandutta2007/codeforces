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

cat mod = 998244353;

cat pw(cat a, cat e) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2);
	x = x * x % mod;
	if(e&1) x = x * a % mod;
	return x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, Q;
	cin >> N >> Q;
	vector<cat> P(N);
	for(int i = 0; i < N; i++) {
		cat p;
		cin >> p;
		P[i] = pw(100, mod-2) * p % mod;
	}
	vector< vector<cat> > prod(20, vector<cat>(N+1, 1));
	for(int i = 0; i < N; i++) prod[0][i] = P[i];
	for(int k = 1; k < 20; k++) for(int i = 0; i <= N-(1<<k); i++)
		prod[k][i] = prod[k-1][i] * prod[k-1][i+(1<<(k-1))] % mod;
	vector< vector<cat> > sum(20, vector<cat>(N+1, 1));
	for(int k = 1; k < 20; k++) for(int i = 0; i <= N-(1<<k); i++)
		sum[k][i] = (sum[k-1][i] + sum[k-1][i+(1<<(k-1))] * prod[k-1][i]) % mod;
	vector<cat> E_sum(N+1, 0), E_prod(N+1, 1);
	for(int i = N-1; i >= 0; i--) {
		E_sum[0] = (E_sum[0] * P[i] + 1) % mod;
		E_prod[0] = (E_prod[0] * P[i]) % mod;
	}
	cat E = E_sum[0] * pw(E_prod[0], mod-2) % mod;
	set<cat> live = {0, N};
	for(int q = 0; q < Q; q++) {
		int u;
		cin >> u;
		u--;
		auto it = live.lower_bound(u);
		if(*it != u) {
			int cur = u, dist = *it - u;
			E_sum[u] = 0, E_prod[u] = 1;
			for(int k = 0; k < 20; k++) if((dist>>k)&1) {
				E_sum[u] = (E_sum[u] + E_prod[u] * sum[k][cur]) % mod;
				E_prod[u] = E_prod[u] * prod[k][cur] % mod;
				cur += 1<<k;
				dist -= 1<<k;
				if(dist == 0) break;
			}
			auto prev = it; prev--;
			E = (E - E_sum[*prev] * pw(E_prod[*prev], mod-2) + E_sum[u] * pw(E_prod[u], mod-2)) % mod;
			E_prod[*prev] = (E_prod[*prev] * pw(E_prod[u], mod-2)) % mod;
			E_sum[*prev] = (E_sum[*prev] - E_prod[*prev] * E_sum[u]) % mod;
			E = (E + E_sum[*prev] * pw(E_prod[*prev], mod-2)) % mod;
			live.insert(u);
		}
		else {
			auto prev = it;
			prev--;
			E -= E_sum[*prev] * pw(E_prod[*prev], mod-2) + E_sum[u] * pw(E_prod[u], mod-2);
			E_sum[*prev] = (E_sum[*prev] + E_prod[*prev] * E_sum[u]) % mod;
			E_prod[*prev] = E_prod[*prev] * E_prod[u] % mod;
			E = (E + E_sum[*prev] * pw(E_prod[*prev], mod-2)) % mod;
			live.erase(it);
		}
		if(E < 0) E += mod;
		cout << E << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing