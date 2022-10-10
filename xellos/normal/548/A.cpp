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
	string S;
	int K;
	cin >> S >> K;
	int N =S.length();
	if(N%K != 0) {cout << "NO\n"; return 0;}
	K =N/K;
	for(int i =0; i < N/K; i++) for(int k =0; k < K; k++)
		if(S[K*i+k] != S[K*i+K-1-k]) {
			cout << "NO\n"; 
			return 0;}
	cout << "YES\n";
	return 0;}

// look at my code
// my code is amazing