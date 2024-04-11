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
	int M,N;
	cin >> M >> N;
	vector<long long> A(M),B(N);
	for(int i =0; i < M; i++) cin >> A[i];
	sort(A.begin(),A.end());
	for(int i =0; i < N; i++) cin >> B[i];
	sort(B.begin(),B.end());

	int a =0;
	long long S =0,ans1 =0,ans2 =0;
	for(int i =0; i < M; i++) {
		while(a < N && (i == M-1 || B[a] <= A[i])) {
			S +=B[a];
			a++;}
		if(i == M-1) ans1 +=S+(N-a)*A[i];
		else ans1 +=min(A[i],S+(N-a)*A[i]);}

	S =a =0;
	for(int i =0; i < N; i++) {
		while(a < M && (i == N-1 || A[a] <= B[i])) {
			S +=A[a];
			a++;}
		if(i == N-1) ans2 +=S+(M-a)*B[i];
		else ans2 +=min(B[i],S+(M-a)*B[i]);}

	cout << min(ans1,ans2) << "\n";
	return 0;}

// look at my code
// my code is amazing