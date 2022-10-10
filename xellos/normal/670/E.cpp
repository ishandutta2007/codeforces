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
	int N,M,P;
	cin >> N >> M >> P;
	string S,op;
	cin >> S >> op;

	vector<int> asg(N);
	stack<int> st;
	for(int i =0; i < N; i++) {
		if(S[i] == '(') {
			st.push(i);
			continue;}
		asg[st.top()] =i;
		asg[i] =st.top();
		st.pop();}

	set<int> live;
	for(int i =0; i < N; i++) live.insert(i);
	int akt =P-1;
	for(int i =0; i < M; i++) {
		if(op[i] == 'R') {
			akt =*live.upper_bound(akt);
			continue;}
		if(op[i] == 'L') {
			akt =*(--live.find(akt));
			continue;}
		int x =akt, y =asg[akt];
		if(x > y) swap(x,y);
		auto it =live.lower_bound(x);
		while(it != live.end() && *it <= y) {
			auto jt =it;
			it++;
			live.erase(jt);}
		if(it == live.end()) it--;
		akt =*it;}

	ALL_THE(live,it) cout << S[*it];
	cout << "\n";
	return 0;}

// look at my code
// my code is amazing