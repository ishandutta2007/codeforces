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
	int N,S;
	cin >> N >> S;
	int ans =-1;
	for(int i =0; i < N; i++) {
		int x,y;
		cin >> x >> y;
		if(x <= S && y == 0) ans =max(ans,0);
		if(x < S && y > 0) ans =max(ans,100-y);}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing