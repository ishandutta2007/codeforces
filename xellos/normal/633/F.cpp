#include <bits/stdc++.h>
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
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890123456789LL
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
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

vector< vector<int> > G;
vector<int> C;
vector<long long> ans[5];

void DFS(int R, int par) {
	ans[0][R] =C[R];
	ALL_THE(G[R],it) if(*it != par) {
		DFS(*it,R);
		ans[0][R] =max(ans[0][R],C[R]+ans[0][*it]);}
	long long x =0;
	ans[1][R] =C[R];
	ALL_THE(G[R],it) if(*it != par) {
		ans[1][R] =max(ans[1][R],x+ans[0][*it]+C[R]);
		x =max(x,ans[0][*it]);}
	ans[2][R] =ans[1][R];
	ALL_THE(G[R],it) if(*it != par) {
		ans[2][R] =max(ans[2][R],ans[2][*it]);
		ans[3][R] =max(ans[3][R],ans[2][*it]+C[R]);}
	ALL_THE(G[R],it) if(*it != par) ans[3][R] =max(ans[3][R],ans[3][*it]+C[R]);
	x =0;
	long long y =-OVER9000;
	ALL_THE(G[R],it) if(*it != par) {
		ans[3][R] =max(ans[3][R],ans[2][*it]+x+C[R]);
		ans[3][R] =max(ans[3][R],ans[0][*it]+y+C[R]);
		x =max(x,ans[0][*it]);
		y =max(y,ans[2][*it]);}
	y =0;
	x =-OVER9000;
	ALL_THE(G[R],it) if(*it != par) {
		ans[4][R] =max(ans[4][R],x+ans[0][*it]+C[R]);
		ans[4][R] =max(ans[4][R],y+ans[3][*it]+C[R]);
		x =max(x,ans[3][*it]);
		y =max(y,ans[0][*it]);}
	x =y =0;
	ALL_THE(G[R],it) {
		ans[4][R] =max(ans[4][R],x+ans[2][*it]+C[R]);
		x =max(x,y+ans[0][*it]);
		y =max(y,ans[0][*it]);}
	x =-OVER9000;
	y =0;
	ALL_THE(G[R],it) {
		ans[4][R] =max(ans[4][R],x+ans[0][*it]+C[R]);
		x =max(x,y+ans[2][*it]);
		y =max(y,ans[0][*it]);}
	y =-OVER9000;
	x =-OVER9000;
	ALL_THE(G[R],it) {
		ans[4][R] =max(ans[4][R],x+ans[0][*it]+C[R]);
		x =max(x,y+ans[0][*it]);
		y =max(y,ans[2][*it]);}
	x =-OVER9000;
	ALL_THE(G[R],it) {
		ans[4][R] =max(ans[4][R],x+ans[2][*it]);
		x =max(x,ans[2][*it]);}
	}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	C.resize(N);
	for(int i =0; i < N; i++) cin >> C[i];
	G.resize(N);
	for(int i =0; i < N-1; i++) {
		int a,b;
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);}
	for(int i =0; i < 5; i++) ans[i].resize(N,-OVER9000);
	DFS(0,0);
	long long ansF =0;
	for(int i =0; i < N; i++) ansF =max(ansF,ans[4][i]);
	cout << ansF << "\n";
	return 0;}

// look at my code
// my code is amazing