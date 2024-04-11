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

long long gcd(long long a, long long b) {
	if(a > b) swap(a,b);
	return (a == 0)?b:gcd(b%a,a);}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(N);
	int g =0, odd =0, L =0;
	for(int i =0; i < N; i++) {
		cin >> A[i];
		L +=A[i];
		if(A[i]%2 != 0) odd++;
		g =gcd(g,A[i]);}
	
	if(odd > 1) {
		cout << "0\n";
		for(int i =0; i < N; i++) for(int j =0; j < A[i]; j++) cout << (char)('a'+i);
		cout << "\n";
		return 0;}

	for(int k =g; k >= 1; k--) if(g%k == 0) { // k casti
		int odd2 =0;
		for(int i =0; i < N; i++) {
			int x =A[i]/k;
			if(A[i]%2 != 0) x--;
			if(x%2 != 0) odd2++;}
		if(odd2 > 1) continue;
		if(odd == 0 && odd2 == 0) cout << 2*k << "\n";
		else cout << k << "\n";
//		if(odd2 > 0) cout << ".\n";
		string s;
		for(int i =0; i < N; i++) {
			int x =A[i]/k;
			if(A[i]%2 != 0) x--;
			for(int j =0; j < x/2; j++) s +=('a'+i);}
		string s2 =s;
		for(int i =0; i < N; i++) {
			int x =A[i]/k;
			if(A[i]%2 != 0) x--;
			if(x%2 != 0) s +=('a'+i);}
		reverse(begin(s2),end(s2));
		s +=s2;
		if(odd > 0) 
			for(int i =0; i < N; i++) if(A[i]%2 != 0) s +=('a'+i);
		for(int i =0; i < k; i++) cout << s;
		cout << "\n";
		return 0;}
	return 0;}

// look at my code
// my code is amazing