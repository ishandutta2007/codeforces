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
	int N,M,K;
	cin >> N >> M >> K;
	vector< vector<int> > A(N,vector<int>(M));
	for(int i =0; i < N*M; i++) cin >> A[i/M][i%M];

	vector<int> ans(N,0), mC(M,0);
	for(int i =0; i < K; i++) {
		int a,b;
		cin >> a >> b;
		ans[--a]--;
		mC[--b]++;}

	for(int i =0; i < N; i++) for(int j =0; j < M; j++) if(A[i][j] == 1)
		ans[i] +=mC[j];

	for(int i =0; i < N; i++) cout << ans[i] << ((i == N-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing