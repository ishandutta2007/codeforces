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
	int N,D,L;
	scanf(" %d %d %d",&N,&D,&L);
	vector<int> C(N,1);
	for(int i =1; i < N; i +=2) C[i] =L;
	int sum =0;
	for(int i =0; i < N; i++) {
		if(i%2 == 0) sum +=C[i];
		else sum -=C[i];}
	int a =0;
	while(sum < D) {
		if(a == N) break;
		if(a%2 == 0) {
			if(C[a] == L) {
				a++;
				continue;}
			C[a]++;
			sum++;}
		if(a%2 == 1) {
			if(C[a] == 1) {
				a++;
				continue;}
			C[a]--;
			sum++;}}
	if(sum != D) printf("-1");
	else for(int i =0; i < N; i++) {
		if(i > 0) printf(" ");
		printf("%d",C[i]);}
	printf("\n");
	return 0;}
        
// look at my code
// my code is amazing