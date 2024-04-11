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
	cin.tie(0);
	cin.sync_with_stdio(0);
	int N,M,K;
	cin >> N >> M >> K;
	vector<string> V(N);
	for(int i =0; i < N; i++) cin >> V[i];

	for(int i =0; i < M; i++) {
		int ans =0;
		for(int j =0; j < N; j++) {
			int x =i+j, y =j;
			if(x < M && V[y][x] == 'L') ans++;
			x =i-j;
			if(x >= 0 && V[y][x] == 'R') ans++;
			x =i, y =2*j;
			if(y < N && V[y][x] == 'U') ans++;}
		cout << ans << ((i == M-1)?"\n":" ");}
	return 0;}

// look at my code
// my code is amazing