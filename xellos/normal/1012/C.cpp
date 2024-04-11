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
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	if(N == 1) {
		cout << "0\n";
		return 0;
	}
	vector< vector<cat> > costl(N+1, vector<cat>((N+1)/2+1, OVER9000));
	vector< vector<cat> > cost(N+1, vector<cat>((N+1)/2+1, OVER9000));
	cost[1][0] = cost[0][0] = costl[0][0] = costl[1][0] = costl[1][1] = 0;
	cost[1][1] = max(0, A[1]-A[0]+1);
	for(int i = 1; i < N; i++) {
		cost[i+1] = cost[i];
		for(int j = 0; j < (i+2)/2; j++) {
			// costl when using A[i]
			cat c = max(0, A[i-1]-A[i]+1) + ((i == 1) ? 0 : cost[i-2][j]);
			if(i > 1) c = min(c, max(0, A[i-1]-min(A[i], A[i-2])+1) + costl[i-1][j]);
			costl[i+1][j+1] = min(costl[i+1][j+1], c);
			cost[i+1][j+1] = min(cost[i+1][j+1], c + ((i != N-1) ? max(0, A[i+1]-A[i]+1) : 0));
		}
	}
	for(int i = 1; i <= (N+1)/2; i++) cout << cost[N][i] << ((i == (N+1)/2) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing