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
	vector<int> V(N);
	for(int i =0; i < N; i++) cin >> V[i];
	double ans =0;
	for(int i =0; i < M; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		ans =max(ans,1.0*(V[a-1]+V[b-1])/c);}
	cout << fixed << setprecision(10) << ans << "\n";
	return 0;}

// look at my code
// my code is amazing