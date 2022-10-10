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

struct fin {
	vector<int> T;
	fin() {}
	fin(int N) : T(N+10, OVER9000) {}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i)) T[i] = min(T[i], val);
	}

	int get(int pos) {
		int ret = OVER9000;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret = min(ret, T[i]);
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> S(N);
	map<int, int> MS;
	for(int i = 0; i < N; i++) {
		cin >> S[i];
		MS[S[i]] = 0;
	}
	int ms = 0;
	ALL_THE(MS, it) it->ss = ms++;
	for(int i = 0; i < N; i++) S[i] = MS[S[i]];
	vector<int> cost[3];
	cost[0].resize(N);
	for(int i = 0; i < N; i++) cin >> cost[0][i];
	for(int k = 1; k < 3; k++) {
		cost[k].resize(N, OVER9000);
		fin F(ms);
		for(int i = 0; i < N; i++) {
			cost[k][i] = min(cost[k][i], F.get(S[i]-1) + cost[0][i]);
			F.put(S[i], cost[k-1][i]);
		}
	}
	int ans = OVER9000;
	for(int i = 0; i < N; i++) ans = min(ans, cost[2][i]);
	if(ans == OVER9000) ans = -1;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing