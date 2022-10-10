// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1034567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N,M,a,b,c,P;
	cin >> N >> M >> a >> b >> c >> P;
	a %=4, b %=2, c %=4;
	for(int i =0; i < P; i++) {
		int x,y;
		cin >> x >> y;
		x--, y--;
		int M0 =M, N0 =N;
		for(int j =0; j < a; j++) {
			int x2 =y, y2 =N-1-x;
			x =x2, y =y2;
			swap(M,N);}
		for(int j =0; j < b; j++) y =M-1-y;
		for(int j =0; j < 3*c; j++) {
			int x2 =y, y2 =N-1-x;
			x =x2, y =y2;
			swap(M,N);}
		cout << x+1 << " " << y+1 << "\n";
		M =M0, N =N0;}
	return 0;}

// look at my code
// my code is amazing