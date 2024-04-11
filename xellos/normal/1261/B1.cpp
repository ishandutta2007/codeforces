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
#define OVER9000 1234567890123456789LL
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
	int N, Q;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	cin >> Q;
	vector< vector<cat> > max_sum(N+1, vector<cat>(N+1, -OVER9000));
	max_sum[N][0] = 0;
	vector< vector<int> > seq(N+1);
	for(int i = N-1; i >= 0; i--) {
		max_sum[i] = max_sum[i+1];
		for(int j = 0; j < N; j++)
			max_sum[i][j+1] = max(max_sum[i][j+1], max_sum[i+1][j] + A[i]);
	}
	for(int l = 1; l <= N; l++) {
		int cur = 0;
		for(int i = 0; i < l; i++) {
			cat m = max_sum[cur][l-i];
			int v = OVER9000, pos = -1;
			for(int j = N-1; j >= cur; j--) if(m == max_sum[j+1][l-i-1] + A[j])
				if(A[j] <= v) v = A[j], pos = j;
			seq[l].push_back(v);
			cur = pos+1;
		}
	}
	for(int q = 0; q < Q; q++) {
		int K, id;
		cin >> K >> id;
		id--;
		cout << seq[K][id] << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing