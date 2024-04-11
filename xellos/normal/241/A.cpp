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
	int M,K;
	scanf(" %d %d",&M,&K);
	vector<int> D(M);
	vector<int> S(M);
	for(int i =0; i < M; i++) scanf(" %d",&D[i]);
	for(int i =0; i < M; i++) scanf(" %d",&S[i]);

	int maxF =0, t =0, z =0;
	for(int i =0; i < M; i++) {
		maxF =max(maxF,S[i]);
		z +=S[i];
		if(z < D[i]) {
			int x =(D[i]-z)/maxF;
			if(x*maxF+z < D[i]) x++;
			t +=x*K;
			z +=x*maxF;}
		z -=D[i];
		t +=D[i];}
	printf("%d\n",t);
	return 0;}
        
// look at my code
// my code is amazing