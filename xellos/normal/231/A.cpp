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
	int N,a =0;
	scanf(" %d",&N);
	for(int i =0; i < N; i++) {
		int b =0,c;
		for(int j =0; j < 3; j++) {
			scanf(" %d",&c);
			b +=c;}
		if(b >= 2) a++;}
	printf("%d\n",a);
	return 0;}
        
// look at my code
// my code is amazing