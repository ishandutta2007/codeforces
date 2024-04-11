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
#define soclose 1e-6
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector< vector<int> > A(N,vector<int>(M,-1));
	int dx[] ={0,0,1,-1};
	int dy[] ={1,-1,0,0};

	for(int i =0; i < N; i++) for(int j =0; j < M; j++) if(A[i][j] == -1) {
		int c =0;
		for(int k =0; k < 5; k++) for(int l =0; l < 4; l++)
			if(i+dx[l] >= 0 && j+dy[l] >= 0 && i+dx[l] < N && j+dy[l] < M)
				if(A[i+dx[l]][j+dy[l]] == c) c++;
		A[i][j] =c;
		int a =1;
		while(true) {
			bool b =true;
			if(j+a < M) {
				int f =0;
				for(int k =0; k < 5; k++) for(int l =0; l < 4; l++)
					if(i+dx[l] >= 0 && j+a+dy[l] >= 0 && i+dx[l] < N && j+a+dy[l] < M)
						if(A[i+dx[l]][j+a+dy[l]] == f) f++;
				if(f < c) b =false;}
			if(!b) break;
			for(int l =0; l <= a; l++) {
				if(i+l >= N || j+a >= M || A[i+l][j+a] != -1) {b =false; break;}
				for(int k =0; k < 4; k++)
					if(i+l+dx[k] >= 0 && j+a+dy[k] >= 0 && i+l+dx[k] < N && j+a+dy[k] < M)
					if(i+l+dx[k] < i || j+a+dy[k] < j)
						if(A[i+l+dx[k]][j+a+dy[k]] == c) {b =false; break;}
				if(!b) break;}
			for(int l =0; l <= a; l++) {
				if(i+a >= N || j+l >= M || A[i+a][j+l] != -1) {b =false; break;}
				for(int k =0; k < 4; k++)
					if(i+a+dx[k] >= 0 && j+l+dy[k] >= 0 && i+a+dx[k] < N && j+l+dy[k] < M)
					if(i+a+dx[k] < i || j+l+dy[k] < j)
						if(A[i+a+dx[k]][j+l+dy[k]] == c) {b =false; break;}
				if(!b) break;}
			if(!b) break;
			for(int l =0; l <= a; l++) A[i+l][j+a] =A[i+a][j+l] =c;
			a++;}
		}

	for(int i =0; i < N; i++) {
		for(int j =0; j < M; j++) cout << (char)(A[i][j]+'A');
		cout << "\n";}
	return 0;}

// look at my code
// my code is amazing