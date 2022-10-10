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
	for(int i =0; i < N; i++) scanf(" %d",&A[i]);
	int mi =OVER9000;
	for(int i =0; i < N; i++) mi =min(mi,A[i]);
	int a =-1;
	for(int i =0; i < N; i++) if(A[i] == mi) {
		a =i;
		break;}
	if(a == 0) {
		if(A[N-1] == mi) a =N-1;
		while(a > 0 && A[a-1] == mi) a--;}
	bool ok =true;
	for(int i =1; i < N; i++) if(A[(a+i)%N] < A[(a+i-1)%N]) ok =false;
	if(!ok) printf("-1\n");
	else printf("%d\n",(N-a)%N);
	return 0;}

// look at my code
// my code is amazing