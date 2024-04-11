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
#define OVER9000 1234567890123456789LL
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
	for(int i =0; i < N; i++) scanf(" %d",&A[i]);
	for(int i =0; i < N; i++) {
		int mi =(i == 0)?(A[i+1]-A[i]):(A[i]-A[i-1]);
		if(i < N-1) mi =min(mi,A[i+1]-A[i]);
		if(i > 0) mi =min(mi,A[i]-A[i-1]);
		int mx =max(A[i]-A[0],A[N-1]-A[i]);
		printf("%d %d\n",mi,mx);}
	return 0;}

// look at my code
// my code is amazing