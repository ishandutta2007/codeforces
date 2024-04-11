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
	int N, M;
	string S, T;
	cin >> N >> M;
	cin >> S >> T;
	int wc = -1;
	for(int i = 0; i < N; i++) if(S[i] == '*') wc = i;
	if(wc == -1) {
		if(S == T) cout << "YES\n";
		else cout << "NO\n";
		return 0;
	}
	string Sp = S.substr(0, wc), Ss = S.substr(wc+1, N-1-wc);
	if(M < (int)Sp.length()+(int)Ss.length()) {
		cout << "NO\n";
		return 0;
	}
	if(T.substr(0, Sp.length()) != Sp || T.substr(M-Ss.length(), Ss.length()) != Ss) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	return 0;
}

// look at my code
// my code is amazing