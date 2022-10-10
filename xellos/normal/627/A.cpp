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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	long long S,X;
	cin >> S >> X;
	long long ans =0;
	if(S == X) ans -=2;
	int p1 =0;
	vector<int> p2;
	for(int k =0; k < 60; k++) {
		if((X>>k)&1) {
			p1++;
			S -=1LL<<k;}
		else p2.push_back(k+1);}
	ALL_THE(p2,it) if((S>>*it)&1) S -=1LL<<(*it);
	if(S == 0) ans +=1LL<<p1;
	else ans =0;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing