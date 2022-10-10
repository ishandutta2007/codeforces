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
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector<bool> used(N,false);
	vector<int> X(M),op(M);
	vector<int> init;
	
	for(int i =0; i < M; i++) {
		string s;
		cin >> s >> X[i];
		if(!used[--X[i]] && s[0] == '-') init.push_back(X[i]);
		used[X[i]] =true;
		if(s[0] == '+') op[i] =0;
		else op[i] =1;}
	
	vector<int> ans;
	for(int i =0; i < N; i++) if(!used[i]) ans.push_back(i);
	
	int l =(init.empty())?X[0]:*init.rbegin(), s =init.size();
	bool b =true, on =!(init.empty());
	for(int i =0; i < M; i++) {
		if(X[i] == l) {
			if(op[i] == 0 && s > 0) b =false;
			if(op[i] == 1 && s > 1) b =false;
			if(op[i] == 0) on =true;
			else on =false;}
		else if(!on)
			if(op[i] == 0 || s > 0) b =false;
		if(op[i] == 0) s++;
		else s--;}
	if(b) ans.push_back(l);
	
	sort(ans.begin(),ans.end());
	cout << ans.size() << "\n";
	for(uint i =0; i < ans.size(); i++) cout << ans[i]+1 << ((i+1 == ans.size())?"\n":" ");
	return 0;}

// look at my code
// my code is amazing