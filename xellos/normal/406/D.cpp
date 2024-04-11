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
	int N,M;
	cin >> N;
	vector< pair<long long,long long> > P(N);
	for(int i =0; i < N; i++) cin >> P[i].ff >> P[i].ss;

	vector<int> H;
	vector<int> par[18];
	for(int i =0; i < 18; i++) par[i].resize(N,N-1);
	for(int i =N-1; i >= 0; i--) {
		while(H.size() > 1) {
			long long a =P[*H.rbegin()].ff-P[i].ff;
			long long b =P[*H.rbegin()].ss-P[i].ss;
			long long c =P[*(H.rbegin()+1)].ff-P[i].ff;
			long long d =P[*(H.rbegin()+1)].ss-P[i].ss;
			long long l =a*d-b*c;
			if(l > 0) H.pop_back();
			else break;}
		if(!H.empty()) par[0][i] =*H.rbegin();
		H.push_back(i);}

	vector<int> dep(N,0);
	for(int i =N-2; i >= 0; i--) dep[i] =dep[par[0][i]]+1;
	for(int i =1; i < 18; i++) for(int j =0; j < N; j++)
		par[i][j] =par[i-1][par[i-1][j]];

	cin >> M;
	for(int i =0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		a--, b--;
		if(dep[a] > dep[b]) swap(a,b);
		int k =17;
		while(dep[a] != dep[b]) {
			if(dep[par[k][b]] < dep[a]) k--;
			else b =par[k][b];}
		k =17;
		while(k >= 0 && a != b) {
			if(par[k][a] == par[k][b]) k--;
			else a =par[k][a], b =par[k][b];}
		if(a != b) a =par[0][a], b =par[0][b];
		cout << a+1 << ((i == M-1)?"\n":" ");}
	return 0;}

// look at my code
// my code is amazing