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
// mylittledoge
using namespace std;

struct fin {
	vector<int> T;
	fin(int N) {T.resize(N,0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] +=val;}

	int get(int pos) {
		int ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
		return ret;}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];

	vector<int> F1(N,0),F2(N,0);
	map<int,int> M;
	for(int i =0; i < N; i++) {
		if(M.find(A[i]) == M.end()) F1[i] =1;
		else F1[i] =F1[M[A[i]]]+1;
		M[A[i]] =i;}
	M.clear();
	for(int i =N-1; i >= 0; i--) {
		if(M.find(A[i]) == M.end()) F2[i] =1;
		else F2[i] =F2[M[A[i]]]+1;
		M[A[i]] =i;}

	fin F(N+tisic);
	for(int i =0; i < N; i++) F.put(F2[i],1);
	long long ans =0;
	for(int i =0; i < N; i++) {
		F.put(F2[i],-1);
		ans +=F.get(F1[i]-1);}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing