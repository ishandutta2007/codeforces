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
	int N,K;
	scanf(" %d %d",&N,&K);
	vector<int> P(N);
	for(int i =0; i < N; i++) scanf(" %d",&P[i]);
	vector<int> S(N);
	for(int i =0; i < N; i++) scanf(" %d",&S[i]);
	vector<int> I(N);
	for(int i =0; i < N; i++) for(int j =0; j < N; j++) if(P[j] == i+1) I[i] =j+1;
	
	vector< vector<int> > V(2*K+1);
	for(int i =0; i < 2*K+1; i++) V[i].resize(N);
	for(int i =0; i < N; i++) V[K][i] =i+1;
	
	for(int i =0; i < K; i++) {
		for(int j =0; j < N; j++) V[K+i+1][P[j]-1] =V[K+i][j];
		for(int j =0; j < N; j++) V[K-i-1][I[j]-1] =V[K-i][j];}
/*	for(int i =0; i <= 2*K; i++) {
		for(int j =0; j < N; j++) printf("%d ",V[i][j]);
		printf("\n");}
	*/
	
	int x =-1,y =2*K+1;
	for(int i =K; i >= 0; i--) if(V[i] == S) {
		x =i;
		break;}
	for(int i =K; i <= 2*K; i++) if(V[i] == S) {
		y =i;
		break;}
	
	if(V[K] == S) {
		printf("NO\n");
		return 0;}
	if(y == 2*K || x == 0) {
		printf("YES\n");
		return 0;}
	if(y == K+1 && x == K-1) {
		printf("NO\n");
		return 0;}
	while(y < 2*K) y +=2;
	while(x > 0) x -=2;
	if(y == 2*K || x == 0) printf("YES\n");
	else printf("NO\n");
	return 0;}

// look at my code
// my code is amazing