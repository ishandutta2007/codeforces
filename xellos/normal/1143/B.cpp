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

int dig_prod(int n) {
	if(n == 0) return 0;
	int ret = 1;
	while(n > 0) {
		ret *= n%10;
		n /= 10;
	}
	return ret;
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	int ans = dig_prod(N);
	for(int k = 0; k < 9; k++) {
		int pw = 1;
		for(int i = 0; i <= k; i++) pw *= 10;
		pw--;
		// a * (pw+1) + pw <= N
		int a = (N+1) / (pw+1) - 1;
		if(a < 0) continue;
		ans = max(ans, dig_prod(a * (pw+1) + pw));
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing