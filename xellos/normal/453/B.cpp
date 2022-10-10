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
#define soclose 1e-10
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
	vector< pair<int,int> > S(N);
	for(int i =0; i < N; i++) {
		cin >> S[i].ff;
		S[i].ss =i;}
	sort(S.begin(),S.end());

	vector<int> P;
	for(int i =2; i <= 1000; i++) {
		bool b =true;
		for(int j =2; j < i; j++) if(i%j == 0) b =false;
		if(b) P.push_back(i);}

	vector< vector<int> > A(N+1,vector<int>(1<<10,1000000));
	vector< vector< pair<int,int> > > ako(N+1,vector< pair<int,int> >(1<<10,make_pair(-1,-1)));
	// i cisel vybranych, bitmask pouzitych prvocisel
	A[0][0] =0;
	for(int i =0; i < N; i++) for(int j =0; j < (1<<10)-1; j++) {
		for(int k =1; k <= 100; k++) {
			int x =j;
			bool b =true;
			for(int a =0; a < 10; a++) if(k%P[a] == 0) {
				if((x>>a)&1) {b =false; break;}
				else x |=(1<<a);}
			for(int a =10; a < 30; a++) if(k%P[a] == 0) {b =false; break;}
			if(b) {
				A[i+1][x] =min(A[i+1][x],A[i][j]+abs(k-S[i].ff));
				if(A[i+1][x] == A[i][j]+abs(k-S[i].ff)) ako[i+1][x] =make_pair(j,k);}
			}
		}

	int ans =1000000;
	vector<int> ansS(N);
	for(int i =0; i <= N; i++) for(int j =0; j < (1<<10); j++) {
		int akt =A[i][j];
		for(int k =i+1; k <= N; k++) akt +=abs(P[10+k-i-1]-S[k-1].ff);
		if(akt < ans) {
			ans =akt;
			for(int k =i+1; k <= N; k++) ansS[S[k-1].ss] =P[10+k-i-1];
			int a =j;
			for(int k =i; k > 0; k--) {
				ansS[S[k-1].ss] =ako[k][a].ss;
				a =ako[k][a].ff;}
			}
		}

//	cout << ans << "\n";
	for(int i =0; i < N; i++) cout << ansS[i] << ((i == N-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing