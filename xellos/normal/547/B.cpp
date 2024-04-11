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
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector< pair<int,int> > V(N);
	for(int i =0; i < N; i++) {
		cin >> V[i].ff;
		V[i].ss =i;}
	sort(begin(V),end(V));

	vector<int> ans(N+1,-1);
	map<int,int> M;
	int maxG =0;
	for(int i =N-1; i >= 0; i--) {
		auto it =M.upper_bound(V[i].ss);
		int l =V[i].ss, r =V[i].ss+1;
		if(it != M.end() && it->ff == V[i].ss+1) {
			r =it->ff+it->ss;
			M.erase(it);}
		it =M.upper_bound(V[i].ss);
		if(it != M.begin()) {
			it--;
			if(it->ff+it->ss == V[i].ss) {
				l =it->ff;
				M.erase(it);}
			}
		M[l] =r-l;
		maxG =max(maxG,r-l);
		ans[maxG] =max(ans[maxG],V[i].ff);}

	for(int i =N; i >= 1; i--) ans[i-1] =max(ans[i-1],ans[i]);
	for(int i =1; i <= N; i++) cout << ans[i] << ((i == N)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing