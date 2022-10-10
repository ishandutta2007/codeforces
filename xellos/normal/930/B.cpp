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
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

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
	int L = S.length();
	vector<int> rots[26];
	for(int i = 0; i < L; i++) rots[S[i]-'a'].push_back(i);
	int cnt_wins = 0;
	for(int i = 0; i < 26; i++) {
		int mxcov = 0;
		for(int j = 0; j < L; j++) {
			int b = 0, b2 = 0;
			for(int k = 0; k < (int)rots[i].size(); k++) {
				int c = 1<<(S[(rots[i][k]+j)%L]-'a');
				if((b&c)) b2 |= c;
				b |= c;
			}
			int cov = 0;
			for(int k = 0; k < 26; k++) cov += ((b^b2)>>k)&1;
			mxcov = max(mxcov, cov);
		}
		cnt_wins += mxcov;
	}
	cout << double(cnt_wins)/L << "\n";
	return 0;}

// look at my code
// my code is amazing