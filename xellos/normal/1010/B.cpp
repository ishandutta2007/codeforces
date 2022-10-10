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
#define soclose 1e-7
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl double
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
	int M, N;
	cin >> M >> N;
	vector<int> correct(N);
	for(int i = 0; i < N; i++) {
		cout << M-i << endl;
		int ans;
		cin >> ans;
		if(ans == 0) return 0;
		if(ans == -1) correct[i] = true;
		else correct[i] = false;
	}
	cat x_min = 0, x_max = M-N;
	int cur = 0;
	while(x_max-x_min > 1) {
		cat x = (x_max+x_min) / 2;
		cout << x << endl;
		int ans;
		cin >> ans;
		if(!correct[cur]) ans = -ans;
		cur = (cur+1)%N;
		if(ans == 0) return 0;
		if(ans == -1) x_max = x-1;
		else x_min = x;
	}
	cout << x_max << endl;
	int ans;
	cin >> ans;
	return 0;
}

// look at my code
// my code is amazing