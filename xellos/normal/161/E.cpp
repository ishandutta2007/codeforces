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
#define dbl long double
using namespace std;
using namespace std::tr1;
// mylittledoge

vector< vector<int> > P[10][10];
vector< vector<int> > ppoc; // 5 cifier, prve 3 cisla pevne, zvysne prefixy take
int pw10[100];

int bt(int n, int N, vector<int> &p) {
	if(n == N) return 1;
	int ret =0, x =0;
	for(int i =0; i < n; i++) x =x*10+((p[i]/pw10[N-n-1])%10);
	ALL_THE(P[N][n][x],it) {
		if(N == 5 && n == 2) {
			p.push_back(*it);
			int y =0, z =0;
			for(int i =0; i < 3; i++) y =y*10+((p[i]/10)%10);
			for(int i =0; i < 3; i++) z =z*10+(p[i]%10);
			ret +=ppoc[y][z];
			p.pop_back();
			continue;}
		p.push_back(*it);
		ret +=bt(n+1,N,p);
		p.pop_back();}
	return ret;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	pw10[0] =1;
	for(int i =1; i < 10; i++) pw10[i] =10*pw10[i-1];
	for(int i =2; i < 6; i++) for(int j =0; j < 6; j++) P[i][j].resize(100000);
	vector<bool> isP(100000,true);
	for(int i =2; i <= 100000; i++) if(isP[i]) {
		for(int l =2; l <= 5; l++) {
			for(int k =0; k <= l; k++) {
				int x =i;
				for(int j =0; j < l-k; j++) x /=10;
				P[l][k][x].push_back(i);}
			}
		for(int j =1; j <= 100000/i; j++) isP[i*j] =false;
		}

	ppoc.resize(1000,vector<int>(1000,0));
	for(int i =0; i < 1000; i++) ALL_THE(P[5][3][i],it)
		for(int j =0; j < 1000; j++) ALL_THE(P[5][3][j],jt)
			if(((*jt)/10)%10 == (*it)%10) ppoc[i][j]++;

	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		int p;
		cin >> p;
		int sz =0, x =p;
		while(x > 0) {sz++; x /=10;}
		vector<int> v(1,p);
		cout << bt(1,sz,v) << "\n";}
	return 0;}

// look at my code
// my code is amazing