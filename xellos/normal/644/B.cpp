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
	int N,B;
	cin >> N >> B;
	queue< pair<int,int> > q;
	long long fr =0;
	vector<long long> ans(N,-1);
	for(int i =0; i < N; i++) {
		int t,d;
		cin >> t >> d;
		while(!q.empty()) {
			pair<int,int> p =q.front();
			if(p.ff+fr > t) break;
			q.pop();
			B++;
			ans[p.ss] =p.ff+fr;
			fr +=p.ff;}
		if(q.empty()) fr =max(fr,1LL*t);
		if(B >= 0) {
			q.push(make_pair(d,i));
			B--;}
		}
	while(!q.empty()) {
		pair<int,int> p =q.front();
		q.pop();
		ans[p.ss] =p.ff+fr;
		fr +=p.ff;}
	for(int i =0; i < N; i++) cout << ans[i] << "\n";
	return 0;}

// look at my code
// my code is amazing