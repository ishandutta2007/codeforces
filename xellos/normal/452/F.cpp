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
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456780LL
#define patkan 9
#define tisic 47
#define soclose 1e-7
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#define ull unsigned long long
#include <time.h>
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	scanf(" %d",&N);
	vector<int> P(N),pos(N);
	for(int i =0; i < N; i++) {
		scanf(" %d",&P[i]);
		pos[--P[i]] =i;}

	if(N <= 20000) {
		for(int i =0; i < N; i++) for(int j =i+1; j < N; j++) if((P[i]-P[j])%2 == 0) 
			if(pos[(P[i]+P[j])/2] > i && pos[(P[i]+P[j])/2] < j) {
				printf("YES\n");
				return 0;}
		printf("NO\n");
		return 0;}

	if((P[0]-P[N-1])%2 == 0) {printf("YES\n"); return 0;}

	vector<int> Pd[2];
	for(int i =0; i < N; i++) Pd[P[i]%2].push_back(P[i]);

	srand(N);
	for(int k =0; k < 50000; k++) {
		int t =rand()%2;
		int a =rand()%Pd[t].size(), b =rand()%Pd[t].size();
		if(a > b) swap(a,b);
		if(a != b && pos[(Pd[t][a]+Pd[t][b])/2] > pos[Pd[t][a]] && pos[(Pd[t][a]+Pd[t][b])/2] < pos[Pd[t][b]]) {
			printf("YES\n");
			return 0;}
		}
	for(int i =0; i < 500; i++) for(int j =N-500; j < N; j++) if((P[i]-P[j])%2 == 0) 
		if(pos[(P[i]+P[j])/2] > i && pos[(P[i]+P[j])/2] < j) {
			printf("YES\n");
			return 0;}

	vector< vector<ull> > pos_sh(64,vector<ull>(2*(N/64)+tisic,0)); // 2y-x+32*(N/32+1), (2y)%32
	vector<ull> V(4*(N/64)+tisic,0);
	int n =N/64;
	for(int i =0; i < N; i++) {
		int a =P[i]+64*(n+1); // y+j <= 2*(N/64)+1
		if((V[a/64]>>(a%64))&1) {printf("YES\n"); return 0;}
		int x =(2*P[i])%64, y =(2*P[i])/64;
		int mi =max(0,n+1-y), mx =min(n+tisic,2*n+2-y);
		if(i < 200000 || i%2 == 0) for(int j =mi; j < mx; j++) V[y+j] |=pos_sh[x][j];
		for(int y =0; y < 64; y +=2) {
			int a =y-P[i]+64*(n+1);
			pos_sh[y][a/64] |=1LL<<(a%64);}
		}

	printf("NO\n");
	return 0;}

// look at my code
// my code is amazing