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
	int N,M;
	cin >> N >> M;
	vector<string> V(N);
	for(int i =0; i < N; i++) cin >> V[i];
	int Sx =-1,Sy =-1;
	for(int i =0; i < N; i++) if(Sx == -1) for(int j =0; j < M; j++) if(V[i][j] == 'X') {
		Sx =i;
		Sy =j;
		break;}

	int ans =-1;
	for(int k =0; k < 2; k++) {
		vector<string> W(M);
		for(int i =0; i < M; i++) for(int j =0; j < N; j++) W[i] +=V[j][i];
		swap(N,M);
		swap(Sx,Sy);
		V =W;

		int Y =1;
		for(int i =Sy+1; i < M; i++) {
			if(V[Sx][i] != 'X') break;
			Y =i-Sy+1;}
		int x =Sx;
		for(int i =Sx+1; i < N; i++) {
			if(V[i][Sy] != 'X') break;
			x =i;}
		int X =1;
		if(Sy+Y < M) for(int i =x; i >= Sx; i--) {
			if(V[i][Sy+Y] != 'X') break;
			X =x-i+1;}

		vector<string> pt(N);
		for(int i =0; i < N; i++) for(int j =0; j < M; j++) pt[i] +='.';
		for(int i =0; i < X; i++) for(int j =0; j < Y; j++) pt[Sx+i][Sy+j] ='X';
		int xA =Sx, yA =Sy;
		while(true) {
			if(xA+X < N && V[xA+X][yA] == 'X' && yA+Y <= M) {
				for(int i =0; i < Y; i++) pt[xA+X][yA+i] ='X';
				xA++;
				continue;}
			if(yA+Y < M && V[xA][yA+Y] == 'X' && xA+X <= N) {
				for(int i =0; i < X; i++) pt[xA+i][yA+Y] ='X';
				yA++;
				continue;}
			break;}
//		for(int i =0; i < N; i++) cout << V[i] << "\n";

		if(pt != V) continue;
		if(ans == -1) ans =X*Y;
		else ans =min(ans,X*Y);}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing