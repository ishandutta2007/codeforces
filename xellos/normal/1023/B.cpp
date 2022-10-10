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
	cat N, K;
	cin >> N >> K;
	cat miL = K-N, miR = N;
	cat mxL = K-1, mxR = 1;
	if(miL <= 0) {
		cat x = -miL+1;
		miL += x, miR -= x;
	}
	if(mxL > N) {
		cat x = mxL-N;
		mxL -= x, mxR += x;
	}
	if(mxL <= 0 || miL > N) {
		cout << "0\n";
		return 0;
	}
	if(miR < mxR) {
		cout << "0\n";
		return 0;
	}
	cat ans = miR-mxR+1;
	if(K%2 == 0 && K/2 > 0 && K/2 <= N) ans--;
	ans /= 2;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing