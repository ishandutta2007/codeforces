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

vector<long long> ansS[2];
vector<long long> ansR;

void DFS(int R, vector< vector<int> > &son, vector<int> &eff) {
	vector<long long> eff_son;
	long long ss =0, s =0;
	ALL_THE(son[R],it) {
		DFS(*it,son,eff);
		ss +=ansS[0][*it];
		eff_son.push_back(ansS[1][*it]-ansS[0][*it]);}
	sort(begin(eff_son),end(eff_son));

	ansS[0][R] =ss;
	int p =0;
	for(int i =eff_son.size()-1; i >= 0; i--) {
		s +=eff_son[i];
		p++;
		ansS[p%2][R] =max(ansS[p%2][R],ss+s);}

	ansR[R] =ansS[0][R]+eff[R];
	ansS[1][R] =max(ansS[1][R],ansR[R]);
	return;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> par(N), eff(N);
	vector< vector<int> > son(N);
	ansS[0].resize(N,0);
	ansS[1].resize(N,0);
	ansR.resize(N,0);
	for(int i =0; i < N; i++) {
		cin >> par[i] >> eff[i];
		if(i > 0) son[--par[i]].push_back(i);}

	long long ans =0;
	DFS(0,son,eff);
	for(int i =0; i < N; i++) ans =max(ans,ansR[i]);
	ans =max(ans,ansS[0][0]);
	ans =max(ans,ansS[1][0]);
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing