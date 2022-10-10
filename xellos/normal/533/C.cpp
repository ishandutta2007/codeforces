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
	int xp,yp,xv,yv;
	cin >> xp >> yp >> xv >> yv;
	int dp =xp+yp, dv =xv+yv;
	if(dv < dp) {cout << "Vasiliy\n"; return 0;}

	if(max(xv,yv) >= xp+yp) {cout << "Polycarp\n"; return 0;}

	int s =0;
	while(xv > 0 && yv > 0) {
		xv--;
		yv--;
		s++;
		if(s >= abs(xp-xv)+abs(yp-yv)) {cout << "Polycarp\n"; return 0;}
		}

	cout << "Vasiliy\n";
	return 0;}

// look at my code
// my code is amazing