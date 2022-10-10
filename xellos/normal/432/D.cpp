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
#define soclose 1e-6
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
	string s;
	cin >> s;
	int N =s.length();

	vector<int> prev(N+1,0);
	for(int i =2; i <= N; i++) {
		int a =prev[i-1];
		while(a > 0 && s[a] != s[i-1]) a =prev[a];
		if(s[a] == s[i-1]) a++;
		prev[i] =a;}

	vector<int> P(N+1,1);
	for(int i =N; i > 0; i--) P[prev[i]] +=P[i];

	vector< pair<int,int> > ans;
	int l =N;
	while(l > 0) {
		ans.push_back(make_pair(l,P[l]));
		l =prev[l];}

	cout << ans.size() << "\n";
	while(!ans.empty()) {
		cout << ans.rbegin()->ff << " " << ans.rbegin()->ss << "\n";
		ans.pop_back();}
	return 0;}

// look at my code
// my code is amazing