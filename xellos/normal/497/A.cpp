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
	int N,M;
	cin >> N >> M;
	vector<string> V(N);
	for(int i =0; i < N; i++) cin >> V[i];
	int ans =0;
	vector<bool> id(N,true);
	for(int j =0; j < M; j++) {
		bool rem =false;
		for(int k =1; k < N; k++) if(id[k] && (V[k][j] < V[k-1][j])) rem =true;
		if(rem) {ans++; continue;}
		for(int k =1; k < N; k++) if(V[k][j] > V[k-1][j]) id[k] =false;}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing