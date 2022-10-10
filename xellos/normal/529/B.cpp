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
	int N;
	cin >> N;
	vector< pair<int,int> > A(N);
	vector<int> H;
	for(int i =0; i < N; i++) {
		cin >> A[i].ff >> A[i].ss;
		H.push_back(A[i].ff);
		H.push_back(A[i].ss);}
	sort(H.begin(),H.end());

	int ans =OVER9000;
	for(uint k =0; k < H.size(); k++) {
		int l =0, K =N/2, w =0;
		vector< pair<int,int> > var;
		bool ok =true;
		for(int i =0; i < N; i++) {
			if(A[i].ff <= H[k] && A[i].ss <= H[k]) {var.push_back(A[i]); continue;}
			if(A[i].ff > H[k] && A[i].ss > H[k]) {ok =false; break;}
			if(A[i].ss <= H[k]) w +=A[i].ff;
			else K--, w +=A[i].ss;}
		if(K < 0 || !ok) continue;

		vector<int> V;
		ALL_THE(var,it) {
			w +=it->ff;
			V.push_back(it->ss-it->ff);}

		sort(V.begin(),V.end());
		for(int i =0; i < min((int)V.size(),K); i++) if(V[i] < 0) w +=V[i];
//			cout << H[k] << " " << w << "\n";
		ans =min(ans,H[k]*w);}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing