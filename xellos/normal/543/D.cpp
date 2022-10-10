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

long long pw(long long a, long long e, long long MOD) {
	if(e <= 0) return 1;
	long long x =pw(a,e/2,MOD);
	x =(x*x)%MOD;
	if(x < 0) x +=MOD;
	if(e%2 != 0) x =(x*a)%MOD;
	if(x < 0) x +=MOD;
	return x;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector< vector<int> > G(N);
	vector<int> par(N,-1);
	for(int i =1; i < N; i++) {
		cin >> par[i];
		G[--par[i]].push_back(i);}
	long long MOD =1000000007;

	vector<long long> A[2]; // dole hranou, hore hranou, neda sa pridat dalsia
	for(int i =0; i < 2; i++) A[i].resize(N,1);

	for(int i =N-1; i > 0; i--) 
		ALL_THE(G[i],it) {
			A[0][i] =(A[0][i]*(A[0][*it]+1))%MOD;
			if(A[0][i] < 0) A[0][i] +=MOD;}

	for(int i =0; i < N; i++) {
		long long p =1;
		ALL_THE(G[i],it) {
			p =(p*(A[0][*it]+1))%MOD;
			if(p < 0) p +=MOD;}
		if(p == 0) ALL_THE(G[i],it) if((A[0][*it]+1)%MOD == 0) {
			ALL_THE(G[i],jt) if(it != jt) A[1][*jt] =0;
			ALL_THE(G[i],jt) if(it != jt) {
				A[1][*it] =(A[1][*it]*(A[0][*jt]+1))%MOD;
				if(A[1][*it] < 0) A[1][*it] +=MOD;}
			if(i > 0) {
				A[1][*it] =(A[1][*it]*(A[1][i]+1))%MOD;
				if(A[1][*it] < 0) A[1][*it] +=MOD;}
			break;}
		if(p == 0) continue;
		ALL_THE(G[i],it) {
			A[1][*it] =(p*pw(A[0][*it]+1,MOD-2,MOD))%MOD;
			if(A[1][*it] < 0) A[1][*it] +=MOD;
			if(i > 0) {
				A[1][*it] =(A[1][*it]*(A[1][i]+1))%MOD;
				if(A[1][*it] < 0) A[1][*it] +=MOD;}
			}
		}

	for(int i =0; i < N; i++) {
		long long ans =1;
		ALL_THE(G[i],it) {
			ans =(ans*(A[0][*it]+1))%MOD;
			if(ans < 0) ans +=MOD;}
		if(i > 0) {
			ans =(ans*(A[1][i]+1))%MOD;
			if(ans < 0) ans +=MOD;}
		cout << ans << ((i == N-1)?"\n":" ");}
	return 0;}

// look at my code
// my code is amazing