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
	string S;
	cin >> S;
	int N = S.length();
	int l = 0, r = N;
	string ans_l = "", ans_r = "";
	while(r-l >= 4) {
		if(S[l] == S[r-1]) {
			ans_l += S[l];
			ans_r += S[r-1];
		}
		else if(S[l] == S[r-2]) {
			ans_l += S[l];
			ans_r += S[r-2];
		}
		else if(S[l+1] == S[r-1]) {
			ans_l += S[l+1];
			ans_r += S[r-1];
		}
		else {
			ans_l += S[l+1];
			ans_r += S[r-2];
		}
		l += 2, r -= 2;
		continue;
	}
	if(r > l) ans_l += S[l];
	reverse(begin(ans_r), end(ans_r));
	cout << ans_l+ans_r << "\n";
	return 0;
}

// look at my code
// my code is amazing