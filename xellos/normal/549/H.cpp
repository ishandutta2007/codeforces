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
	dbl a,b,c,d;
	cin >> a >> b >> c >> d;
	dbl X_min =0, X_max =max(max(abs(a),abs(b)),max(abs(c),abs(d)));
	for(int i =0; i < 1000; i++) {
		dbl X =(X_min+X_max)/2;
		dbl a1 =a-X, a2 =a+X;
		dbl b1 =b-X, b2 =b+X;
		dbl c1 =c-X, c2 =c+X;
		dbl d1 =d-X, d2 =d+X;
		dbl mx1 =max(max(a1*d1,a1*d2),max(a2*d1,a2*d2));
		dbl mi1 =min(min(a1*d1,a1*d2),min(a2*d1,a2*d2));
		dbl mx2 =max(max(c1*b1,c1*b2),max(c2*b1,c2*b2));
		dbl mi2 =min(min(c1*b1,c1*b2),min(c2*b1,c2*b2));
		if(mi1-mx2 > 0 || mx1-mi2 < 0) X_min =X;
		else X_max =X;}
	cout << fixed << setprecision(10) << X_min << "\n";
	return 0;}

// look at my code
// my code is amazing