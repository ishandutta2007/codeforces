// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
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
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	int N,M;
	scanf(" %d %d",&N,&M);
	vector<int> P(N);
	for(int i =0; i < N; i++) scanf(" %d",&P[i]);
	vector< vector<dbl> > pinv(N,vector<dbl>(N,0));
	for(int i =0; i < N; i++) for(int j =i+1; j < N; j++)
		if(P[i] > P[j]) pinv[i][j] =1;

	for(int i =0; i < M; i++) {
		int a,b;
		scanf(" %d %d",&a,&b);
		a--, b--;
		if(a > b) swap(a,b);
		for(int j =b+1; j < N; j++) pinv[b][j] =pinv[a][j] =0.5*(pinv[a][j]+pinv[b][j]);
		for(int j =0; j < a; j++) pinv[j][b] =pinv[j][a] =0.5*(pinv[j][a]+pinv[j][b]);
		for(int j =a+1; j < b; j++) {
			dbl d =pinv[a][j]-pinv[j][b];
			pinv[a][j] =0.5*(1+d);
			pinv[j][b] =0.5*(1-d);}
		pinv[a][b] =0.5;}

	dbl ans =0;
	for(int i =0; i < N; i++) for(int j =i+1; j < N; j++) ans +=pinv[i][j];
	printf("%.10f\n",ans);
	return 0;}

// look at my code
// my code is amazing