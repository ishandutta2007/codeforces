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
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	vector<int> Pi(N,1);
	for(int i =1; i < N; i++) if(A[i] > A[i-1]) Pi[i] =Pi[i-1]+1;
	vector<int> Pd(N,1);
	for(int i =N-2; i >= 0; i--) if(A[i] < A[i+1]) Pd[i] =Pd[i+1]+1;

	int ans =0;
	for(int i =0; i < N; i++) {
		if(i > 0 && i < N-1 && A[i-1] < A[i+1]-1) ans =max(ans,Pi[i-1]+Pd[i+1]+1);
		if(i > 0) ans =max(ans,Pi[i-1]+1);
		if(i < N-1) ans =max(ans,Pd[i+1]+1);}
	for(int i =0; i < N; i++) ans =max(ans,Pi[i]);
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing