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
	int N;
	scanf(" %d",&N);
	if(N%2 == 1) {
		printf("-1\n");
		return 0;}
	vector<int> V(N);
	for(int i =0; i < N; i++) {
		if(i > 0) printf(" ");
		printf("%d",N-i);}
	printf("\n");
	return 0;}
        
// look at my code
// my code is amazing