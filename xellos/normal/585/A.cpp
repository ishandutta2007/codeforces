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
	vector<long long> V(N),D(N),P(N);
	for(int i =0; i < N; i++) scanf(" %lld %lld %lld",&V[i],&D[i],&P[i]);
	vector<int> ans;
	vector<bool> live(N,true);
	for(int i =0; i < N; i++) if(live[i]) {
		int x =0;
		vector<long long> sum(N,0);
		for(int j =i+1; j < N; j++) if(live[j]) {
			P[j] -=max(0LL,V[i]-x);
			x++;
			if(P[j] < 0) {live[j] =false; sum[j] +=D[j];}
			}
		for(int j =i+1; j < N; j++) {
			sum[j] +=sum[j-1];
			P[j] -=sum[j];
			if(live[j] && P[j] < 0) {live[j] =false; sum[j] +=D[j];}
			}
		ans.push_back(i);}
	printf("%d\n",(int)ans.size());
	for(int i =0; i < (int)ans.size(); i++) {
		if(i > 0) printf(" ");
		printf("%d",ans[i]+1);}
	printf("\n");
	return 0;}

// look at my code
// my code is amazing