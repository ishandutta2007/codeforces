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
// mylittlepony
using namespace std;

int sig(int x) {if(x == 0) return 0; if(x > 0) return 1; return -1;}

int main() {
	int ar,N;
	cin >> ar >> N;
	N++;
	
	int dx[] ={0,-1,0,1};
	int dy[] ={1,0,-1,0};
	char c[] ={'U','L','D','R'};
	vector<int> go(4*N*N+1,-1);
	// pozicia (x,y), smer z: vrchol 4Nx+4y+z; 4NN je mimo
	
	vector< vector<int> > dir(N, vector<int> (N,-1));
	for(int i =0; i < ar; i++) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		int e =0;
		for(int j =0; j < 4; j++) if(sig(c-a) == dx[j] && sig(d-b) == dy[j]) e =j;
		if(a > c) swap(a,c);
		if(b > d) swap(b,d);
		for(int j =a; j <= c; j++) for(int k =b; k <= d; k++) dir[j][k] =e;}
	
	for(int i =0; i < 4*N*N; i++) {
		int z =i%4, y =(i/4)%N, x =i/4/N;
		if(dir[x][y] != z && dir[x][y] != -1) continue;
		if(x+dx[z] < 0 || x+dx[z] >= N || y+dy[z] < 0 || y+dy[z] >= N) {
			go[i] =4*N*N;
			continue;}
		x +=dx[z], y +=dy[z];
		if(dir[x][y] != -1) z =dir[x][y];
		go[i] =4*N*x+4*y+z;}
	
	int Q;
	cin >> Q;
	vector<int> dep(4*N*N+1,-1);
	for(int q =0; q < Q; q++) {
		int x,y;
		string s;
		long long t;
		cin >> x >> y >> s >> t;
		int z =0;
		for(int i =0; i < 4; i++) if(c[i] == s[0]) z =i;
		if(dir[x][y] != -1) z =dir[x][y];
		int pos =4*N*x+4*y+z;
		
		dep[pos] =0;
		stack<int> S;
		S.push(pos);
		bool cyc =false;
		while(true) {
			int a =go[S.top()];
			if(a == 4*N*N) break;
			if(t == dep[S.top()]) break;
			if(dep[a] == -1) {
				dep[a] =dep[S.top()]+1;
				S.push(a);
				if(dep[a] == t) break;
				continue;}
			 t =(t-dep[a])%(dep[S.top()]-dep[a]+1)+dep[a];
			 cyc =true;
			 break;}
		if(!cyc) cout << S.top()/4/N << " " << (S.top()/4)%N;
		while(!S.empty()) {
			if(cyc && dep[S.top()] == t) {
				cout << S.top()/4/N << " " << (S.top()/4)%N;
				cyc =false;}
			dep[S.top()] =-1;
			S.pop();}
		cout << "\n";}
		
    return 0;}
        
// look at my code
// my code is amazing