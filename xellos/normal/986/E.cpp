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

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = (x*x) % mod;
	if(e&1) x = (x*a) % mod;
	return x;
}

struct fin {
	vector<int> T;
	fin() = default;
	fin(int N) : T(vector<int>(N+10, 0)) {}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i)) T[i] += val;
	}

	int get(int pos) {
		int ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret += T[i];
		return ret;
	}
};

void DFS(int R, auto & G, auto & par, auto & I) {
	I[R].ss = I[R].ff+1;
	ALL_THE(G[R], it) if(par[*it] == -1) {
		par[*it] = R;
		I[*it].ff = I[R].ss;
		DFS(*it, G, par, I);
		I[R].ss = I[*it].ss;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}

	vector< pair<int, int> > I(N, {0, 0});
	vector< vector<int> > par(18, vector<int>(N, -1));
	par[0][0] = 0;
	DFS(0, G, par[0], I);
	for(int i = 1; i < 18; i++)
		for(int j = 0; j < N; j++) par[i][j] = par[i-1][par[i-1][j]];

	int MX = 3500;
	vector<int> primes;
	for(int i = 2; i <= MX; i++) {
		bool is_prime = true;
		for(int j = 2; j*j <= i; j++) if(i%j == 0) {
			is_prime = false;
			break;
		}
		if(is_prime) primes.push_back(i);
	}
	vector< pair<int, pair<int, int> > > factors;
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		for(int j = 0; j < (int)primes.size(); j++) if(a%primes[j] == 0) {
			int e = 0;
			while(a%primes[j] == 0) a /= primes[j], e++;
			factors.push_back({primes[j], {e, i}});
		}
		if(a > 1) factors.push_back({a, {1, i}});
	}
	sort(begin(factors), end(factors));

	int Q;
	cin >> Q;
	vector<int> U(Q), V(Q), L(Q);
	vector< pair<int, pair<int, int> > > factors_q;
	for(int q = 0; q < Q; q++) {
		int a;
		cin >> U[q] >> V[q] >> a;
		U[q]--, V[q]--;
		int l = (I[U[q]].ff <= I[V[q]].ff && I[V[q]].ff < I[U[q]].ss) ? U[q] : V[q];
		int x = U[q]+V[q]-l;
		for(int i = 17; i >= 0; i--)
			if(I[par[i][l]].ff > I[x].ff || I[par[i][l]].ss <= I[x].ff) l = par[i][l];
		if(I[l].ff > I[x].ff || I[l].ss <= I[x].ff) l = par[0][l];
		L[q] = l;
		for(int j = 0; j < (int)primes.size(); j++) if(a%primes[j] == 0) {
			int e = 0;
			while(a%primes[j] == 0) a /= primes[j], e++;
			factors_q.push_back({primes[j], {e, q}});
		}
		if(a > 1) factors_q.push_back({a, {1, q}});
	}
	sort(begin(factors_q), end(factors_q));
	cat mod = 1000000007;
	vector<cat> ans(Q, 1);

	fin Fgt(N), Fsum(N);
	int a = 0;
	for(int i = 0; i < (int)factors_q.size(); i++) if(i == 0 || factors_q[i].ff != factors_q[i-1].ff) {
		while(a < (int)factors.size() && factors[a].ff < factors_q[i].ff) a++;
		if(a == (int)factors.size() || factors[a].ff != factors_q[i].ff) continue;
		vector< pair<int, int> > cur_fac, cur_fac_q;
		for(int j = i; j < (int)factors_q.size(); j++) {
			if(factors_q[j].ff != factors_q[i].ff) break;
			cur_fac_q.push_back(factors_q[j].ss);
		}
		for(int j = a; j < (int)factors.size(); j++) {
			if(factors[j].ff != factors[a].ff) break;
			cur_fac.push_back(factors[j].ss);
			Fgt.put(I[factors[j].ss.ss].ff, 1);
			Fgt.put(I[factors[j].ss.ss].ss, -1);
		}

		int b = 0;
		for(int j = 0; j < (int)cur_fac_q.size(); j++) {
			while(b < (int)cur_fac.size() && cur_fac[b].ff <= cur_fac_q[j].ff) {
				Fgt.put(I[cur_fac[b].ss].ff, -1);
				Fgt.put(I[cur_fac[b].ss].ss, 1);
				Fsum.put(I[cur_fac[b].ss].ff, cur_fac[b].ff);
				Fsum.put(I[cur_fac[b].ss].ss, -cur_fac[b].ff);
				b++;
			}
			int q = cur_fac_q[j].ss;
			int sum_exp_gt = Fgt.get(I[U[q]].ff) + Fgt.get(I[V[q]].ff) - Fgt.get(I[L[q]].ff);
			int sum_exp_sum = Fsum.get(I[U[q]].ff) + Fsum.get(I[V[q]].ff) - Fsum.get(I[L[q]].ff);
			if(L[q] != 0) {
				sum_exp_gt -= Fgt.get(I[par[0][L[q]]].ff);
				sum_exp_sum -= Fsum.get(I[par[0][L[q]]].ff);
			}
			int sum_exp = sum_exp_gt * cur_fac_q[j].ff + sum_exp_sum;
			ans[q] = ans[q] * pw(factors_q[i].ff, sum_exp, mod) % mod;
		}

		for(int j = 0; j < b; j++) {
			Fsum.put(I[cur_fac[j].ss].ff, -cur_fac[j].ff);
			Fsum.put(I[cur_fac[j].ss].ss, cur_fac[j].ff);
		}
		while(b < (int)cur_fac.size()) {
			Fgt.put(I[cur_fac[b].ss].ff, -1);
			Fgt.put(I[cur_fac[b].ss].ss, 1);
			b++;
		}
	}

	for(int i = 0; i < Q; i++) cout << ans[i] << "\n";
	return 0;}

// look at my code
// my code is amazing