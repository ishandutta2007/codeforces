// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
#define sent(x,y) (x >= 0 && y >= 0 && x < R && y < C)
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N,Ox =0,Oy =0;
	cin >> N;
	long long mod =1000000007;
	vector<int> F[3];
	for(int i =0; i < 3; i++) {
		string s;
		cin >> s;
		for(int j =0; j < N; j++) {
			if(s[j] == 'O') Ox =i, Oy =j;
			if(s[j] == '.') F[i].push_back(0);
			else F[i].push_back(1);}}
	
	long long ans =0;
	int dx[] ={1,-1,0,0};
	int dy[] ={0,0,1,-1};
	int d[4];
	for(d[0] =0; d[0] < 4; d[0]++) for(d[1] =0; d[1] < 4; d[1]++)
	for(d[2] =0; d[2] < 4; d[2]++) for(d[3] =0; d[3] < 4; d[3]++) {
		int A[5][5];
		for(int i =0; i < 25; i++) A[i/5][i%5] =0;
		bool ok0 =true;
		for(int i =0; i < 4; i++) {
			bool b =true;
			if(Ox+dx[i] > 2 || Ox+dx[i] < 0 || Oy+dy[i] < 0 || Oy+dy[i] >= N) b =false;
			if(!b || F[Ox+dx[i]][Oy+dy[i]] == 1) {
				if(d[i] > 0) ok0 =false;
				continue;}
			A[2+dx[i]][2+dy[i]]++;
			A[2+dx[i]+dx[d[i]]][2+dy[i]+dy[d[i]]]++;}
		if(!ok0) continue;
		bool ok =false;
		for(int i =0; i < 4; i++) if(dx[i]+dx[d[i]] == 0 || dy[i]+dy[d[i]] == 0) ok =true;
		int B[5][5];
		for(int i =0; i < 25; i++) B[i/5][i%5] =0;
		for(int y =max(0,2-Oy); y < min(5,2-Oy+N); y++) for(int x =2-Ox; x < 5-Ox; x++) {
			B[x][y] =1;
			if(F[x-2+Ox][y-2+Oy] == 1) A[x][y]++;}
		for(int i =0; i < 25; i++) if(A[i/5][i%5] > 1) ok =false;
		for(int i =0; i < 25; i++) if(B[i/5][i%5] == 0 && A[i/5][i%5] > 0) ok =false;
		if(!ok) continue;
		
		vector<int> Fn[3];
		for(int i =0; i < 3; i++) Fn[i] =F[i];
		for(int i =0; i < 25; i++) if(A[i/5][i%5] > 0) Fn[i/5-2+Ox][i%5-2+Oy] =1;
		
		vector< vector<long long> > C(N+1, vector<long long>(8,0));
		C[0][Fn[0][0]+2*Fn[1][0]+4*Fn[2][0]] =1;
		for(int i =0; i < N-1; i++) for(int j =0; j < 8; j++) if(C[i][j] > 0) {
			// ako vyzera tento a dalsi stplec?
			int a[3] ={j%2,(j/2)%2,j/4};
			int k =Fn[0][i+1]+2*Fn[1][i+1]+4*Fn[2][i+1];
			if(a[1] == 0) {
				if(a[0] == 0 && a[2] == 1) C[i+1][k] =(C[i+1][k]+C[i][j])%mod;
				if(a[0] == 1 && a[2] == 0) C[i+1][k] =(C[i+1][k]+C[i][j])%mod;
				if(a[0]+a[2] == 0) {
					if((k&1) == 0) C[i+1][k+1] =(C[i+1][k+1]+C[i][j])%mod;
					if((k&4) == 0) C[i+1][k+4] =(C[i+1][k+4]+C[i][j])%mod;}}
			if(((7-j)&k) == 0) C[i+1][(7-j)|k] =(C[i+1][(7-j)|k]+C[i][j])%mod;}
		ans =(ans+C[N-1][7]+C[N-1][4]+C[N-1][1])%mod;}
	cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing