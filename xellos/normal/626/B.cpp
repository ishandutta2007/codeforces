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

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	string s;
	cin >> N >> s;
	int poc[3] ={0,0,0};
	for(int i =0; i < s.length(); i++) {
		if(s[i] == 'B') poc[0]++;
		if(s[i] == 'G') poc[1]++;
		if(s[i] == 'R') poc[2]++;}
	string ans,c="BGR";
	for(int k =0; k < 3; k++) {
		if(poc[(1+k)%3] > 0 && poc[(2+k)%3] > 0) {ans +=c[k]; continue;}
		if(poc[(1+k)%3] == 0 && poc[(2+k)%3] == 0) {ans +=c[k]; continue;}
		if(poc[k] == 0) continue;
		if(poc[(1+k)%3] == 1 || poc[(2+k)%3] == 1) continue;
		ans +=c[k];}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing