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
#define dbl double
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
	int N;
	cin >> N;
	vector<int> M(N);
	cat sum = 0, sub = 0;
	for(int i = 0; i < N; i++) {
		cin >> M[i];
		sub += M[i]+1;
	}
	vector<int> cnt(N, 1);
	for(int i = 1; i < N; i++) {
		cnt[i] = cnt[i-1];
		if(M[i]+1 > cnt[i]) cnt[i] = M[i]+1;
	}
	for(int i = N-1; i > 0; i--) cnt[i-1] = max(cnt[i-1], cnt[i]-1);
	for(int i = 0; i < N; i++) sum += cnt[i];
	cout << sum-sub << "\n";
	return 0;}

// look at my code
// my code is amazing