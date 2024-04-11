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
	x = x * x % mod;
	if(e&1) x = x * a % mod;
	return x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	map<cat, vector< pair<cat, int> > > QM;
	int MX = 35'000'000;
	vector<cat> primes;
	vector<bool> is_prime(MX+10, true);
	for(int i = 2; i <= MX; i++) if(is_prime[i]) {
		primes.push_back(i);
		for(int j = i; j <= MX/i; j++) is_prime[i*j] = false;
	}
	int Q;
	cin >> Q;
	for(int q = 0; q < Q; q++) {
		cat N, K;
		cin >> N >> K;
		QM[K].push_back({N, q});
	}
	vector<bool> ans(Q, false);
	ALL_THE(QM, qt) {
		cat K = qt->ff;
		if(K == 1) continue;
		vector<cat> P;
		ALL_THE(primes, it) if(K%(*it) == 0) {
			P.push_back(*it);
			while(K%(*it) == 0) K /= *it;
		}
		if(K > 1) P.push_back(K);
		sort(begin(P), end(P));
		vector< pair<cat, int> > V = qt->ss;
		sort(begin(V), end(V));
		if((int)P.size() == 1) {
			ALL_THE(V, it) if(it->ff%P[0] == 0) ans[it->ss] = true;
			continue;
		}
		while(!V.empty() && V.back().ff >= P[0] * P[1]) {
			ans[V.back().ss] = true;
			V.pop_back();
		}
		if((int)P.size() == 2) {
			ALL_THE(V, it) {
				cat rem[2] = {it->ff % P[0], it->ff % P[1]};
				// N = a P[0] + b P[1]
				// rem[0] P[1]^-1 == b
				cat coef[2] = {rem[1] * pw(P[0], P[1]-2, P[1]), rem[0] * pw(P[1], P[0]-2, P[0])};
				for(int i = 0; i < 2; i++) {
					coef[i] %= P[1-i];
					if(coef[i] < 0) coef[i] += P[1-i];
				}
				if(coef[0] * P[0] + coef[1] * P[1] == it->ff) ans[it->ss] = true;
			}
			continue;
		}
		vector<cat> min_reach(P[0], -1);
		min_reach[0] = 0;
		priority_queue<cat, vector<cat>, greater<cat> > q;
		q.push(0);
		while(!q.empty()) {
			cat x = q.top();
			int y = x % P[0];
			q.pop();
			if(min_reach[y] != x) continue;
			ALL_THE(P, it) {
				int z = (y + *it) % P[0];
				if(min_reach[z] == -1 || min_reach[z] > x + *it) {
					min_reach[z] = x + *it;
					q.push(x+*it);
				}
			}
		}
		ALL_THE(V, it) {
			int y = it->ff % P[0];
			if(min_reach[y] != -1 && min_reach[y] <= it->ff) ans[it->ss] = true;
		}
	}
	for(int q = 0; q < Q; q++) cout << (ans[q] ? "YES\n" : "NO\n");
	return 0;
}

// look at my code
// my code is amazing