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
	int N;
	cin >> N;
	vector< vector<int> > A(N,vector<int>(N));
	for(int i =0; i < N*N; i++) cin >> A[i/N][i%N];

	int s =0;
	for(int i =0; i < N; i++)
		s =(s+A[i][i]*A[i][i])%2;

	int Q;
	cin >> Q;
	for(int q =0; q < Q; q++) {
		int t;
		cin >> t;
		if(t == 3) cout << s;
		else {
			int x;
			cin >> x;
			x--;
			s =1-s;}}
	cout << "\n";
	return 0;}

// look at my code
// my code is amazing