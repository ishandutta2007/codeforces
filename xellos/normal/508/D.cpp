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
#define OVER9000 1234567890
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

vector<int> sol; // Eulerian path

void DFS(int R, vector< vector<int> > &G) {
	while(!G[R].empty()) {
		int x =*G[R].rbegin();
		G[R].pop_back();
		DFS(x,G);}
	sol.push_back(R);}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector<int> > Gin(1<<16),Gout(1<<16);
	for(int i =0; i < N; i++) {
		string s;
		cin >> s;
		int x =s[0]+256*s[1], y =s[1]+256*s[2];
		Gout[x].push_back(y);
		Gin[y].push_back(x);}

	int pz =0;
	for(int i =0; i < 1<<16; i++) if(Gin[i].size() != Gout[i].size()) pz++;
	if(pz > 2) {cout << "NO\n"; return 0;}

	for(int i =0; i < 1<<16; i++) if(Gin[i].size() > Gout[i].size()) {
		if(Gin[i].size() != Gout[i].size()+1) {cout << "NO\n"; return 0;}
		DFS(i,Gin);
		if((int)sol.size() != N+1) {cout << "NO\n"; return 0;}
		cout << "YES\n";
		string ans;
		for(int j =0; j < sol.size(); j++) ans +=(char)(sol[j]%256);
		ans +=(char)(i/256);
		cout << ans << "\n";
		return 0;}

	for(int i =0; i < 1<<16; i++) if((int)Gin[i].size() != 0) {
		DFS(i,Gin);
		if((int)sol.size() != N+1) {cout << "NO\n"; return 0;}
		cout << "YES\n";
		string ans;
		for(int j =0; j < sol.size(); j++) ans +=(char)(sol[j]%256);
		ans +=(char)(i/256);
		cout << ans << "\n";
		return 0;}

	cout << "NO\n";
	return 0;}

// look at my code
// my code is amazing