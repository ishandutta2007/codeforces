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

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(3),C(N);
	for(int i =0; i < 3; i++) cin >> A[i];
	for(int i =0; i < N; i++) cin >> C[i];
	sort(begin(A),end(A));
	sort(begin(C),end(C));

	if(C[N-1] > A[0]+A[1]+A[2]) {
		cout << "-1\n";
		return 0;}

	int ansF =N;

	if(A[0]+A[1] >= A[2]) {
		int poc[7];
		memset(poc,0,sizeof(poc));
		for(int i =0; i < N; i++) {
			if(C[i] <= A[0]) poc[0]++;
			else if(C[i] <= A[1]) poc[1]++;
			else if(C[i] <= A[2]) poc[2]++;
			else if(C[i] <= A[0]+A[1]) poc[3]++;
			else if(C[i] <= A[0]+A[2]) poc[4]++;
			else if(C[i] <= A[1]+A[2]) poc[5]++;
			else poc[6]++;}
		int ans =poc[6];
		for(int i =0; i <= 2; i++) {
			for(int j =i; j >= 0; j--) {
				int x =min(poc[j],poc[5-i]);
				poc[j] -=x;
				poc[5-i] -=x;
				ans +=x;}
			ans +=poc[5-i];
			poc[5-i] =0;}
		int TA =-1, TB =max(poc[0],max(poc[1],poc[2]));
		while(TB-TA > 1) {
			int T =(TB+TA)/2;
			int t =max(0,poc[2]-T);
			if(poc[2]+poc[1] > 2*T || poc[2]+poc[1]+poc[0] > 3*T-t) TA =T;
			else TB =T;}
		ansF =ans+TB;}

	if(A[0]+A[1] <= A[2]) {
		int poc[7];
		memset(poc,0,sizeof(poc));
		for(int i =0; i < N; i++) {
			if(C[i] <= A[0]) poc[0]++;
			else if(C[i] <= A[1]) poc[1]++;
			else if(C[i] <= A[0]+A[1]) poc[2]++;
			else if(C[i] <= A[2]) poc[3]++;
			else if(C[i] <= A[0]+A[2]) poc[4]++;
			else if(C[i] <= A[1]+A[2]) poc[5]++;
			else poc[6]++;}
		int ans =poc[6];
		for(int i =0; i <= 1; i++) {
			for(int j =i; j >= 0; j--) {
				int x =min(poc[j],poc[5-i]);
				poc[j] -=x;
				poc[5-i] -=x;
				ans +=x;}
			ans +=poc[5-i];
			poc[5-i] =0;}

		int TA =-1, TB =N;
		while(TB-TA > 1) {
			int T =(TB+TA)/2;
			vector<int> poc2(4,0);
			for(int i =0; i < 4; i++) poc2[i] =poc[i];
			int t =T;
			for(int i =3; i >= 0; i--) {
				int x =min(poc2[i],t);
				poc2[i] -=x;
				t -=x;}
			if(t > 0) {TB =T; continue;}
			if(poc2[3] > 0) {TA =T; continue;}
			// T-krat pouzite C, T-krat mozem zadarmo A+B alebo A,B
			t =T;
			int x =min(poc2[2],t);
			t -=x;
			poc2[2] -=x;
			if(poc2[2] > 0) {TA =T; continue;}
			for(int i =0; i < 2; i++) {
				if(i > 0) poc2[i] +=poc2[i-1];
				poc2[i] =max(0,poc2[i]-t);}
			if(poc2[1] > 0) TA =T;
			else TB =T;}
		ansF =min(ansF,ans+TB);}

	cout << ansF << "\n";
	return 0;}

// look at my code
// my code is amazing