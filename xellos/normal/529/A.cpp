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
	string s;
	cin >> s;
	int N =s.length();
	int d =0;
	for(int i =0; i < N; i++) {
		if(s[i] == '(') d++;
		else d--;}

	set< pair<int,int> > S1;
	vector<int> Sv(N);
	int sA =0;
	for(int i =0; i < N; i++) {
		if(s[i] == '(') sA++;
		else sA--;
		Sv[i] =sA;
		S1.insert(make_pair(sA,i));}

	vector<int> Ppos(1,0);

	int ans =max(abs(d),-S1.begin()->ff); sA =0;
	if(d >= 0) ans =d+max(0,-S1.begin()->ff);
	for(int i =0; i < N-1; i++) {
		S1.erase(make_pair(Sv[i],i));
		sA =min(sA,Sv[i]);
		int c;
		if(d >= 0) c =d+max(0,max(-S1.begin()->ff+Sv[i],-sA-Sv[N-1]+Sv[i]));
		else c =max(0,max(-S1.begin()->ff+Sv[i],-sA-Sv[N-1]+Sv[i]));
		if(ans > c) {ans =c; Ppos.clear();}
		if(ans == c) Ppos.push_back(i+1);}

//	cout << ans << " " << d << "\n";

	N *=2;
	vector< vector<int> > V1(256);
	V1[0].push_back(N);
	for(int i =0; i < N; i++) V1[s[i%(N/2)]].push_back(i);
	int K =5;
	while(1<<(K-1) < N) K++;
	vector<int> isB(N+1+(1<<(K-1)),0);
	vector<int> SA(N+1,N); // order of suffixes
	vector<int> Bs(N+2,N+1); // bucket start
	Bs[0] =0;
	int Btot =-1, q =0; // buckets total
	for(int j =0; j < 256; j++) {
		if(!V1[j].empty()) Bs[++Btot] =q;
		for(uint i =0; i < V1[j].size(); i++) {
			SA[q] =V1[j][i];
			isB[V1[j][i]] =Btot;
			q++;}
		}

	vector< pair<int,int> > tmp(N+1);
	vector<int> Bs1(N+1,0); // bucket size (tmp)
	vector<int> nxtB(N+1,0), pos(N+1,0);
	for(int i =1; i < K; i++) {
		int q =1<<(i-1);
		for(int j =0; j <= Btot; j++) Bs1[j] =0; 									// t=1
		for(int j =0; j <= N; j++) nxtB[j] =isB[SA[j]+q];							// t=12
		for(int j =0; j <= Btot; j++) if(Bs[j+1]-Bs[j] > 1) for(int k =Bs[j]; k < Bs[j+1]; k++) 
			Bs1[nxtB[k]]++;									// t=9
		// transform Bs1 to bucket start (tmp)
		int s =0;
		for(int j =0; j <= Btot; j++) {												// t=1
			int s2 =Bs1[j]+s;
			Bs1[j] =s;
			s =s2;}
		for(int j =0; j <= Btot; j++) if(Bs[j+1]-Bs[j] > 1) for(int k =Bs[j]; k < Bs[j+1]; k++) 			// t=22
			pos[k] =Bs1[nxtB[k]]++;
		for(int j =0; j <= Btot; j++) if(Bs[j+1]-Bs[j] > 1) for(int k =Bs[j]; k < Bs[j+1]; k++) {			// t=14
			tmp[pos[k]].ff =SA[k];
			tmp[pos[k]].ss =j;}
		for(int j =0; j < s; j++) pos[j] =Bs[tmp[j].ss]++;							// t=14
		for(int j =0; j < s; j++) SA[pos[j]] =tmp[j].ff;							// t=7
		for(int j =0; j <= N; j++) nxtB[j] =isB[SA[j]+q];							// t=11
		// split buckets
		Btot =0;
		Bs[0] =0;
		for(int j =1; j <= N; j++) {
			if(isB[SA[j]] != isB[SA[j-1]] || nxtB[j] != nxtB[j-1]) pos[j] =++Btot;	// t=14
			else pos[j] =pos[j-1];
		}
//		clock_t ta =clock();
		int p =0;
		for(int j =1; j <= N; j++) {												// t=19
			if(p+1 == pos[j]) Bs[++p] =j;
			isB[SA[j]] =p;}
//		clock_t tb =clock();
//		cout << i << " " << (int)(tb-ta) << endl;
		}

	vector<int> invP(N+1);
	for(int i =0; i <= N; i++) invP[SA[i]] =i;
	int optR =Ppos[0], optP =invP[Ppos[0]];
	for(uint i =0; i < Ppos.size(); i++) if(optP > invP[Ppos[i]]) {
		optR =Ppos[i];
		optP =invP[Ppos[i]];}

//	cout << optR << "\n";
//	return 0;
	string s2;
	for(int i =0; i < -d; i++) s2 +="(";
	for(int i =optR; i < N/2; i++) s2 +=s[i];
	for(int i =0; i < optR; i++) s2 +=s[i];
	for(int i =0; i < d; i++) s2 +=")";
	cout << s2 << "\n";
	return 0;}

// look at my code
// my code is amazing