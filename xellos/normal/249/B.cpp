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
	int N,T;
	string S;
	cin >> N >> T >> S;
	T--;

	int lastH =-1, pH =0;
	for(int i =0; i < N; i++) if(S[i] == 'H') lastH =i, pH++;
	if(lastH > T) {cout << "-1\n"; return 0;}

	int tA =-1, tB =N+1;
	while(tB-tA > 1) {
		int t =(tB+tA)/2;
		// posledna pozicia, zakladny check
		int lastP =lastH, sh =0;
		for(int i =0; i < N; i++) if(S[i] == 'S') {
			sh++;
			if(sh+t <= pH) lastP =max(lastP,i);}
		if(sh+t < pH) {tA =t; continue;}
		int akt =t, lastHx =N+1, pHx =0, tt =0;
		bool ok =false;
		for(int i =0; i <= lastP; i++) {
			if(S[i] == 'S') {
				akt++;
				// vrat sa
				if(lastHx != N+1 && pHx <= akt) {
					if(tt+2*lastP-lastHx <= T) ok =true;
					tt +=2*(i-lastHx);
					akt -=pHx;
					pHx =0;
					lastHx =N+1;}
				}
			if(S[i] == 'H') {
				// mozem mu dat?
				if(akt > 0) akt--;
				else {
					if(lastHx == N+1) lastHx =i;
					pHx++;}
				}
			if(tt+2*lastP-min(i,lastHx) <= T) ok =true;}
		if(ok) tB =t;
		else tA =t;}

	cout << tB << "\n";
	return 0;}

// look at my code
// my code is amazing