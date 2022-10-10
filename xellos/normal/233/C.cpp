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
	int K;
	scanf(" %d",&K);
	int N =100, a;
	vector<int> c(N+1,0);
	for(int i =3; i <= N; i++) {
		c[i] =i*(i-1)*(i-2)/6;
		if(c[i] > K) {
			i--;
			a =i;
			K -=c[i];
			break;}}
	// klika velka a
	vector<int> d(N+1,0);
	for(int i =2; i <= N; i++) d[i] =i*(i-1)/2;

	vector<int> v;
	while(K > 0)
		for(int i =2; i <= a; i++) if(d[i] > K) {
			i--;
			K -=d[i];
			v.push_back(i);
			break;}
	N =a+(signed)v.size();
	printf("%d\n",N);
	vector< vector<int> > G(N);
	for(int i =0; i < N; i++) G[i].resize(N,0);
	for(int i =0; i < a; i++) for(int j =0; j < a; j++) G[i][j] =1;
	for(int i =0; i < (signed)v.size(); i++) for(int j =0; j < v[i]; j++) G[i+a][j] =G[j][i+a] =1;
	for(int i =0; i < N; i++) G[i][i] =0;
	for(int i =0; i < N; i++) {
		for(int j =0; j < N; j++) {
			printf("%d",G[i][j]);}
		printf("\n");}
	return 0;}
        
// look at my code
// my code is amazing