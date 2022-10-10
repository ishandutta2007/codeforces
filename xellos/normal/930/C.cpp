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
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

struct fin {
	vector<int> T;
	fin() {}
	fin(int N) {T.resize(N+10, 0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i))
			T[i] = max(T[i], val);
	}

	int get(int pos) {
		int ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret = max(ret, T[i]);
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector<int> cov(M+1, 0);
	for(int i = 0; i < N; i++) {
		int l, r;
		cin >> l >> r;
		cov[l-1]++;
		cov[r]--;
	}
	for(int i = 0; i < M; i++) cov[i+1] += cov[i];

	vector<int> inc(M), dec(M);
	fin F(N);
	for(int i = 0; i < M; i++) {
		inc[i] = F.get(cov[i])+1;
		F.put(cov[i], inc[i]);
	}
	F = fin(N);
	for(int i = M-1; i >= 0; i--) {
		dec[i] = F.get(cov[i])+1;
		F.put(cov[i], dec[i]);
	}

	int ans = 0;
	for(int i = 0; i < M; i++) ans = max(ans, inc[i]+dec[i]-1);
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing