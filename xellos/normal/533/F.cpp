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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	string S,T;
	cin >> N >> M >> S >> T;
	vector<int> match(N,0);

	long long p[2] ={1023,999983};
	long long mod[2] ={1000000007,1000000009};

	vector<int> lOcc(26,-1);
	for(int i =0; i < M; i++) lOcc[T[i]-'a'] =i;

	for(int k =0; k < 2; k++) {
		vector<long long> pPw(N+1,1);
		for(int i =0; i < N; i++) {
			pPw[i+1] =(pPw[i]*p[k])%mod[k];
			if(pPw[i+1] < 0) pPw[i+1] +=mod[k];}

		// hashe S
		vector<long long> Hs(N+1,0);
		for(int i =0; i < N; i++) {
			Hs[i+1] =(Hs[i]*p[k]+S[i]-'a'+1)%mod[k];
			if(Hs[i+1] < 0) Hs[i+1] +=mod[k];}

		// hash kazdeho pismena v T
		vector<long long> Hlt(26,0);
		for(int i =0; i < M; i++) {
			Hlt[T[i]-'a'] =(Hlt[T[i]-'a']+pPw[M-1-i])%mod[k];
			if(Hlt[T[i]-'a'] < 0) Hlt[T[i]-'a'] +=mod[k];}

		for(int i =0; i <= N-M; i++) {

			// najdi doparovanie
			vector<int> fits(26,-1);
			bool ok =true;
			for(int j =0; j < 26; j++) if(lOcc[j] != -1) {
				if(fits[j] != -1 && fits[j] != S[i+lOcc[j]]-'a') ok =false;
				fits[j] =S[i+lOcc[j]]-'a';
				if(fits[S[i+lOcc[j]]-'a'] != -1 && fits[S[i+lOcc[j]]-'a'] != j) ok =false;
				fits[S[i+lOcc[j]]-'a'] =j;}

			vector<int> fail(26,0);
			for(int j =0; j < 26; j++) if(fits[j] != -1) fail[fits[j]]++;
			for(int j =0; j < 26; j++) if(fail[j] > 1) ok =false;

			if(!ok) continue;

			long long Ht =0;
			for(int j =0; j < 26; j++) {
				Ht =(Ht+Hlt[j]*(fits[j]+1))%mod[k];
				if(Ht < 0) Ht +=mod[k];}

			long long Hss =(Hs[i+M]-pPw[M]*Hs[i])%mod[k];
//			Hs[i]*pPw[M]+Hss == Hs[i+M]
			if((Hss-Ht)%mod[k] == 0) match[i]++;}
		}

	int pm =0;
	for(int i =0; i < N; i++) if(match[i] == 2) pm++;
	cout << pm << "\n";
	for(int i =0; i < N; i++) if(match[i] == 2) {
		cout << i+1;
		pm--;
		cout << ((pm == 0)?"\n":" ");}
	return 0;}

// look at my code
// my code is amazing