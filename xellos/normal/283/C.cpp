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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,Q,T;
	cin >> N >> Q >> T;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];

	vector<int> to(N,-1),from(N,-1);
	for(int i =0; i < Q; i++) {
		int b,c;
		cin >> b >> c;
		from[--b] =--c;
		to[c] =b;}

	int n =0;
	for(int i =0; i < N; i++) if(from[i] == -1) {
		int akt =to[i], d =1;
		while(akt != -1) {
			T =max(-1LL,T-1LL*d*A[akt]);
			d++;
			akt =to[akt];}
		}
	for(int i =0; i < N; i++) if(to[i] == -1) {
		int akt =from[i];
		n++;
		while(akt != -1) {
			A[akt] =min(T+1,A[akt]+A[to[akt]]);
			n++;
			akt =from[akt];}
		}

	if(n < N || T < 0) {cout << "0\n"; return 0;}

	long long mod =1000000007;
	vector<long long> pos(T+1,0);
	pos[0] =1;
	for(int i =0; i < N; i++) for(int j =0; j < min(T+1,A[i]); j++) {
		long long s =0;
		for(int k =j; k <= T; k +=A[i]) {
			s =(s+pos[k])%mod;
			pos[k] =s;}
		}

	cout << pos[T] << "\n";
	return 0;}

// look at my code
// my code is amazing