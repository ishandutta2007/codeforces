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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,M;
	cin >> N >> M;
	map<int,int> F;
	set<int> bad;
	for(int i =0; i < N; i++) {
		int a;
		cin >> a;
		if(F.find(a) != F.end()) bad.insert(a);
		F[a] =i+1;}
	vector<int> ans;
	bool mul =false;
	for(int i =0; i < M; i++) {
		int a;
		cin >> a;
		if(F.find(a) == F.end()) {cout << "Impossible\n"; return 0;}
		if(bad.find(a) != bad.end()) mul =true;
		ans.push_back(F[a]);}
	if(mul) cout << "Ambiguity\n";
	else {
		cout << "Possible\n";
		for(int i =0; i < M; i++)
			cout << ans[i] << ((i == M-1)?"\n":" ");
		}
	return 0;}

// look at my code
// my code is amazing