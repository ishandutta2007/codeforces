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
	int N,K;
	scanf(" %d %d",&N,&K);
	vector<int> A(K);
	for(int i =0; i < K; i++) {
		scanf(" %d",&A[i]);
		A[i]--;}
	vector<bool> F(N*K,true);
	for(int i =0; i < K; i++) F[A[i]] =false;
	for(int i =0; i < K; i++) {
		printf("%d",A[i]+1);
		int a =1;
		for(int j =0; j < N*K; j++) if(F[j]) {
			printf(" %d",j+1);
			F[j] =false;
			a++;
			if(a == N) break;}
		printf("\n");}

	return 0;}
        
// look at my code
// my code is amazing