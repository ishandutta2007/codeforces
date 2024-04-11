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
#define soclose 1e-8
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
	vector< pair<int,int> > P(N);
	for(int i =0; i < N; i++) {
		int x,y;
		scanf(" %d %d",&x,&y);
		P[i].ff =x+y;
		P[i].ss =x-y;}
	sort(begin(P),end(P));

	vector<int> mx_lft(N+1,-2e9-tisic), mi_lft(N+1,2e9+tisic);
	for(int i =0; i < N; i++) {
		mx_lft[i+1] =max(mx_lft[i],P[i].ss);
		mi_lft[i+1] =min(mi_lft[i],P[i].ss);}
	vector<int> mx_rt(N+1,-2e9-tisic), mi_rt(N+1,2e9+tisic);
	for(int i =N-1; i >= 0; i--) {
		mx_rt[i] =max(mx_rt[i+1],P[i].ss);
		mi_rt[i] =min(mi_rt[i+1],P[i].ss);}

	dbl d_mi =0, d_mx =1e10;
	while(d_mx-d_mi > soclose) {
		int a =0;
		dbl d =(d_mi+d_mx)/2;
		bool ok =false;
		for(int i =0; i < N; i++) {
			while(a < i && P[a].ff < P[i].ff+soclose-d) a++;
			if(max(mx_rt[i+1],mx_lft[a])-min(mi_rt[i+1],mi_lft[a]) < d) ok =true;
			}
		if(ok) d_mx =d;
		else d_mi =d;}

	printf("%.10f\n",d_mx/2);
	return 0;}

// look at my code
// my code is amazing