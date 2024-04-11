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

int solve(int f, int xf, vector< pair<int,int> > &L, map< pair<int,int>, int> &ans) {
	auto it =ans.find(make_pair(f,xf));
	if(it != ans.end()) return it->ss;
	int N =L.size();
	if(f == N) return 0;

	// prvy orientujem vpravo
	int ret =solve(f+1,max(xf,L[f].ff+L[f].ss),L,ans)+max(0,L[f].ff+L[f].ss-max(xf,L[f].ff));

	// pref. max.
	vector<int> pm(N-f+1,0);
	for(int i =f; i < N; i++) pm[i-f+1] =max(pm[i-f],L[i].ff+L[i].ss);

	// sort podla laveho kraja ak su orientovane vlavo
	vector< pair<int,int> > V(N-f);
	for(int i =f; i < N; i++) V[i-f].ff =L[i].ff-L[i].ss, V[i-f].ss =i;
	sort(begin(V),end(V));

	// prvy orientovany vlavo
	for(int i =0; i < N-f; i++) {
		int r =max(xf,L[V[i].ss].ff);
		r =max(r,pm[V[i].ss-f]);
		int akt =solve(V[i].ss+1,max(xf,r),L,ans);
		akt +=max(0,r-max(xf,V[i].ff));
		ret =max(ret,akt);}

	ans[make_pair(f,xf)] =ret;
	return ret;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< pair<int,int> > L(N);
	for(int i =0; i < N; i++) cin >> L[i].ff >> L[i].ss;
	sort(begin(L),end(L));
	map< pair<int,int>,int> ans;
	cout << solve(0,-100000000,L,ans) << "\n";
	return 0;}

// look at my code
// my code is amazing