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
	int Y,K,N;
	scanf(" %d %d %d",&Y,&K,&N);
	bool z =false;
	for(int i =1; i <= N/K; i++) if(i*K-Y > 0) {
		if(z) printf(" ");
		else z =true;
		printf("%d",i*K-Y);}
	if(!z) printf("-1");
	printf("\n");
	return 0;}
        
// look at my code
// my code is amazing