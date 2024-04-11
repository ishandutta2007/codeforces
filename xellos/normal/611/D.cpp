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
	long long mod =1000000007;
	vector< vector<long long> > ans(N+1,vector<long long>(N+1,0));
	auto sum =ans;

	vector< vector<int> > fdig(N+1,vector<int>(N+1,N));
	for(int i =N-1; i >= 0; i--) for(int j =i+1; j < N; j++) {
		if(S[j] != S[i]) fdig[i][j] =0;
		else if(j < N-1) fdig[i][j] =fdig[i+1][j+1]+1;
		}

	for(int i =N-1; i >= 0; i--) if(S[i] != '0') {
		ans[i][N] =sum[i][N] =1;
		for(int j =N-1; j > i; j--) if(S[j] != '0') {
			// ans[i][j] == sum ans[j][k] pre S[j][k] > S[i][j] (teda k-j > j-i alebo k-j == j-i a S[j][j+d] > S[i][i+d])
			if(2*j-i > N) continue;
			int k =2*j-i+1;
			if(fdig[i][j]+i < j && S[j+fdig[i][j]] > S[i+fdig[i][j]]) k--;
			if(k <= N) ans[i][j] +=sum[j][k];
			if(ans[i][j] >= mod) ans[i][j] -=mod;}
		for(int j =N-1; j >= 0; j--) {
			sum[i][j] =ans[i][j]+sum[i][j+1];
			if(sum[i][j] >= mod) sum[i][j] -=mod;}
		}

	long long ansF =0;
	for(int i =1; i <= N; i++) {
		ansF +=ans[0][i];
		if(ansF >= mod) ansF -=mod;}
	cout << ansF << "\n";
	return 0;}

// look at my code
// my code is amazing