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
	long long N,A,B;
	scanf(" %I64d %I64d %I64d",&N,&A,&B);
	long long ansX =6*N, ansY =B;
	if(A*B >= 6*N) ansX =A;
	for(long long i =A; i <= 100000; i++) {
		long long j =6*N/i;
		while(j*i < 6*N) j++;
		j =max(j,B);
		if(ansX*ansY > i*j) {
			ansX =i;
			ansY =j;}
		}
	for(long long i =B; i <= 100000; i++) {
		long long j =6*N/i;
		while(j*i < 6*N) j++;
		j =max(j,A);
		if(ansX*ansY > i*j) {
			ansX =j;
			ansY =i;}
		}
	printf("%I64d\n%I64d %I64d",ansX*ansY,ansX,ansY);
	return 0;}

// look at my code
// my code is amazing