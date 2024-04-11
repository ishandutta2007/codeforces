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
	int N;
	string S;
	cin >> N >> S;
	for(int i = 1; i < N; i++) if(S[i] == S[i-1] && S[i] != '?') {
		cout << "No\n";
		return 0;
	}
	if(S[0] == '?' || S[N-1] == '?') {
		cout << "Yes\n";
		return 0;
	}
	for(int i = 1; i < N-1; i++) if(S[i] == '?') {
		if(S[i-1] != '?' && S[i+1] != '?' && S[i-1] != S[i+1]) continue;
		cout << "Yes\n";
		return 0;
	}
	cout << "No\n";
	return 0;
}

// look at my code
// my code is amazing