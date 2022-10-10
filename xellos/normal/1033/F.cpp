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
	int W, N, M;
	cin >> W >> N >> M;
	vector<int> A(1<<W, 0);
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A[a]++;
	}
	vector< vector<int> > B(1<<W, vector<int>(1<<W, 0));
	for(int i = 0; i < (1<<W); i++) for(int j = 0; j < (1<<W); j++)
		B[i][i&j] += A[j];
	for(int i = 0; i < M; i++) {
		string s;
		cin >> s;
		int mask[6] = {};
		for(int j = 0; j < W; j++) {
			if('O' == s[j]) mask[0] |= 1<<(W-1-j);
			if('a' == s[j]) mask[1] |= 1<<(W-1-j);
			if('X' == s[j]) mask[2] |= 1<<(W-1-j);
			if('x' == s[j]) mask[3] |= 1<<(W-1-j);
			if('A' == s[j]) mask[4] |= 1<<(W-1-j);
			if('o' == s[j]) mask[5] |= 1<<(W-1-j);
		}
		int vc = mask[1] | mask[3] | mask[5];
		int vm = mask[2] | mask[3] | mask[5];
		int im = (1<<W)-1 - mask[4], m = mask[4] | mask[5];
		int ans = 0;
		for(int j = 0; j < (1<<W); j++) if((j&(mask[0]|mask[1])) == mask[1]) {
			int mask_cur = (j & m) ^ im;
			int val_cur = vc ^ (j & vm);
			ans += B[mask_cur][val_cur] * A[j];
		}
		cout << ans << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing