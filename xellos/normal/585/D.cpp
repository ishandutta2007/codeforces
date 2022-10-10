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
	scanf(" %d",&N);
	vector< vector<int> > V(3,vector<int>(N));
	for(int i =0; i < N; i++) for(int j =0; j < 3; j++) scanf(" %d",&V[j][i]);

	map< pair<long long,long long>, pair<long long,int> > M;
	int pw3 =1;
	for(int i =0; i < N/2; i++) pw3 *=3;
	for(int i =0; i < pw3; i++) {
		long long sum[3] ={0,0,0};
		int x =i;
		for(int j =0; j < N/2; j++) {
			for(int k =0; k < 3; k++) if(x%3 != k) sum[k] +=V[k][j];
			x /=3;}
		auto it =M.find(make_pair(sum[1]-sum[0],sum[2]-sum[0]));
		if(it == end(M)) M[make_pair(sum[1]-sum[0],sum[2]-sum[0])] =make_pair(sum[0],i);
		else if(it->ss.ff < sum[0]) it->ss =make_pair(sum[0],i);
		}

	if(N%2 != 0) pw3 *=3;
	pair<int,int> ans =make_pair(-1,-1);
	long long anss =-1000000000000000LL;
	for(int i =0; i < pw3; i++) {
		long long sum[3] ={0,0,0};
		int x =i;
		for(int j =N/2; j < N; j++) {
			for(int k =0; k < 3; k++) if(x%3 != k) sum[k] +=V[k][j];
			x /=3;}
		auto it =M.find(make_pair(-sum[1]+sum[0],-sum[2]+sum[0]));
		if(it == end(M)) continue;
		else if(anss < it->ss.ff+sum[0]) {
			ans =make_pair(it->ss.ss,i);
			anss =it->ss.ff+sum[0];}
		}

	if(ans.ff == -1) {printf("Impossible\n"); return 0;}
	string comp ="LMW";
	for(int i =0; i < N/2; i++) {
		for(int k =0; k < 3; k++) if(ans.ff%3 != k) printf("%c",comp[k]);
		printf("\n");
		ans.ff /=3;}
	for(int i =0; i < N-N/2; i++) {
		for(int k =0; k < 3; k++) if(ans.ss%3 != k) printf("%c",comp[k]);
		printf("\n");
		ans.ss /=3;}
	return 0;}

// look at my code
// my code is amazing