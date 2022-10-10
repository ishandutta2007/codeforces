// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
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
using namespace std::tr1;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,K, mi =OVER9000;
	cin >> N >> K;
	vector<bool> used(N,false);
	vector< pair<int,int> > stool;
	dbl sum =0;
	for(int i =0; i < N; i++) {
		int c,t;
		cin >> c >> t;
		if(t == 1) stool.push_back(make_pair(c,i));
		if(mi > c) mi =c;
		sum +=c;}
	vector< vector<int> > ans(K);
	sort(begin(stool),end(stool));
	for(int i =0; i < min((int)stool.size(),K-1); i++) {
		sum -=stool[stool.size()-1-i].ff*0.5;
		ans[i].push_back(stool[stool.size()-1-i].ss);
		used[stool[stool.size()-1-i].ss] =true;}
	if(stool.size() >= K) sum -=mi*0.5;
	int fe =0;
	while(!ans[fe].empty()) fe++;
	for(int i =0; i < N; i++) if(!used[i]) {
		ans[fe].push_back(i);
		fe =min(fe+1,K-1);}
	cout << fixed << setprecision(1) << sum << "\n";
	for(int k =0; k < K; k++) {
		cout << ans[k].size();
		ALL_THE(ans[k],it) cout << " " << *it+1;
		cout << "\n";}
	return 0;}

// look at my code
// my code is amazing