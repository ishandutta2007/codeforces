// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define chocolate win
// mylittlepony
using namespace std;

int main() {
	int N,t,a,b,l =1;
	scanf(" %d",&N);
	vector<int> A(N+1,0);
	vector<int> K(N+1,0);
	long long s =0;
	for(int i =0; i < N; i++) {
		scanf(" %d",&t);
		if(t == 1) {
			scanf(" %d %d",&a,&b);
			s +=(long long)a*(long long)b;
			A[a-1] +=b;}
		if(t == 2) {
			scanf(" %d",&a);
			s +=a;
			K[l] =a;
			l++;}
		if(t == 3) {
			A[l-2] +=A[l-1];
			s -=A[l-1]+K[l-1];
			A[l-1] =0;
			K[l-1] =0;
			l--;}
		printf("%.8f\n",(double)s/(double)l);}
	return 0;}

// look at my code
// my code is amazing