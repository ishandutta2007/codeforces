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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,x,y;
	cin >> N >> x >> y;
	double mind =1e15, maxd =0;
	vector< pair<long long,long long> > P(N);
	for(int i =0; i < N; i++) {
		long long x1,y1;
		cin >> x1 >> y1;
		x1 -=x;
		y1 -=y;
		mind =min(mind,1.0*x1*x1+y1*y1);
		maxd =max(maxd,1.0*x1*x1+y1*y1);
		P[i].ff =x1, P[i].ss =y1;}
	for(int i =0; i < N; i++) {
		// vyska == obsah*2/P[i]-P[i+1]
		double d =sqrt(pow(P[i].ff-P[(i+1)%N].ff,2)+pow(P[i].ss-P[(i+1)%N].ss,2));
		double a =sqrt(pow(P[i].ff,2)+pow(P[i].ss,2));
		double b =sqrt(pow(P[(i+1)%N].ff,2)+pow(P[(i+1)%N].ss,2));
		double S =P[i].ff*P[(i+1)%N].ss-P[i].ss*P[(i+1)%N].ff;
		if(d < soclose) continue;
		double h =abs(S/d);
		double ang =min(-a*a+d*d+b*b,-b*b+d*d+a*a);
		if(ang > -soclose) mind =min(mind,h*h);}
	cout << pi*(maxd-mind) << "\n";
	return 0;}

// look at my code
// my code is amazing