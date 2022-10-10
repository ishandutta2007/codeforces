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
	int N,M;
	scanf(" %d %d",&N,&M);
	dbl d;
	vector<int> A(N);
	for(int i =0; i < N; i++) scanf(" %d %lf",&A[i],&d);

	vector<int> ans(N,0);
	int ansF =0;
	for(int i =0; i < N; i++) {
		for(int j =0; j < i; j++) if(A[j] <= A[i]) ans[i] =max(ans[i],ans[j]);
		ans[i] +=1;
		ansF =max(ansF,ans[i]);}

	printf("%d\n",N-ansF);
	return 0;}

// look at my code
// my code is amazing