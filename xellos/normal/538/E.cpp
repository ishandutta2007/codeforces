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
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265359
using namespace std;
// mylittledoge

vector<long long> ans[2]; // max., min.
vector<long long> L;

void DFS(int R, vector< vector<int> > &G, vector<int> &dep) {
	bool isL =true;
	ALL_THE(G[R],it) if(dep[*it] == -1) {
		isL =false;
		dep[*it] =dep[R]+1;
		DFS(*it,G,dep);
		L[R] +=L[*it];}
	if(isL) {
		L[R] =1;
		ans[0][R] =ans[1][R] =0;
		return;}
	int sons =0;
	long long sum[2] ={0,0};
	ALL_THE(G[R],it) if(dep[*it] > dep[R]) {
		if(dep[R]%2 == 0) {
			ans[0][R] =max(ans[0][R],L[R]-L[*it]+ans[0][*it]);
			// rozhadz sum[1] cisel tak aby najvacsie z nich bolo min.
			sum[1] +=ans[1][*it]+1;}
		else {
			if(ans[1][R] == -1) ans[1][R] =L[R];
			ans[1][R] =min(ans[1][R],ans[1][*it]);
			// rozhadz sum[0] cisel tak aby najmensie z nich bolo max.
			sum[0] +=ans[0][*it];}
		sons++;}
	if(dep[R]%2 == 0) ans[1][R] =sum[1]-1;
	else ans[0][R] =sum[0];
	}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector< vector<int> > G(N);
	for(int i =0; i < N-1; i++) {
		int u,v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);}

	vector<int> dep(N,-1);
	L.resize(N,0);
	dep[0] =0;
	ans[0].resize(N,-1);
	ans[1].resize(N,-1);
	DFS(0,G,dep);

	cout << ans[0][0]+1 << " " << ans[1][0]+1 << "\n";
	return 0;}

// look at my code
// my code is amazing