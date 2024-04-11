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

struct tri {
	long long lx,ly,op;
	tri(long long a, long long b, long long c) {lx =a, ly =b, op =c;}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,H,W;
	string S;
	cin >> N >> H >> W >> S;
	string dir ="UDLR";
	int dx[] ={1,-1,0,0};
	int dy[] ={0,0,1,-1};

	long long x =0, y =0, xmin =0, xmax =0, ymin =0, ymax =0;
	vector<tri> inc;
	for(int i =0; i < N; i++) {
		for(int k =0; k < 4; k++) if(S[i] == dir[k]) {
			x +=dx[k];
			y +=dy[k];}
		if(x < xmin || y < ymin || y > ymax || x > xmax) {
			xmin =min(x,xmin);
			ymin =min(y,ymin);
			xmax =max(x,xmax);
			ymax =max(y,ymax);
			inc.push_back(tri(xmax-xmin,ymax-ymin,i+1));}
		}
	long long X =x, Y =y;

	if(xmax-xmin < H && ymax-ymin < W && X == 0 && Y == 0) {
		cout << "-1\n";
		return 0;}

	vector<tri> inc2;
	for(int i =0; i < N; i++) {
		for(int k =0; k < 4; k++) if(S[i] == dir[k]) {
			x +=dx[k];
			y +=dy[k];}
		if(x < xmin || y < ymin || y > ymax || x > xmax) {
			xmin =min(x,xmin);
			ymin =min(y,ymin);
			xmax =max(x,xmax);
			ymax =max(y,ymax);
			inc.push_back(tri(xmax-xmin,ymax-ymin,N+i+1));
			inc2.push_back(tri(x,y,N+i+1));}
		}

	if(!inc2.empty()) while((int)inc.size() <= H+W+tisic) {
		ALL_THE(inc2,it) {
			it->lx +=X;
			it->ly +=Y;
			it->op +=N;
			xmin =min(it->lx,xmin);
			ymin =min(it->ly,ymin);
			xmax =max(it->lx,xmax);
			ymax =max(it->ly,ymax);
			inc.push_back(tri(xmax-xmin,ymax-ymin,it->op));
			if(xmax-xmin >= H || ymax-ymin >= W) break;
			if((int)inc.size() > H+W+tisic) break;}
		}

	x =0, y =0;
	long long ans =0, Lx =H, Ly =W, mod =1000000007;
	ALL_THE(inc,it) {
		if(it->lx >= H || it->ly >= W) {
			ans +=(it->op%mod)*(Lx*Ly%mod);
			ans %=mod;
			break;}
		bool isX =true;
		if(x == it->lx) isX =false;
		x =it->lx;
		y =it->ly;
		if(isX) {
			ans +=it->op%mod*Ly;
			ans %=mod;
			Lx--;}
		else {
			ans +=it->op%mod*Lx;
			ans %=mod;
			Ly--;}
		}

	if(ans < 0) ans +=mod;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing