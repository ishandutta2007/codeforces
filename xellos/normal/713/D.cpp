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
	int N,M;
	cin >> N >> M;
	vector< vector<int> > maxl[10][10];
	for(int i =0; i < 100; i++) maxl[i/10][i%10].resize(N,vector<int>(M,0));
	for(int i =0; i < N; i++) for(int j =0; j < M; j++) cin >> maxl[0][0][i][j];
	for(int i =N-2; i >= 0; i--) for(int j =M-2; j >= 0; j--) if(maxl[0][0][i][j]) 
		maxl[0][0][i][j] =min(maxl[0][0][i+1][j+1],min(maxl[0][0][i+1][j],maxl[0][0][i][j+1]))+1;
	for(int k =0; k < 10; k++) for(int l =0; l < 10; l++) if(k+l > 0)
		for(int i =0; i <= N-(1<<k); i++) for(int j =0; j <= M-(1<<l); j++) {
			if(k > 0) maxl[k][l][i][j] =max(maxl[k-1][l][i][j],maxl[k-1][l][i+(1<<(k-1))][j]);
			else maxl[k][l][i][j] =max(maxl[k][l-1][i][j],maxl[k][l-1][i][j+(1<<(l-1))]);}

	int Q;
	cin >> Q;
	for(int q =0; q < Q; q++) {
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--;
		
		int x1a =x1, y1a =y1;
		int dif =min(y2-y1,x2-x1)-1, v =0;
		if(x2-x1 <= y2-y1) {
			for(int k =9; k >= 0; k--) if(y1a+(1<<k) <= y2-dif) {
				v =max(v,maxl[0][k][x1a][y1a]);
				y1a +=1<<k;}
			x1a++;}
		else {
			for(int k =9; k >= 0; k--) if(x1a+(1<<k) <= x2-dif) {
				v =max(v,maxl[k][0][x1a][y1a]);
				x1a +=1<<k;}
			y1a++;}
		if(v > dif) {cout << dif+1 << "\n"; continue;}

		int ans =v;
		for(int k =0; k < 10; k++) if((dif>>k)&1) {
			int x1b =x1, y1b =y1, v0 =v;
			for(int i =9; i >= 0; i--) if(x1b+(1<<i) <= x1a+(1<<k)) {
				v =max(v,maxl[i][k][x1b][y1a]);
				v =max(v,maxl[i][k][x1a+(1<<k)-(1<<i)][y1a]);
				x1b +=1<<i;
				break;}
			for(int i =9; i >= 0; i--) if(y1b+(1<<i) <= y1a+(1<<k)) {
				v =max(v,maxl[k][i][x1a][y1b]);
				v =max(v,maxl[k][i][x1a][y1a+(1<<k)-(1<<i)]);
				y1b +=1<<i;
				break;}
			if(v > dif-(1<<k)) {
				for(int k2 =k-1; k2 >= 0; k2--) {
					v =v0;
					x1b =x1, y1b =y1;
					for(int i =9; i >= 0; i--) if(x1b+(1<<i) <= x1a+(1<<k2)) {
						v =max(v,maxl[i][k2][x1b][y1a]);
						v =max(v,maxl[i][k2][x1a+(1<<k2)-(1<<i)][y1a]);
						x1b +=1<<i;
						break;}
					for(int i =9; i >= 0; i--) if(y1b+(1<<i) <= y1a+(1<<k2)) {
						v =max(v,maxl[k2][i][x1a][y1b]);
						v =max(v,maxl[k2][i][x1a][y1a+(1<<k2)-(1<<i)]);
						y1b +=1<<i;
						break;}
					if(v <= dif-(1<<k2)) {
						v0 =v;
						ans =max(ans,v);
						x1a +=1<<k2, y1a +=1<<k2;
						dif -=1<<k2;}
					}
				ans =max(ans,dif);
				break;}
			x1a +=1<<k, y1a +=1<<k;
			dif -=1<<k;
			ans =v;}

		cout << ans << "\n";}
	return 0;}

// look at my code
// my code is amazing