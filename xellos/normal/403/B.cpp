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
#include <time.h>
// mylittlepony
using namespace std;

int gcd(int a, int b) {
	if(a > b) swap(a,b);
	if(a == 0) return b;
	return gcd(b%a,a);}

int main() {
	cin.sync_with_stdio(0);
	int N,M;
	cin >> N >> M;

	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];

	set<int> B;
	for(int i =0; i < M; i++) {
		int b;
		cin >> b;
		B.insert(b);}

	vector<int> G(N+1,1);
	G[0] =A[0];
	for(int i =1; i < N; i++) G[i] =gcd(A[i],G[i-1]);

	vector<int> Ab(N,0),Gb(N+1,0);
	for(int i =0; i < N; i++) {
		for(int j =2; j*j <= A[i]; j++) if(A[i]%j == 0) {
			int k =1;
			if(B.find(j) != B.end()) k =-1;
			while(A[i]%j == 0) {A[i] /=j; Ab[i] +=k;}}
		if(A[i] > 1) {
			if(B.find(A[i]) == B.end()) Ab[i]++;
			else Ab[i]--;}
		for(int j =2; j*j <= G[i]; j++) if(G[i]%j == 0) {
			int k =1;
			if(B.find(j) != B.end()) k =-1;
			while(G[i]%j == 0) {G[i] /=j; Gb[i] +=k;}}
		if(G[i] > 1) {
			if(B.find(G[i]) == B.end()) Gb[i]++;
			else Gb[i]--;}}

	int B0 =0;
	for(int i =0; i < N; i++) B0 +=Ab[i];

	vector<int> ans(N+1,-OVER9000); ans[N] =B0;
	int ansR =B0;
	for(int i =N-1; i >= 0; i--) {
		for(int j =i+1; j <= N; j++) if(ans[j] > -OVER9000)
			ans[i] =max(ans[i],ans[j]+(i+1)*(Gb[j]-Gb[i]));
		ansR =max(ansR,ans[i]);}
	cout << ansR << "\n";
	return 0;}

// look at my code
// my code is amazing