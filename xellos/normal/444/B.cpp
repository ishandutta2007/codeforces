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
#include <time.h>
// mylittlepony
using namespace std;

long long x;

long long nxt() {
	x =(x*37+10007)%1000000007;
	return x;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,D;
	cin >> N >> D >> x;
	vector<int> A(N),B(N,0),pos(N);
	for(int i =0; i < N; i++) A[i] =i;
	for(int i =0; i < N; i++) swap(A[i],A[nxt()%(i+1)]);
	for(int i =0; i < N; i++) pos[A[i]] =i;
	for(int i =0; i < D; i++) B[i] =1;
	for(int i =0; i < N; i++) swap(B[i],B[nxt()%(i+1)]);
	vector<int> isB;
	for(int i =0; i < N; i++) if(B[i] == 1) isB.push_back(i);

	vector<int> C(N,-1);
	int dt =50000000, d =0;
	for(int i =N-1; i >= 0; i--) {
		for(int j =0; j < isB.size(); j++) {
			if(isB[j]+pos[i] >= N) break;
			if(C[isB[j]+pos[i]] == -1) C[isB[j]+pos[i]] =i;
			d++;}
		if(d > dt) break;}

	for(int i =0; i < N; i++) if(C[i] == -1) {
		for(int j =0; j < isB.size(); j++) {
			if(isB[j] > i) break;
			C[i] =max(C[i],A[i-isB[j]]);}
		}

	for(int i =0; i < N; i++) cout << C[i]+1 << "\n";
	return 0;}

// look at my code
// my code is amazing