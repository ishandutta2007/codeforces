// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1034567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int G[5][5];
	for(int i =0; i < 5; i++) for(int j =0; j < 5; j++) cin >> G[i][j];

	vector<int> P(5);
	for(int i =0; i < 5; i++) P[i] =i;
	int ans =0;
	while(true) {
		int akt =0;
		for(int i =0; i < 5; i++) for(int j =i; j < 4; j +=2) akt +=G[P[j]][P[j+1]]+G[P[j+1]][P[j]];
		ans =max(ans,akt);
		if(!next_permutation(P.begin(),P.end())) break;}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing