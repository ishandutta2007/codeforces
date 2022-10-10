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
	int N;
	cin >> N;
	int MX = 300000;
	vector<int> used(MX+1, 0);
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		used[a]++;
	}
	vector<int> P(MX+1, 1), prev(MX+1, 1);
	for(int i = 2; i <= MX; i++) {
		if(P[i] == 1) {
			P[i] = i;
			for(int j = i; j <= MX/i; j++) P[j*i] = i;
		}
		prev[i] = i;
		while(prev[i] % P[i] == 0) prev[i] /= P[i];
	}
	// // max. 6 primes
	vector<int> is_state(MX+1, 0);
	is_state[1] = 1;
	for(int i = 2; i <= MX; i++) {
		int x = i / P[i];
		if(x % P[i] == 0) continue;
		is_state[i] = is_state[x];
	}
	vector<int> used_state(MX+1, 0);
	for(int i = 0; i <= MX; i++) if(used[i]) {
		int x = i, y = 1;
		while(x > 1) {
			y *= P[x];
			x = prev[x];
		}
		used_state[y] = 1;
	}
	vector<int> count_div(MX+1, 0);
	for(int i = 1; i <= MX; i++) if(is_state[i])
		for(int j = 1; j <= MX/i; j++) count_div[i] += used_state[i*j];
	vector<int> count_coprime(MX+1, 0);
	vector<int> p, prod(1<<10, 1), sgn(1<<10, 0);
	for(int i = 0; i < (1<<10); i++) for(int j = 0; j < 10; j++) sgn[i] ^= (i>>j)&1;
	for(int i = 1; i <= MX; i++) {
		p.clear();
		int x = i;
		while(x > 1) {
			p.push_back(P[x]);
			x = prev[x];
		}
		int n = p.size(), a = 0;
		for(int j = 0; j < (1<<n); j++) {
			while((1<<a) <= j) a++;
			for(int k = a; k < n; k++) prod[j | (1<<k)] = prod[j] * p[k];
			count_coprime[i] += (sgn[j] ? -1 : 1) * count_div[prod[j]];
		}
	}
	vector< vector<int> > G(MX+1);
	for(int i = 1; i <= MX; i++) if(used_state[i]) G[0].push_back(i);
	for(int i = 1; i <= MX; i++) if(is_state[i]) {
		p.clear();
		int x = i;
		while(x > 1) {
			p.push_back(P[x]);
			x = prev[x];
		}
		int n = p.size(), a = 0;
		for(int j = 0; j < (1<<n)-1; j++) {
			while((1<<a) <= j) a++;
			for(int k = a; k < n; k++) prod[j | (1<<k)] = prod[j] * p[k];
			if(count_coprime[i/prod[j]]) G[i].push_back(prod[j]);
		}
	}
	vector<int> dist(MX+1, -1);
	queue<int> q;
	q.push(0);
	dist[0] = 0;
	while(!q.empty()) {
		ALL_THE(G[q.front()], it) if(dist[*it] == -1) {
			dist[*it] = dist[q.front()] + 1;
			q.push(*it);
		}
		q.pop();
	}
	cout << dist[1] << "\n";
	return 0;
}

// look at my code
// my code is amazing