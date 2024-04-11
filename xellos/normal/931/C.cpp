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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, minx = 100000000;
	cin >> N;
	vector<int> X(N);
	for(int i = 0; i < N; i++) {
		cin >> X[i];
		minx = min(minx, X[i]);
	}
	int cnt[3] = {0, 0, 0}, ans[3], cur[3];
	for(int i = 0; i < N; i++) cnt[X[i]-minx]++;
	int mincost = 100000000;
	// cur[0]+cur[1]+cur[2] == N
	// cur[1]+2cur[2] == cnt[1]+2cnt[2]
	for(cur[1] = 0; cur[1] <= N; cur[1]++) {
		if((cnt[1]-cur[1])&1) continue;
		cur[2] = (cnt[1]-cur[1])/2+cnt[2];
		cur[0] = N-cur[1]-cur[2];
		if(cur[0] < 0 || cur[1] < 0 || cur[2] < 0) continue;
		if(cnt[2] == 0) {
			if(cur[2] != 0) continue;
			if(cnt[1] == 0 && cur[1] != 0) continue;
		}
		if(mincost > min(cur[1], cnt[1]) + min(cur[0], cnt[0]) + min(cur[2], cnt[2])) {
			mincost = min(cur[1], cnt[1]) + min(cur[0], cnt[0]) + min(cur[2], cnt[2]);
			ans[0] = cur[0], ans[1] = cur[1], ans[2] = cur[2];
		}
	}
	cout << mincost << "\n";
	vector<int> Y;
	for(int i = 0; i < 3; i++) for(int j = 0; j < ans[i]; j++) Y.push_back(minx+i);
	for(int i = 0; i < N; i++) cout << Y[i] << ((i == N-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing