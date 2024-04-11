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
#define OVER9000 1234567890123456780LL
#define patkan 9
#define tisic 47
#define soclose 1e-7
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector< pair<int,int> > X(N);
	for(int i =0; i < N; i++) {
		cin >> X[i].ff;
		X[i].ss =i;}
	sort(begin(X),end(X));
	vector<int> ans(N);
	for(int i =0; i < N; i++) ans[X[i].ss] =i%2;
	for(int i =0; i < N; i++) cout << ans[i] << ((i == N-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing