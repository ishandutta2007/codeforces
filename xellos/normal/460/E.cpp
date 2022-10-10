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
#define soclose 1e-7
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittledoge
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,R;
	cin >> N >> R;

	vector< pair<int,int> > P;
	for(int i =-R; i <= R; i++) for(int j =-R; j <= R; j++) if(i*i+j*j <= R*R) {
		if((i+1)*(i+1)+j*j <= R*R && (i-1)*(i-1)+j*j <= R*R) continue;
		if((j+1)*(j+1)+i*i <= R*R && (j-1)*(j-1)+i*i <= R*R) continue;
		P.push_back(make_pair(i,j));}

	vector< vector<int> > A(2*R*N+1,vector<int>(2*R*N+1,-OVER9000)); // sum x, sum y
	vector< vector<int> > ako[N+1];
	ako[0].resize(2*R*N+1,vector<int>(2*R*N+1,0));
	A[R*N][R*N] =0;
	for(int i =0; i < N; i++) {
		vector< vector<int> > An =A;
		ako[i+1].resize(2*R*N+1,vector<int>(2*R*N+1,0));
		for(int x =-R*N; x <= R*N; x++) for(int y =-R*N; y <= R*N; y++) if(An[x+R*N][y+R*N] != -OVER9000)
			ALL_THE(P,it) {
				int d2 =An[x+R*N][y+R*N]+(N-1)*((it->ff)*(it->ff)+(it->ss)*(it->ss))-2*x*(it->ff)-2*y*(it->ss);
				A[x+it->ff+R*N][y+it->ss+R*N] =max(A[x+it->ff+R*N][y+it->ss+R*N],d2);
				if(A[x+it->ff+R*N][y+it->ss+R*N] == d2) ako[i+1][x+it->ff+R*N][y+it->ss+R*N] =(it-P.begin());}
		}

	int ans =-1;
	pair<int,int> p =make_pair(0,0);
	for(int i =0; i <= 2*R*N; i++) for(int j =0; j <= 2*R*N; j++) {
		ans =max(ans,A[i][j]);
		if(ans == A[i][j]) p =make_pair(i,j);}
	cout << ans << "\n";
	for(int i =0; i < N; i++) {
		pair<int,int> pp =P[ako[N-i][p.ff][p.ss]];
		cout << pp.ff << " " << pp.ss << "\n";
		p.ff -=pp.ff;
		p.ss -=pp.ss;}
	return 0;}

// look at my code
// my code is amazing