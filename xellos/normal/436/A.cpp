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
	cin.tie(0);
	cin.sync_with_stdio(0);
	int N,x;
	cin >> N >> x;
	vector< pair<int,int> > A[2];
	for(int i =0; i < N; i++) {
		int t,x,y;
		cin >> t >> x >> y;
		A[t].push_back(make_pair(x,y));}
	sort(A[0].begin(),A[0].end());
	sort(A[1].begin(),A[1].end());

	int ans =0;
	for(int k =0; k < 2; k++) {
		int X =x, b =0;
		int akt =0;
		vector<bool> E[2];
		for(int i =0; i < 2; i++) E[i].resize(A[i].size(),false);
		while(true) {
			int m =0,a =-1;
			for(int i =0; i < A[b].size(); i++)
				if(!E[b][i] && X >= A[b][i].ff && m < A[b][i].ss) {
					m =A[b][i].ss;
					a =i;}
			if(a == -1) break;
			E[b][a] =true;
			akt++;
			X +=A[b][a].ss;
			b =1-b;}
		ans =max(ans,akt);
		swap(A[0],A[1]);}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing