#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265359
using namespace std;
// mylittledoge

struct fin {
	vector<int> T;
	fin(int N) {T.resize(N+tisic,0);}

	int lastone(int x) {return x&(x^(x-1));}

	int get(int pos) {
		int ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
		return ret;}

	void put(int pos, int val) {
		for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] +=val;}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> A(N);
	map<int,int> M;
	for(int i =0; i < N; i++) {
		cin >> A[i];
		M[A[i]] =0;}
	int m =0;
	ALL_THE(M,it) it->ss =m++;
	for(int i =0; i < N; i++) A[i] =M[A[i]];
	vector<long long> ans(N,0);

	// K small
	fin F(m);
	int K =min(N-1,150);
	for(int k =1; k <= K; k++) {
		int a =0, b =0; // [a,b)
		for(int i =0; i < N; i++) {
			if(1LL*k*i+1 >= N) break;
			while(a < k*i+1) {
				F.put(A[a],-1);
				a++;}
			while(b <= min(N-1,k*i+k)) {
				F.put(A[b],1);
				b++;}
			ans[k] +=F.get(A[i]-1);}
		for(int i =0; i <= m; i++) F.T[i] =0;}

	// K large
	vector<int> S(N+1,0);
	for(int i =0; 1LL*i*(K+1)+1 < N; i++) {
		for(int j =0; j < N; j++) {
			if(A[j] < A[i]) S[j+1] =S[j]+1;
			else S[j+1] =S[j];}
		for(int k =K+1; 1LL*k*i+1 < N; k++) {
			if(k >= N) break;
			ans[k] +=S[min(N-1,k*i+k)+1]-S[k*i+1];}
		for(int j =0; j <= N; j++) S[j] =0;}

	for(int i =1; i < N; i++) cout << ans[i] << " ";
	cout << "\n";
	return 0;}

// look at my code
// my code is amazing