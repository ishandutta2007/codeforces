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
	long long N,K;
	scanf(" %I64d %I64d",&N,&K);
	K--;
	N--;
	K =min(K,N);
	if(K*(K+1)/2 < N) {printf("-1\n"); return 0;}
	int ans =0;
	while(N > 0) {
		K =min(K,N);
		// N -=K+(K-1)+..+L = K*(K+1)/2-L*(L-1)/2
		long long x =sqrt(K*(K+1)-2*N);
		while(K*(K+1)-x*(x-1) > 2*N || x == 0) x++;
		N -=K*(K+1)/2-x*(x-1)/2;
		ans +=K-x+1;
		K =min(K-1,x-1);}
	printf("%d\n",ans);
	return 0;}

// look at my code
// my code is amazing