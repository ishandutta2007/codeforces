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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,L,R,X;
	cin >> N >> L >> R >> X;
	vector<int> C(N);
	for(int i =0; i < N; i++) cin >> C[i];
	int ans =0;
	for(int i =0; i < (1<<N); i++) {
		int p =0, s =0, mx =0, mi =OVER9000;
		for(int j =0; j < N; j++) if((i>>j)&1) {
			mx =max(mx,C[j]);
			mi =min(mi,C[j]);
			s +=C[j];
			p++;}
		if(p >= 2 && mx-mi >= X && s >= L && s <= R) ans++;}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing