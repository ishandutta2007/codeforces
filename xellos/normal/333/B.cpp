// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;
using namespace std::tr1;

int main() {
	int N,M,x,y;
	cin >> N >> M;
	vector< vector<int> > V((N-2)/2, vector<int>(8,1));
	int sx =N%2, sy =N%2;
	for(int i =0; i < M; i++) {
		cin >> x >> y;
		x--; y--;
		if(x-1 == N-3-(x-1)) sx--;
		if(y-1 == N-3-(y-1)) sy--;
		if(x > 0 && x < N-1 && x-1 != N-3-(x-1)) {
			x--;
			int a =0;
			if(x > N-3-x) a++;
			x =min(x,N-3-x);
			V[x][a] =V[x][5-a] =0;}
		if(y > 0 && y < N-1 && y-1 != N-3-(y-1)) {
			y--;
			int a =0;
			if(y > N-3-y) a++;
			y =min(y,N-3-y);
			V[y][2+a] =V[y][7-a] =0;}
		}
	
	int G[8][8];
	for(int i =0; i < 8; i++) for(int j =0; j < 8; j++) G[i][j] =0;
	G[0][3] =G[0][7] =G[0][5] =1;
	G[1][2] =G[1][4] =G[1][6] =1;
	G[2][5] =G[2][7] =1;
	G[3][4] =G[3][6] =1;
	G[4][7] =G[5][6] =1;
	for(int i =0; i < 8; i++) for(int j =i+1; j < 8; j++) G[j][i] =G[i][j];

	int s =(sx > 0 || sy > 0)?1:0;
	for(int i =0; i < (N-2)/2; i++) {
		int a =256;
		int t =0;
		for(int j =0; j < a; j++) {
			vector<int> W;
			int b =j;
			bool B =true;
			for(int k =0; k < 8; k++) {
				if(b%2 != 0) W.push_back(k);
				if(b%2 != 0 && V[i][k] == 0) {B =false; break;}
				b /=2;}
			for(int k =0; k < W.size(); k++) if(B)
				for(int l =k+1; l < W.size(); l++) 
					if(G[W[k]][W[l]] == 1) {B =false; break;}
			if(B) t =max(t,(int)W.size());}
		s +=t;}
	cout << s << "\n";	
//	x#x#x
//	#.x.#
//	#...#
//	x...#
//	x##xx
	return 0;}
        
// look at my code
// my code is amazing