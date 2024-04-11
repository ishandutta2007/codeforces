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
#define OVER9000 1234567890123456789LL
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
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<long long> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	vector<long long> ans(N,0);
	int U =0,D =0;
	for(int i =1; i < N; i++) {
		ans[i] =ans[i-1];
		if(A[i] < A[i-1]) {
			if(U > 0) ans[i] =max(ans[i],max(ans[U-1]+A[U]-A[i],ans[U]+A[U+1]-A[i])); 
			else ans[i] =max(ans[i],A[U]-A[i]);}
		if(A[i] > A[i-1]) { 
			if(D > 0) ans[i] =max(ans[i],max(ans[D-1]+A[i]-A[D],ans[D]+A[i]-A[D+1])); 
			else ans[i] =max(ans[i],A[i]-A[D]);}
		if(A[i] > A[i-1]) U =i;
		if(A[i] < A[i-1]) D =i;}
	
	cout << ans[N-1] << "\n";
	return 0;}

// look at my code
// my code is amazing