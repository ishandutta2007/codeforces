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
#define OVER9000 223456789012345678LL
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
	int N,T;
	cin >> N >> T;
	vector<int> next(N);
	for(int i =0; i < N; i++) {
		cin >> next[i];
		next[i] +=i;}
	vector<bool> vis(N,false);
	vis[0] =true;
	int akt =next[0];
	while(true) {
		if(vis[akt]) break;
		vis[akt] =true;
		akt =next[akt];}
	cout << (vis[T-1]?"YES\n":"NO\n");
	return 0;}

// look at my code
// my code is amazing