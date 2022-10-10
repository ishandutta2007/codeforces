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

struct fin {
	vector<int> T;
	fin(int N) {T.resize(N+1,0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] =max(T[i],val);}

	int get(int pos) {
		int ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret =max(ret,T[i]);
		return ret;}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector< pair<int,int> > XW(N);
	map<int,int> M;
	for(int i =0; i < N; i++) {
		cin >> XW[i].ff >> XW[i].ss;
		M[XW[i].ff-XW[i].ss] =0;
		M[XW[i].ff+XW[i].ss] =0;}
	sort(XW.begin(),XW.end());
	int m =0;
	ALL_THE(M,it) it->ss =m++;

	fin F(m+tisic);
	int ans =0;
	for(int i =0; i < N; i++) {
		int r =M[XW[i].ff-XW[i].ss], p =M[XW[i].ff+XW[i].ss];
		int t =F.get(r)+1;
		ans =max(ans,t);
		F.put(p,t);}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing