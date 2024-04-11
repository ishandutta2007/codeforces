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
#define OVER9000 1234567890123456780LL
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
	int N,M,mn,mx;
	cin >> N >> M >> mn >> mx;
	int mnA =150, mxA =-1;
	for(int i =0; i < M; i++) {
		int a;
		cin >> a;
		mnA =min(mnA,a);
		mxA =max(mxA,a);}

	if(mnA < mn || mxA > mx) {cout << "Incorrect\n"; return 0;}
	if(mnA == mn && mxA == mx) {cout << "Correct\n"; return 0;}
	if(mnA > mn && mxA < mx && N-M == 1) cout << "Incorrect\n";
	else cout << "Correct\n";
	return 0;}

// look at my code
// my code is amazing