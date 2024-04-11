#include <bits/stdc++.h>
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
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265359
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M,B;
	long long MOD;
	cin >> N >> M >> B >> MOD;
	vector< vector<long long> > ans(M+1,vector<long long>(B+1,0));
	ans[0][0] =1;
	for(int i =0; i < N; i++) {
		int a;
		cin >> a;
		for(int j =0; j < M; j++) for(int b =0; b <= B-a; b++) {
			ans[j+1][b+a] =(ans[j][b]+ans[j+1][b+a])%MOD;
			if(ans[j+1][b+a] < 0) ans[j+1][b+a] +=MOD;}
		}
	long long ansF =0;
	for(int i =0; i <= B; i++) ansF +=ans[M][i];
	ansF %=MOD;
	if(ansF < 0) ansF +=MOD;
	cout << ansF << "\n";
	return 0;}

// look at my code
// my code is amazing


/*		map<int,long long> S;
		for(int k =0; k <= M; k++) {
			for(int j =0; j <= B; j++) S[k-k*a] +=ans[k][j];
			for(int b =0; b <= B; b++) ans_new[k][b] +=S[b-k*a];}
*/