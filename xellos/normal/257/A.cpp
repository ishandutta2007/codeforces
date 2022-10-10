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
	int N,M,K;
	scanf(" %d %d %d",&N,&M,&K);
	vector<int> v(N);
	for(int i =0; i < N; i++) scanf(" %d",&v[i]);
	sort(v.begin(),v.end());
	int a =K;
	if(a >= M) {
		printf("0\n");
		return 0;}
	for(int i =N-1; i >= 0; i--) {
		a +=v[i]-1;
		if(a >= M) {
			printf("%d\n",N-i);
			return 0;}}
	printf("-1\n");
	return 0;}

// look at my code
// my code is amazing