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
	cat c[3][2];
	cin >> c[0][0] >> c[0][1] >> c[1][0] >> c[1][1] >> c[2][0] >> c[2][1];
	cat st[2];
	cat T;
	cin >> st[0] >> st[1] >> T;
	cat P[100][2];
	P[0][0] = c[0][0], P[0][1] = c[0][1];
	int N = 1;
	for(int i = 0; i < 90; i++) {
		if(st[0]+T-c[2][0] < 0 || P[i][0] > (st[0]+T-c[2][0])/c[1][0]) break;
		if(st[1]+T-c[2][1] < 0 || P[i][1] > (st[1]+T-c[2][1])/c[1][1]) break;
		P[i+1][0] = P[i][0]*c[1][0]+c[2][0];
		P[i+1][1] = P[i][1]*c[1][1]+c[2][1];
		N++;
	}
	int ans = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j <= i; j++) for(int k = i; k < N; k++) {
		cat dist = abs(P[i][0]-st[0])+abs(P[i][1]-st[1]);
		dist += P[i][0]-P[j][0] + P[i][1]-P[j][1];
		dist += P[k][0]-P[j][0] + P[k][1]-P[j][1];
		if(dist <= T) ans = max(ans, k-j+1);
	}
	for(int i = 0; i < N; i++) for(int j = 0; j <= i; j++) for(int k = i; k < N; k++) {
		cat dist = abs(P[i][0]-st[0])+abs(P[i][1]-st[1]);
		dist += P[k][0]-P[i][0] + P[k][1]-P[i][1];
		dist += P[k][0]-P[j][0] + P[k][1]-P[j][1];
		if(dist <= T) ans = max(ans, k-j+1);
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing