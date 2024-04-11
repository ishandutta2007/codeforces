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
	scanf(" %d",&N);
	vector<int> P(N);
	for(int i =0; i < N; i++) {
		scanf(" %d",&P[i]);
		P[i]--;}

	vector<int> sz(N+1,0);
	vector<bool> vis(N,false);
	vector< vector<int> > cyc;
	for(int i =0; i < N; i++) if(!vis[i]) {
		int sz_akt =1, akt =P[i];
		vis[i] =true;
		vector<int> v(1,i);
		while(!vis[akt]) {
			sz_akt++;
			v.push_back(akt);
			vis[akt] =true;
			akt =P[akt];}
		sz[sz_akt]++;
		cyc.push_back(v);
		if(sz_akt == 1) {
			printf("YES\n");
			for(int j =0; j < N; j++) if(i != j) printf("%d %d\n",i+1,j+1);
			return 0;}
		}

	if(sz[2] == 0) {printf("NO\n"); return 0;}
	for(int i =3; i <= N; i +=2) if(sz[i] > 0) {
		printf("NO\n");
		return 0;}

	printf("YES\n");
	for(int i =0; i < (int)cyc.size(); i++) if(cyc[i].size() == 2) {
		printf("%d %d\n",cyc[i][0]+1,cyc[i][1]+1);
		for(int j =0; j < (int)cyc.size(); j++) if(j != i) {
			for(int k =0; k < (int)cyc[j].size(); k +=2) printf("%d %d\n",cyc[j][k]+1,cyc[i][0]+1);
			for(int k =1; k < (int)cyc[j].size(); k +=2) printf("%d %d\n",cyc[j][k]+1,cyc[i][1]+1);
			}
		return 0;}
	return 0;}

// look at my code
// my code is amazing