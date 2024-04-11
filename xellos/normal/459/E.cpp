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
	int N,M;
	cin >> N >> M;
	map<int, vector< pair<int,int> > > E;
	for(int i =0; i < M; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		a--, b--;
		E[c].push_back(make_pair(a,b));}

	vector<int> ans(N,0);
	ALL_THE(E,it) {
		set< pair<int,int> > S;
		ALL_THE(it->ss,jt)
			S.insert(make_pair(jt->ss,ans[jt->ff]+1));
		ALL_THE(S,jt) ans[jt->ff] =max(ans[jt->ff],jt->ss);}

	int A =0;
	for(int i =0; i < N; i++) A =max(A,ans[i]);
	cout << A << "\n";
	return 0;}

// look at my code
// my code is amazing