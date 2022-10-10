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
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	vector<int> P(10000000+tisic,0);
	vector<int> A(10000000+tisic,0);
	vector<bool> isP(10000000+tisic,true);
	for(int i =0; i < N; i++) {
		int x;
		cin >> x;
		P[x]++;}

	for(int i =2; i < 10000000; i++) if(isP[i])
		for(int j =1; j <= 10000000/i; j++) {
			isP[i*j] =false;
			A[i] +=P[i*j];}

	for(int i =0; i <= 10000000; i++) A[i+1] +=A[i];

	int M;
	cin >> M;
	for(int q =0; q < M; q++) {
		int L,R;
		cin >> L >> R;
		R =min(R,10000000);
		L =min(L,R);
		cout << A[R]-A[L-1] << "\n";}
	return 0;}

// look at my code
// my code is amazing