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
// mylittlepony
using namespace std;

int main() {
	int N,D;
	scanf(" %d %d",&N,&D);
	vector<int> P(N);
	for(int i =0; i < N; i++) scanf(" %d",&P[i]);
	
	int x =0,y =0;
	long long ans =0;
	while(x < N) {
		while(y < N) {
			if(P[y]-P[x] > D) break;
			y++;}
		ans +=(long long)(y-x-1)*(long long)(y-x-2);
		x++;}
	printf("%I64d\n",ans/2);
	return 0;}

// look at my code
// my code is amazing