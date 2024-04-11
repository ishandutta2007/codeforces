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
#define OVER9000 2234567890123456780LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.rbegin(); LIE != CAKE.rend(); LIE++)
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
	int N,M,a,b;
	cin >> N >> M;
	vector< set<int> > G(N),Gi(N);
	for(int i =0; i < M; i++) {
		cin >> a >> b;
		G[--a].insert(--b);
		Gi[b].insert(a);}

	vector<int> next(N,-1),prev(N,-1);
	int fr =0,bk =0;
	for(int k =1; k < N; k++) {
		if(G[fr].find(k) == G[fr].end()) {
			next[fr] =k;
			prev[k] =fr;
			fr =k;
			continue;}
		if(Gi[bk].find(k) == Gi[bk].end()) {
			prev[bk] =k;
			next[k] =bk;
			bk =k;
			continue;}
		int x =-1;
		ALL_THE(G[k],it) if(*it < k && G[k].find(next[*it]) == G[k].end())
			x =max(x,*it);
		ALL_THE(Gi[k],it) if(*it < k && Gi[k].find(prev[*it]) == Gi[k].end())
			x =max(x,prev[*it]);
		prev[next[x]] =k;
		next[k] =next[x];
		prev[k] =x;
		next[x] =k;}

	int akt =bk;
	cout << bk+1;
	for(int i =1; i < N; i++) {
		akt =next[akt];
		cout << " " << akt+1;}
	cout << "\n";
	return 0;}

// look at my code
// my code is amazing