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
	int N;
	long long A, S =0;
	cin >> N >> A;
	vector<long long> D(N);
	for(int i =0; i < N; i++) {
		cin >> D[i];
		S +=D[i];}

	for(int i =0; i < N; i++) {
//		x: sucet zvysku S-D[i] >= A-x >= N-1
		long long xMin =max(1LL,A-S+D[i]), xMax =min(D[i],A-N+1);
		cout << D[i]-max(0LL,xMax-xMin+1) << "\n";}

	return 0;}

// look at my code
// my code is amazing