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
// mylittledoge
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,K,D;
	cin >> N >> K >> D;
	vector< vector<int> > ans(D,vector<int>(N));
	long long P =1;
	for(int i =0; i < D; i++) P =min(1LL*N,P*K);
	if(P < 1LL*N) {
		cout << "-1\n";
		return 0;}
	for(int i =0; i < N; i++) {
		int a =i;
		for(int j =0; j < D; j++) {
			ans[j][i] =a%K;
			a /=K;}
		}

	for(int i =0; i < D; i++) for(int j =0; j < N; j++)
		cout << (ans[i][j]+1) << ((j == N-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing