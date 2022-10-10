// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
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
using namespace std::tr1;
	
int main() {
	long long N;
	scanf(" %I64d",&N);
	long long xA =1, xB =OVER9000;
	while(xB-xA > 1) {
		long long xC =(xA+xB)/2;
		if(xC*xC+81*xC >= N) xB =xC;
		else xA =xC;}
	for(long long x =xA; x*x <= N; x++) {
		long long y =x, s =0;
		while(y > 0) {
			s +=y%10;
			y /=10;}
		if(x*x+s*x == N) {
			printf("%I64d\n",x);
			return 0;}}
	printf("-1\n");
	return 0;}
        
// look at my code
// my code is amazing