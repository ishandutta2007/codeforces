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
	int cov[300][300];
	memset(cov, 0, sizeof(cov));
	int x[3][2], y[3][2];
	cin >> x[0][0] >> y[0][0];
	for(int i = 0; i < 3; i++) {
		int xn, yn;
		cin >> xn >> yn;
		if(xn != x[0][0]) x[0][1] = xn;
		if(yn != y[0][0]) y[0][1] = yn;
	}
	if(x[0][0] > x[0][1]) swap(x[0][0], x[0][1]);
	if(y[0][0] > y[0][1]) swap(y[0][0], y[0][1]);
	for(int i = 110+x[0][0]; i < 110+x[0][1]; i++)
		for(int j = 110+y[0][0]; j < 110+y[0][1]; j++)
			cov[i][j] |= 1;
	cin >> x[1][0] >> y[1][0] >> x[2][0] >> y[2][0] >> x[1][1] >> y[1][1] >> x[2][1] >> y[2][1];
	if(y[1][0] > y[1][1]) swap(y[1][0], y[1][1]);
	if(x[1][0] > x[1][1]) swap(x[1][0], x[1][1]);
	if(y[2][0] > y[2][1]) swap(y[2][0], y[2][1]);
	if(x[2][0] > x[2][1]) swap(x[2][0], x[2][1]);
	if(x[1][0] != x[1][1]) {
		swap(x[1][0], x[2][0]);
		swap(x[1][1], x[2][1]);
		swap(y[1][0], y[2][0]);
		swap(y[1][1], y[2][1]);
	}
	for(int i = x[2][0]-3; i < x[2][1]+3; i++)
		for(int j = y[1][0]-3; j < y[1][1]+3; j++) {
			if(i+j+2 < x[1][0]+y[1][0]) continue;
			if(i+j > x[1][0]+y[1][1]) continue;
			if(i-j-1 > x[2][1]-y[2][0]) continue;
			if(i-j+1 < x[2][0]-y[2][0]) continue;
			cov[i+110][j+110] |= 2;
		}
	for(int i = 0; i < 300; i++) for(int j = 0; j < 300; j++) if(cov[i][j] == 3) {
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
	return 0;}

// look at my code
// my code is amazing