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
#define OVER9000 1234567890
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
	int N,M;
	cin >> N >> M;
	vector<string> W(N);
	for(int i =0; i < N; i++) cin >> W[i];

	vector< vector<int> > maxR(N, vector<int>(M+1,0));
	for(int i =0; i < N; i++) for(int j =M-1; j >= 0; j--)
		if(W[i][j] == '1') maxR[i][j] =maxR[i][j+1]+1;

	int ans =0;
	vector<int> V(5000+tisic,0);
	for(int i =0; i < M; i++) {
		for(int j =0; j <= 5000; j++) V[j] =0;
		for(int j =0; j < N; j++) V[maxR[j][i]]++;
		int a =0;
		for(int j =5000; j >= 0; j--) {
			a +=V[j];
			ans =max(ans,a*j);}
		}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing