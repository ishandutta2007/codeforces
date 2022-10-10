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
	int y1,y2,yw,xb,yb,r;
	cin >> y1 >> y2 >> yw >> xb >> yb >> r;
	if(xb == r) {cout << "-1\n"; return 0;}
	yw -=r;
	y2 =yw+(yw-y2);
	y1 =yw+(yw-y1);

	dbl ang10 =atan2(y2-yb,xb);
	dbl dst1 =sqrt(1LL*(y2-yb)*(y2-yb)+1LL*xb*xb);
	dbl ang11 =asin(r/dst1);

	dbl ang20 =atan2(y1-yb,xb);
	dbl dst2 =sqrt(1LL*(y1-yb)*(y1-yb)+1LL*xb*xb);
	dbl ang21 =asin(r/dst2);

	dbl angf =ang10+ang11+soclose;
	dbl y3 =yb+xb*tan(angf);
	if(y3 > y1-r-soclose) {
		cout << "-1\n";
		return 0;}
	// (yw-yb)/(xb-xw) == tan(angf)
	cout << fixed << setprecision(12) << xb-(yw-yb)/tan(angf) << "\n";
	return 0;}

// look at my code
// my code is amazing