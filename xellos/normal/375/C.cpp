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

int main() {
	cin.sync_with_stdio(0);
	int N,M,T =0;
	cin >> N >> M;
	vector<string> V(N);
	map< pair<int,int>, int> tr;
	for(int i =0; i < N; i++) {
		cin >> V[i];
		for(int j =0; j < M; j++)
			if(V[i][j] >= '0' && V[i][j] <= '9') {
				T++;
				tr[make_pair(i,j)] =V[i][j]-'1';}
		}
	vector<int> val(T);
	for(int i =0; i < T; i++) cin >> val[i];

	int O =T, S =0;
	map< pair<int,int>, int> B;
	for(int i =0; i < N; i++)
		for(int j =0; j < M; j++) {
			if(V[i][j] == 'B') B[make_pair(i,j)] =O++;
			if(V[i][j] == 'S') S =i*M+j;}

	int ans =0;
	for(int t =0; t < 2; t++) {

	vector< vector<int> > D[3];
	for(int i =0; i < 3; i++) D[i].resize(N*M,vector<int>(1<<O,OVER9000));
	queue< pair<int,int> > q;
	int x =0;
	for(int i =S%M+1; i < M; i++) {
		if(V[S/M][i] == 'B') x |=1<<B[make_pair(S/M,i)];
		if(V[S/M][i] >= '0' && V[S/M][i] <= '9') x |=1<<tr[make_pair(S/M,i)];}
	q.push(make_pair(3*S,x));
	vector<int> W(1<<O,OVER9000);
	D[0][S][x] =0;
	int dx[] ={0,0,1,-1};
	int dy[] ={1,-1,0,0};

	while(!q.empty()) {
		int x =(q.front().ff/3)/M, y =(q.front().ff/3)%M, z =q.front().ff%3;
		for(int k =0; k < 4; k++) if(dx[k]+x >= 0 && dy[k]+y >= 0 && dx[k]+x < N && dy[k]+y < M) {
			if(V[dx[k]+x][dy[k]+y] != '.' && V[dx[k]+x][dy[k]+y] != 'S') continue;
			int b =q.front().ss, u =z;
			if(dx[k] != 0) {
				for(int j =dy[k]+y; j < M; j++) {
					if(V[dx[k]+x][j] == 'B') b ^=1<<B[make_pair(dx[k]+x,j)];
					if(V[dx[k]+x][j] >= '0' && V[dx[k]+x][j] <= '9') b ^=1<<tr[make_pair(dx[k]+x,j)];}
				if(dx[k] == 1) u =1;
				else u =2;
				if(z == 0 && u != t+1) continue;
				if(u != z) for(int j =dy[k]+y; j < M; j++) {
					if(V[x][j] == 'B') b ^=1<<B[make_pair(x,j)];
					if(V[x][j] >= '0' && V[x][j] <= '9') b ^=1<<tr[make_pair(x,j)];}
				}
			if(1+D[z][x*M+y][q.front().ss] < D[u][(dx[k]+x)*M+dy[k]+y][b]) {
				D[u][(dx[k]+x)*M+dy[k]+y][b] =1+D[z][x*M+y][q.front().ss];
				if((dx[k]+x)*M+dy[k]+y == S && u == t+1) W[b] =D[u][S][b];
				q.push(make_pair(3*((dx[k]+x)*M+dy[k]+y)+u,b));}
			}
		q.pop();}

	for(int i =0; i < (1<<T); i++) {
		int v =0;
		for(int j =0; j < T; j++) if((i>>j)&1) v +=val[j];
		ans =max(ans,v-W[i]);}
	}

	for(int t =0; t < 2; t++) {

	vector< vector<int> > D[3];
	for(int i =0; i < 3; i++) D[i].resize(N*M,vector<int>(1<<O,OVER9000));
	queue< pair<int,int> > q;
	int x =0;
	for(int i =S%M+1; i < M; i++) {
		if(V[S/M][i] == 'B') x |=1<<B[make_pair(S/M,i)];
		if(V[S/M][i] >= '0' && V[S/M][i] <= '9') x |=1<<tr[make_pair(S/M,i)];}
	x =0;
	q.push(make_pair(3*S,x));
	vector<int> W(1<<O,OVER9000);
	D[0][S][0] =x;
	int dx[] ={0,0,1,-1};
	int dy[] ={1,-1,0,0};

	while(!q.empty()) {
		int x =(q.front().ff/3)/M, y =(q.front().ff/3)%M, z =q.front().ff%3;
		for(int k =0; k < 4; k++) if(dx[k]+x >= 0 && dy[k]+y >= 0 && dx[k]+x < N && dy[k]+y < M) {
			if(V[dx[k]+x][dy[k]+y] != '.' && V[dx[k]+x][dy[k]+y] != 'S') continue;
			int b =q.front().ss, u =z;
			if(dx[k] != 0) {
				for(int j =dy[k]+y; j < M; j++) {
					if(V[dx[k]+x][j] == 'B') b ^=1<<B[make_pair(dx[k]+x,j)];
					if(V[dx[k]+x][j] >= '0' && V[dx[k]+x][j] <= '9') b ^=1<<tr[make_pair(dx[k]+x,j)];}
				if(dx[k] == 1) u =1;
				else u =2;
				if(z == 0 && u != t+1) continue;
				if(u != z) for(int j =dy[k]+y; j < M; j++) {
					if(V[x][j] == 'B') b ^=1<<B[make_pair(x,j)];
					if(V[x][j] >= '0' && V[x][j] <= '9') b ^=1<<tr[make_pair(x,j)];}
				}
			if(1+D[z][x*M+y][q.front().ss] < D[u][(dx[k]+x)*M+dy[k]+y][b]) {
				D[u][(dx[k]+x)*M+dy[k]+y][b] =1+D[z][x*M+y][q.front().ss];
				if((dx[k]+x)*M+dy[k]+y == S && u != t+1) W[b] =D[u][(dx[k]+x)*M+dy[k]+y][b];
				q.push(make_pair(3*((dx[k]+x)*M+dy[k]+y)+u,b));}
			}
		q.pop();}

	for(int i =0; i < (1<<T); i++) {
		int v =0;
		for(int j =0; j < T; j++) if((i>>j)&1) v +=val[j];
		ans =max(ans,v-W[i]);}
	}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing