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
#define OVER9000 1234567890
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

vector< vector<long long> > M(4,vector<long long>(4,0));

vector< vector<long long> > pw(long long e, long long mod) {
	if(e <= 0) {
		vector< vector<long long> > V(4,vector<long long>(4,0));
		for(int i =0; i < 4; i++) V[i][i] =1;
		return V;}
	vector< vector<long long> > V =pw(e/2,mod),W(4,vector<long long>(4,0));
	for(int i =0; i < 4; i++) for(int j =0; j < 4; j++) {
		for(int k =0; k < 4; k++) W[i][j] +=(V[i][k]*V[k][j])%mod;
		W[i][j] %=mod;
		if(W[i][j] < 0) W[i][j] +=mod;}
	if(e%2 == 0) return W;
	for(int i =0; i < 4; i++) for(int j =0; j < 4; j++) {
		V[i][j] =0;
		for(int k =0; k < 4; k++) V[i][j] +=(W[i][k]*M[k][j])%mod;
		V[i][j] %=mod;
		if(V[i][j] < 0) V[i][j] +=mod;}
	return V;}

int main() {
	cin.sync_with_stdio(0);
	long long N,sx,sy,dx,dy;
	long long T;
	cin >> N >> sx >> sy >> dx >> dy >> T;
	if(T == 0) {cout << sx << " " << sy << "\n"; return 0;}

	long long dv =dy-dx, dp =sy-sx;
	if(dv < 0) dv +=N;
	if(dp < 0) dp +=N;
	sx--, sy--;
	long long x1 =(sx+sy+2+dx+sx)%N, x2 =sx;
	long long C =(dv+1)%N, D =(2+dp)%N;
	if(C < 0) C +=N;
	if(D < 0) D +=N;
	if(x1 < 0) x1 +=N;

	vector<long long> V(4);
	V[0] =x1, V[1] =x2, V[2] =V[3] =1;
	M[3][3] =M[2][2] =M[2][3] =M[1][0] =1;
	M[0][0] =4, M[0][1] =N-1, M[0][2] =C, M[0][3] =D;

	M =pw(T-1,N);
	long long x =0;
	for(int i =0; i < 4; i++) x +=(M[0][i]*V[i])%N;
	x %=N;
	if(x < 0) x +=N;
	long long y =(x+dp+(T%N)*dv)%N;
	if(y < 0) y +=N;

	cout << x+1 << " " << y+1 << "\n";
	return 0;}

// look at my code
// my code is amazing