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
	int N, M;
	cin >> N >> M;
	vector< vector<int> > nxt_seg(N);
	vector<int> half_seg(N, 0);
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		if(N%2 == 0 && (a-b+N/2)%N == 0) half_seg[a] = half_seg[b] = 1;
		else {
			if(a > b) swap(a, b);
			if(b > a+N/2) swap(a, b);
			int dist = b-a;
			while(dist < 0) dist += N;
			nxt_seg[a].push_back(dist);
		}
	}
	for(int i = 0; i < N; i++) {
		sort(begin(nxt_seg[i]), end(nxt_seg[i]));
		if(half_seg[i]) nxt_seg[i].push_back(N/2);
		nxt_seg[i].push_back(N+1);
	}
	vector<int> seq;
	for(int i = 0; i < N; i++) ALL_THE(nxt_seg[i], it)
		seq.push_back(*it);
	int L = seq.size();

	int p = 999983;
	cat mod[2] = {1000000007, 1000000009};
	vector<cat> pw[2];
	for(int k = 0; k < 2; k++) {
		pw[k].resize(L+1, 1);
		for(int i = 1; i <= L; i++) pw[k][i] = pw[k][i-1] * p % mod[k];
	}
	vector< vector<cat> > H(L, vector<cat>(2, 0));
	for(int k = 0; k < 2; k++) {
		for(int i = 0; i < L; i++)
			H[0][k] = (H[0][k] + pw[k][i] * seq[i]) % mod[k];
		if(H[0][k] < 0) H[0][k] += mod[k];
		for(int i = L-1; i > 0; i--) {
			H[i][k] = (H[(i+1)%L][k] - pw[k][L-1] * seq[i]) % mod[k];
			H[i][k] = (H[i][k] * p + seq[i]) % mod[k];
			if(H[i][k] < 0) H[i][k] += mod[k];
		}
	}
	vector<cat> Hc(L);
	for(int i = 0; i < L; i++) Hc[i] = H[i][0] * mod[1] + H[i][1];
	sort(begin(Hc), end(Hc));
	for(int i = 1; i < L; i++) if(Hc[i] == Hc[i-1]) {
		cout << "Yes\n";
		return 0;
	}
	cout << "No\n";
	return 0;
}

// look at my code
// my code is amazing