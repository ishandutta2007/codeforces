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
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<int> W(N);
	for(int i = 0; i < N; i++) cin >> W[i];
	vector<int> cnt(1<<N, 0);
	for(int i = 0; i < M; i++) {
		string s;
		cin >> s;
		int b = 0;
		for(int j = 0; j < N; j++) if(s[j] == '1') b |= 1<<j;
		cnt[b]++;
	}
	vector<int> w(1<<N, 0);
	for(int i = 0; i < (1<<N); i++)
		for(int j = 0; j < N; j++) if((i>>j)&1) w[i] += W[j];
	vector< vector<int> > cnt_w(1<<N, vector<int>(2000, 0));
	for(int i = 0; i < (1<<N); i++) {
		for(int j = 0; j < (1<<N); j++) cnt_w[i][w[(1<<N)-1-(i^j)]] += cnt[j];
		for(int j = 1; j < 2000; j++) cnt_w[i][j] += cnt_w[i][j-1];
	}
	for(int q = 0; q < Q; q++) {
		string s;
		int K;
		cin >> s >> K;
		int b = 0;
		for(int j = 0; j < N; j++) if(s[j] == '1') b |= 1<<j;
		cout << cnt_w[b][K] << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing