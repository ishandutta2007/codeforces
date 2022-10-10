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
#define ALL_THE(CAKE,LIE) for(vector<int>::iterator LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define ALL_THE2(CAKE,LIE) for(vector< pair<int,int> >::iterator LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
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
#include <time.h>
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string s;
	int K;
	cin >> s >> K;
	int N =s.length();

	vector< vector<int> > V1(256);
	V1[0].push_back(N);
	for(int i =0; i < N; i++) V1[s[i]].push_back(i);
	vector< pair<int,int> > V;
	for(int i =0; i < 256; i++) ALL_THE(V1[i],it) V.push_back(make_pair(i,*it));
	vector<int> isB[20];
	for(int i =0; i < 20; i++) isB[i].resize(N+1+(1<<18),0);
	vector<int> SA(N+1,N); // order of suffixes
	vector<int> Bs(N+2,N+1); // bucket start
	Bs[0] =0;
	int Btot =0; // buckets total
	for(int i =1; i <= N; i++) {
		SA[i] =V[i].ss;
		if(V[i].ff != V[i-1].ff) Bs[++Btot] =i;
		isB[0][SA[i]] =Btot;}

	vector< pair<int,int> > tmp(N+1);
	vector<int> Bs1(N+1,0); // bucket size (tmp)
	vector<int> nxtB(N+1,0), pos(N+1,0);
	for(int i =1; i < 20; i++) {
//		clock_t ta =clock();
		for(int j =0; j <= Btot; j++) Bs1[j] =0;
		for(int j =0; j <= N; j++) nxtB[j] =isB[i-1][SA[j]+(1<<(i-1))];
		for(int j =0; j <= N; j++) Bs1[nxtB[j]]++;
		// transform Bs1 to bucket start (tmp)
		int s =0;
		for(int j =0; j <= Btot; j++) {
			int s2 =Bs1[j]+s;
			Bs1[j] =s;
			s =s2;}
		for(int j =0; j <= Btot; j++) for(int k =Bs[j]; k < Bs[j+1]; k++) 
			pos[k] =Bs1[nxtB[k]]++;
		for(int j =0; j <= Btot; j++) for(int k =Bs[j]; k < Bs[j+1]; k++) {
			tmp[pos[k]].ff =SA[k];
			tmp[pos[k]].ss =j;}
		for(int j =0; j <= N; j++) pos[j] =Bs[tmp[j].ss]++;
		for(int j =0; j <= N; j++) SA[pos[j]] =tmp[j].ff;
		for(int j =0; j <= N; j++) nxtB[j] =isB[i-1][SA[j]+(1<<(i-1))];
		// split buckets
		Btot =0;
		Bs[0] =0;
		for(int j =1; j <= N; j++) {
			if(isB[i-1][SA[j]] != isB[i-1][SA[j-1]] || nxtB[j] != nxtB[j-1]) pos[j] =++Btot;
			else pos[j] =Btot;}
		for(int j =N; j > 0; j--) {
			isB[i][SA[j]] =pos[j];
			Bs[pos[j]] =j;}
//		clock_t tb =clock();
//		cout << i << " " << (int)(tb-ta) << endl;
		}

	vector<int> LCP(N+1,0);
	int L =0;
	for(int i =0; i < N; i++) {
		int k =SA[isB[19][i]-1];
		while(i+L < N && k+L < N && s[i+L] == s[k+L]) L++;
		LCP[isB[19][i]] =L;
		if(L > 0) L--;}

	for(int i =1; i <= N; i++) for(int j =LCP[i]+1; j <= N-SA[i]; j++) {
		int a =i;
		while(a < N && LCP[a+1] >= j) a++;
		if(a-i+1 < K) {K -=a-i+1; continue;}
		cout << s.substr(SA[i],j) << "\n";
		return 0;}

	cout << "No such line.\n";
	return 0;}

// look at my code
// my code is amazing