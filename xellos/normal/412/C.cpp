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
#define OVER9000 2234567890123456780LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.rbegin(); LIE != CAKE.rend(); LIE++)
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
	int N;
	cin >> N;
	vector<string> V(N);
	for(int i =0; i < N; i++) cin >> V[i];
	string ans;
	for(uint i =0; i < V[0].length(); i++) {
		set<char> s;
		for(int j =0; j < N; j++) if(V[j][i] != '?')
			s.insert(V[j][i]);
		if(s.size() > 1) ans +='?';
		if(s.size() == 1) ans +=*s.begin();
		if(s.empty()) ans +='a';}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing