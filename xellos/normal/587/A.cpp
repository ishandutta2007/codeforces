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
	int N, mx =1000000;
	scanf(" %d",&N);
	vector<int> poc(mx+10000,0);
	for(int i =0; i < N; i++) {
		int a;
		scanf(" %d",&a);
		poc[a]++;}
	int ans =0;
	for(int i =0; i <= mx+5000; i++) {
		if(poc[i]%2 != 0) ans++;
		poc[i+1] +=poc[i]/2;}
	printf("%d\n",ans);
	return 0;}

// look at my code
// my code is amazing