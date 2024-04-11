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
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
using namespace std;
// mylittledoge

int gcd(int x, int y) {
	if(x > y) swap(x,y);
	while(x > 0) {
		int z =y%x;
		y =x;
		x =z;}
	return y;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> L(N),C(N);
	for(int i =0; i < N; i++) cin >> L[i];
	for(int i =0; i < N; i++) cin >> C[i];
	map<int,int> S;
	S[0] =0;
	for(int i =0; i < N; i++) ALL_THE(S,it) {
		int x =gcd(L[i],it->ff);
		auto jt =S.find(x);
		if(jt == S.end()) S[x] =it->ss+C[i];
		else jt->ss =min(jt->ss,it->ss+C[i]);}
	if(S.find(1) == S.end()) cout << "-1\n";
	else cout << S[1] << "\n";
	return 0;}

// look at my code
// my code is amazing