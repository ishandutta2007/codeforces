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
#define soclose 1e-10
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
	int K,N;
	cin >> N >> K;
	int P[2] ={0,0};
	for(int i =0; i < N; i++) {
		int a;
		cin >> a;
		P[(int)(a%2 != 0)]++;}
	if(N == K) {
		if(P[1]%2 == 0) cout << "Daenerys\n";
		else cout << "Stannis\n";
		return 0;}

	if(P[0] >= N-K && P[1] >= N-K) {
		if((N-K)%2 == 0) cout << "Daenerys\n";
		else cout << "Stannis\n";
		return 0;}

	int pE =(N-K)/2,pO =N-K-(N-K)/2;
	if(pE >= P[1]) {cout << "Daenerys\n"; return 0;}
	if(K%2 == 0 && pE >= P[0]) {cout << "Daenerys\n"; return 0;}
	if(K%2 != 0 && pO >= P[0]) {cout << "Stannis\n"; return 0;}
	// pE < P[0],P[1] < N-K
	// pO <= P[1], < P[0] < N-K
	if(K%2 == 0) {
		// same 0: win 2heho, same 1: win 2heho
		if((N-K)%2 == 0) cout << "Daenerys\n";
		else cout << "Stannis\n";
		return 0;}
	if((N-K)%2 == 0) {
		// druhy nici 1tky, prehra ak nemoze vybrat 0 (ak nemoze vybrat 1 tak vyhra)
		cout << "Daenerys\n";
		return 0;}
	// prvy prehra ak musi vybrat 0 (ak musi vybrat 1 tak vyhra)
	cout << "Stannis\n";
	return 0;}

// look at my code
// my code is amazing