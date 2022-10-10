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
	long long A,CF,CM,M;
	cin >> N >> A >> CF >> CM >> M;
	vector< pair<long long,int> > H(N);
	for(int i =0; i < N; i++) {
		cin >> H[i].ff;
		H[i].ss =i;}
	sort(begin(H),end(H));

	long long s =0, p =0; // p*min-s <= M
	// len 0..p-1
	while(p < N && H[p].ff*p-s <= M) {
		s +=H[p].ff;
		p++;}

	long long ans =(p == 0)?0:(min(A,(M+s)/p)*CM);
	int x =N;
	long long ml =(p == 0)?0:((M+s)/p);
	for(int i =N-1; i >= 0; i--) {
		// i..N-1 na max
		while(p > i) {
			s -=H[p-1].ff;
			p--;}
		M -=A-H[i].ff;
		if(M < 0) break;
		while(p < i && H[p].ff*p-s <= M) {
			s +=H[p].ff;
			p++;}
		while(p > 0 && H[p-1].ff*p-s > M) {
			s -=H[p-1].ff;
			p--;}
		if(p > 0) {
			ans =max(ans,(N-i)*CF+min(A,(M+s)/p)*CM);
			if(ans == (N-i)*CF+min(A,(M+s)/p)*CM) x =i, ml =(M+s)/p;}
		else {
			ans =max(ans,(N-i)*CF+A*CM);
			if(ans == (N-i)*CF+A*CM) x =i, ml =A;}
		}

	cout << ans << "\n";
	vector<long long> sk(N);
	for(int i =x; i < N; i++) sk[H[i].ss] =A;
	ml =min(ml,A);
	for(int i =0; i < x; i++) sk[H[i].ss] =max(H[i].ff,ml);
	for(int i =0; i < N; i++) cout << sk[i] << ((i == N-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing