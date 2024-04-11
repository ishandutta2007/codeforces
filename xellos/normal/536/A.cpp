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
	long long A,B;
	int Q;
	cin >> A >> B >> Q;
	for(int q =0; q < Q; q++) {
		int L,P,M;
		cin >> L >> P >> M;
		if(L*B+A-B > P) {cout << "-1\n"; continue;}
		long long Ra =L, Rb =L+2000000;
		while(Rb-Ra > 1) {
			long long R =(Ra+Rb)/2;
			if(B*R+A-B > P || A*(R-L+1)+B*((R-1)*R-1LL*(L-1)*(L-2))/2 > 1LL*P*M)
				Rb =R;
			else Ra =R;}
		cout << Ra << "\n";
		}
	return 0;}

// look at my code
// my code is amazing