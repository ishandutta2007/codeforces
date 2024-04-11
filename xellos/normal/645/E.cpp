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
	int N,K;
	string S;
	cin >> N >> K >> S;
	vector< pair<int,int> > last(K);
	for(int i =0; i < K; i++) last[i].ff =0, last[i].ss =i;
	for(int i =0; i < (int)S.length(); i++) last[S[i]-'a'].ff =i+1;
	sort(begin(last),end(last));
	while(N > 0) {
		int k =min(K,N);
		for(int i =0; i < k; i++) S +=('a'+last[i].ss);
		N -=k;}
	vector<int> lastDP(K,0);
	long long mod =1000000007;
	N =S.length();
	vector<long long> DP(N+1,0),sum(N+2,0);
	DP[0] =sum[1] =1;
	for(int i =0; i < N; i++) {
		DP[i+1] =sum[i+1]-sum[lastDP[S[i]-'a']];
		if(DP[i+1] < 0) DP[i+1] +=mod;
		lastDP[S[i]-'a'] =i+1;
		sum[i+2] =DP[i+1]+sum[i+1];
		if(sum[i+2] >= mod) sum[i+2] -=mod;}
	cout << sum[N+1] << "\n";
	return 0;}

// look at my code
// my code is amazing