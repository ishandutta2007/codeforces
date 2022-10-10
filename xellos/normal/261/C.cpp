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

vector< vector<long long> > ans(100+tisic);

long long Ans(long long N, int P) {
	if(N == 1) return (int)(P == 0);
	long long a =1;
	int p =0;
	// find 2^p-1 <= N
	while(a-1 <= N) {
		a *=2;
		p++;}
	if(a-1 > N) {
		a /=2;
		p--;}
	long long ret =ans[p][P];
	// 1. 2^p-1 == N
	if(a-1 == N) return ret;
	// 2. 2^p-1 + 1 == N
	if(a <= N && P == 0) ret++;
	if(a == N) return ret;
	// 3.
	if(P > 0) ret +=Ans(N-a,P-1);
	return ret;}

int main() {
	long long N,T;
	int P =0;
	scanf(" %I64d %I64d",&N,&T);
	while(T > 1) {
		if(T%2 != 0) {
			printf("0\n");
			return 0;}
		P++;
		T /=2;}
	
	ans[1].resize(100+tisic,0);
	ans[1][0] =1; // 2^i-1 rows
	for(int i =1; i < 100; i++) {
		ans[i+1] =ans[i];
		for(int j =0; j < 100; j++) ans[i+1][j+1] +=ans[i][j];
		ans[i+1][0]++;}
		
	N++;
	printf("%I64d\n",Ans(N,P)-(int)(P == 0));
	
/*	vector< vector<bool> > V(N+1);
	for(int i =0; i <= N; i++) V[i].resize(N+1,0);
	V[0][N] =1;
	for(int i =1; i <= N; i++) for(int j =0; j <= N; j++) {
		if(j == 0) V[i][j] =V[i-1][j+1];
		else if(j == N) V[i][j] =V[i-1][j-1];
		else V[i][j] =V[i-1][j+1]^V[i-1][j-1];}
	for(int i =0; i <= N; i++) {
		for(int j =0; j <= N; j++) printf("%d",(int)V[i][j]);
		printf("\n");}
*/	return 0;}

// look at my code
// my code is amazing