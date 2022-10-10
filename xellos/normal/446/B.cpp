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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M,K;
	long long P;
	cin >> N >> M >> K >> P;
	vector<long long> R(N,0),C(M,0);
	for(int i =0; i < N; i++) for(int j =0; j < M; j++) {
		int a;
		cin >> a;
		R[i] +=a, C[j] +=a;}
	priority_queue<long long> qR,qC;
	for(int i =0; i < N; i++) qR.push(R[i]);
	for(int i =0; i < M; i++) qC.push(C[i]);

	vector<long long> ansR(K+1,0),ansC(K+1,0);
	for(int i =0; i < K; i++) {
		ansR[i+1] =ansR[i]+qR.top();
		long long a =qR.top();
		qR.pop();
		qR.push(a-P*M);
		ansC[i+1] =ansC[i]+qC.top();
		a =qC.top();
		qC.pop();
		qC.push(a-P*N);}
//	for(int i =1; i <= K; i++) {
//		ansR[i] =max(ansR[i],ansR[i-1]);
//		ansC[i] =max(ansC[i],ansC[i-1]);}

	long long ans =-OVER9000;
	for(int i =0; i <= K; i++) ans =max(ans,ansR[i]+ansC[K-i]-1LL*i*(K-i)*1LL*P);
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing