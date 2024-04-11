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

bool sent(int x, int y, int H, int W) {
	return (x >= 0 && y >= 0 && x < H && y < W);}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int H,W,Q;
	cin >> H >> W;
	vector<string> G(H);
	for(int i =0; i < H; i++) cin >> G[i];

	int dx[] ={1,-1,0,0};
	int dy[] ={0,0,1,-1};
	vector< vector<int> > deg(H,vector<int>(W,0));
	for(int i =0; i < H; i++) for(int j =0; j < W; j++) if(G[i][j] == '.')
		for(int k =0; k < 4; k++) if(sent(i+dx[k],j+dy[k],H,W))
			if(G[i+dx[k]][j+dy[k]] == '.') deg[i][j]++;
	vector< vector<int> > sum(H+1,vector<int>(W+1,0));
	for(int i =0; i < H; i++) for(int j =0; j < W; j++)
		sum[i+1][j+1] =deg[i][j]-sum[i][j]+sum[i][j+1]+sum[i+1][j];

	cin >> Q;
	for(int q =0; q < Q; q++) {
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--, x2--, y2--;
		int ans =sum[x2+1][y2+1]+sum[x1][y1]-sum[x1][y2+1]-sum[x2+1][y1];
		if(x1 > 0) for(int i =y1; i <= y2; i++) 
			if(G[x1][i] == '.' && G[x1-1][i] == '.') ans--;
		if(x2 < H-1) for(int i =y1; i <= y2; i++) 
			if(G[x2][i] == '.' && G[x2+1][i] == '.') ans--;
		if(y1 > 0) for(int i =x1; i <= x2; i++) 
			if(G[i][y1] == '.' && G[i][y1-1] == '.') ans--;
		if(y2 < W-1) for(int i =x1; i <= x2; i++) 
			if(G[i][y2] == '.' && G[i][y2+1] == '.') ans--;
		cout << ans/2 << "\n";}
	return 0;}

// look at my code
// my code is amazing