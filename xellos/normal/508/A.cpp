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
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M,K;
	cin >> N >> M >> K;
	vector< vector<int> > V(N,vector<int>(M,0));
	for(int i =0; i < K; i++) {
		int x,y;
		cin >> x >> y;
		V[--x][--y] =1;
		if(x > 0 && y > 0)
			if(V[x-1][y-1] && V[x-1][y] && V[x][y-1]) {cout << i+1 << "\n"; return 0;}
		if(x < N-1 && y < M-1)
			if(V[x+1][y+1] && V[x+1][y] && V[x][y+1]) {cout << i+1 << "\n"; return 0;}
		if(x > 0 && y < M-1)
			if(V[x-1][y+1] && V[x-1][y] && V[x][y+1]) {cout << i+1 << "\n"; return 0;}
		if(x < N-1 && y > 0)
			if(V[x+1][y-1] && V[x+1][y] && V[x][y-1]) {cout << i+1 << "\n"; return 0;}
		}
	cout << "0\n";
	return 0;}

// look at my code
// my code is amazing