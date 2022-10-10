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
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

struct fin {
	vector<int> T;
	fin(int N) {T.resize(N+tisic,0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] +=val;}

	int get(int pos) {
		int ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
		return ret;}
	};

long long pw(long long a, long long e, long long mod) {
	if(e <= 0) return 1;
	long long x =pw(a,e/2,mod);
	x =(x*x)%mod;
	if(x < 0) x +=mod;
	if(e%2 != 0) x =(x*a)%mod;
	if(x < 0) x +=mod;
	return x;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(N);
	fin F(100000);
	for(int i =0; i < N; i++) {
		cin >> A[i];
		F.put(100000-A[i],1);}

	vector< vector<int> > D(100000+tisic);
	for(int i =1; i <= 100000; i++)
		for(int j =1; j <= 100000/i; j++) D[i*j].push_back(i);

	long long ans =1, mod =1000000007;
	for(int m =2; m <= 100000; m++) {
		int M =D[m].size();
		vector<int> P(M+1,0);
		for(int i =0; i < M; i++) P[i] =F.get(100000-D[m][i]);
		for(int i =0; i < M; i++) P[i] -=P[i+1];
		long long a =1, b =1;
		for(int i =0; i < M; i++) a =(a*pw(i+1,P[i],mod))%mod;
		ans +=a;
		if(ans >= mod) ans -=mod;
		P[M-2] +=P[M-1];
		for(int i =0; i < M-1; i++) b =(b*pw(i+1,P[i],mod))%mod;
		ans -=b;
		if(ans < 0) ans +=mod;}

	ans %=mod;
	if(ans < 0) ans +=mod;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing