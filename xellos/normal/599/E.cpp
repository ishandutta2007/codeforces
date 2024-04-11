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
#define in(a,b) ((a>>b)&1)
#define notin(a,b) (((a>>b)&1) == 0)
using namespace std;
// mylittledoge

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

long long ans[1<<13][13][13][14];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,M,Q;
	cin >> N >> M >> Q;
	if(N == 1) {cout << "1\n"; return 0;}
	vector< vector<int> > E(N,vector<int>(N,0));
	for(int i =0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		E[--a][--b] =1;
		E[b][a] =1;}
	vector< vector< pair<int,int> > > lcap(N);
	vector< vector<int> > child(N);
	for(int i =0; i < Q; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		c--, b--, a--;
		if(a == b && a != c) {cout << "0\n"; return 0;}
		if(a == b) continue;
		if(a != c && b != c) lcap[c].push_back(make_pair(a,b));
		if(a != c) child[c].push_back(a);
		if(b != c) child[c].push_back(b);}

	vector<bool> ban(1<<N,false);
	for(int i =0; i < (1<<N); i++) {
		for(int j =0; j < N; j++) if(notin(i,j)) 
			ALL_THE(lcap[j],it) if(in(i,it->ss) && in(i,it->ff)) ban[i] =true;
		for(int j =0; j < N; j++) if(in(i,j))
			ALL_THE(child[j],it) if(notin(i,*it)) ban[i] =true;
		}

	vector<int> v(1<<N), sub;

	for(int i =1; i < (1<<N); i++) for(int r =0; r < N; r++) if(in(i,r))
		for(int pr =0; pr < N; pr++) if(notin(i,pr) || (r == 0 && pr == 0)) {
			if((1<<r) == i) ans[i][r][pr][0] =1;
			for(int k =0; k < N; k++) {
				if(!in(i,k) || k == r) {ans[i][r][pr][k+1] =ans[i][r][pr][k]; continue;}
				// nie je syn
				ans[i][r][pr][k+1] =ans[i][r][pr][k];
				// je syn, s cim dalsim?
				sub.clear();
				for(int j =0; j < N; j++) if(in(i,j) && j != r && j != k) sub.push_back(j);
				int s =sub.size(), b =0;
				v[0] =1<<k;
				for(int j =0; j < (1<<s); j++) {
					while((1<<b) <= j) b++;
					for(int l =b; l < s; l++) v[j+(1<<l)] =v[j]+(1<<sub[l]);
					ans[i][r][pr][k+1] +=ans[v[j]][k][r][N]*ans[i-v[j]][r][pr][k];}
				}
			// hrany
			bool ok =true;
			for(int j =0; j < N; j++) if(E[r][j] && (pr != j && notin(i,j))) ok =false;
			if(!ok || ban[i]) ans[i][r][pr][N] =0;
			}

	cout << ans[(1<<N)-1][0][0][N] << "\n";
	return 0;}

// look at my code
// my code is amazing