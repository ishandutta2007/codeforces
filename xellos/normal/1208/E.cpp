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
	int N, W;
	cin >> N >> W;
	vector<int> A(W);
	vector<cat> ans(W, 0), add(W+1, 0);
	for(int i = 0; i < N; i++) {
		int L;
		cin >> L;
		for(int j = 0; j < L; j++) cin >> A[j];
		int mx = -OVER9000;
		for(int j = 0; j < L; j++) mx = max(mx, A[j]);
		if(L-1 < W-L) {
			mx = max(0, mx);
			add[L-1] += mx;
			add[W-L] -= mx;
		}
		multiset<int> S;
		int x = 0;
		for(int j = 0; j < W; j++) {
			if(j < L) S.insert(A[j]);
			if(j == L-1) {
				j = max(j, W-L);
				if(j >= W) break;
			}
			while(x < L && x < j+L-W) {
				S.erase(S.find(A[x]));
				x++;
			}
			if(j >= L || j < W-L) ans[j] += max(0, *S.rbegin());
			else ans[j] += *S.rbegin();
		}
	}
	for(int i = 0; i < W; i++) {
		ans[i] += add[i];
		add[i+1] += add[i];
	}
	for(int i = 0; i < W; i++) cout << ans[i] << ((i == W-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing