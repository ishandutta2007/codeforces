// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
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
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	int N;
	scanf(" %d",&N);
	vector<int> A(N);
	long long sum =0;
	for(int i =0; i < N; i++) {
		scanf(" %d",&A[i]);
		sum +=A[i];}
	if(sum%3 != 0) {printf("0\n"); return 0;}

	long long sp =0;
	vector<int> poc_pr(N+1,0);
	for(int i =0; i < N; i++) {
		sp +=A[i];
		if(sp*3 == sum) poc_pr[i+1] =poc_pr[i]+1;
		else poc_pr[i+1] =poc_pr[i];}

	sp =0;
	long long ans =0;
	for(int i =N-1; i > 0; i--) {
		sp +=A[i];
		if(sp*3 == sum) ans +=poc_pr[i-1];}

	printf("%I64d\n",ans);
	return 0;}

// look at my code
// my code is amazing