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
#define soclose 1e-8
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
	vector<string> V(N);
	for(int i =0; i < N; i++) cin >> V[i];
	vector< vector<int> > out(26,vector<int>(26,0));
	for(int i =0; i < N-1; i++) {
		int a =0;
		while(a < V[i].length() && a < V[i+1].length() && V[i][a] == V[i+1][a]) a++;
		if(a == V[i+1].length()) {cout << "Impossible\n"; return 0;}
		if(a == V[i].length()) continue;
		out[V[i+1][a]-'a'][V[i][a]-'a']++;}

	string ans;
	vector<bool> done(26,false);
	for(int i =0; i < 26; i++) {
		int x =-1;
		for(int j =0; j < 26; j++) if(!done[j]) {
			int s =0;
			ALL_THE(out[j],it) s +=*it;
			if(s == 0) x =j;}
		if(x == -1) {cout << "Impossible\n"; return 0;}
		done[x] =true;
		ans +=('a'+x);
		for(int j =0; j < 26; j++) out[j][x] =0;}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing