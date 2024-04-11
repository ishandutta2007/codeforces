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
	int N;
	scanf(" %d",&N);
	vector<int> pr(N,4),live(4*N);
	vector< pair<int, pair<int,int> > > E(4*N);
	for(int i =0; i < 4*N; i++) {
		scanf(" %d %d %d",&E[i].ff,&E[i].ss.ff,&E[i].ss.ss);
		E[i].ff--;
		E[i].ss.ff--;
		E[i].ss.ss--;
		live[i] =i;}

	vector<int> seq;
	while(!live.empty()) {
		vector<int> live_nw;
		ALL_THE(live,it) {
			int pr1 =pr[E[*it].ss.ff]+1, pr2 =pr[E[*it].ss.ss]+1;
			if(E[*it].ff == E[*it].ss.ff) pr1--;
			if(E[*it].ss.ss == E[*it].ss.ff) pr1++;
			if(E[*it].ff == E[*it].ss.ss) pr2--;
			if(E[*it].ss.ss == E[*it].ss.ff) pr2++;
			if(pr1 <= 9 && pr2 <= 9) {
				pr[E[*it].ff]--;
				pr[E[*it].ss.ff]++;
				pr[E[*it].ss.ss]++;
				seq.push_back(*it);}
			else live_nw.push_back(*it);}
		live =live_nw;}

	printf("YES\n");
	ALL_THE(seq,it) printf("%d ",*it+1);
	printf("\n");
	return 0;}

// look at my code
// my code is amazing