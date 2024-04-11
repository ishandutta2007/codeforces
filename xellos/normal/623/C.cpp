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
#include <time.h>
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
#define dbl long double
#define pi 3.14159265358979323846
#define pw2(x) ((x)*(x))
using namespace std;
// mylittledoge

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< pair<long long,long long> > P(N);
	for(int i =0; i < N; i++) cin >> P[i].ff >> P[i].ss;
	sort(begin(P),end(P));
	vector<long long> miL(N+1,1e9),mxL(N+1,-1e9),miR(N+1,1e9),mxR(N+1,-1e9);
	for(int i =0; i < N; i++) {
		miL[i+1] =min(miL[i],P[i].ss);
		mxL[i+1] =max(mxL[i],P[i].ss);}
	for(int i =N-1; i >= 0; i--) {
		miR[i] =min(miR[i+1],P[i].ss);
		mxR[i] =max(mxR[i+1],P[i].ss);}

	long long ans0 =min((P[N-1].ff-P[0].ff)*(P[N-1].ff-P[0].ff),(mxL[N]-miL[N])*(mxL[N]-miL[N]));

	long long ansA =-1, ansB =ans0;
	while(ansB-ansA > 1) {
		long long ansC =(ansA+ansB)/2;
		int a =0, b =0;
		bool ok =false;
		for(int i =0; i < N; i++) {
			while(pw2(P[i].ff-P[a].ff) > ansC) a++;
			while(P[i].ff > 0 && -P[b].ff > P[i].ff) b++;
			while(P[i].ff > 0 && b > 0 && -P[b-1].ff <= P[i].ff) b--;
			int c =max(a,b);
			long long miy =min(miL[c],miR[i+1]);
			long long mxy =max(mxL[c],mxR[i+1]);
			if(pw2(mxy-miy) <= ansC)
				if(pw2(max(abs(mxy),abs(miy)))+pw2(max(abs(P[i].ff),abs(P[c].ff))) <= ansC) {
					ok =true;
					break;}
			}
		a =b =N-1;
		if(!ok) for(int i =N-1; i >= 0; i--) {
			while(pw2(P[i].ff-P[a].ff) > ansC) a--;
			while(P[i].ff < 0 && P[b].ff > -P[i].ff) b--;
			while(P[i].ff < 0 && b < N-1 && P[b+1].ff <= -P[i].ff) b++;
			int c =min(a,b);
			long long miy =min(miR[c+1],miL[i]);
			long long mxy =max(mxR[c+1],mxL[i]);
			if(pw2(mxy-miy) <= ansC)
				if(pw2(max(abs(mxy),abs(miy)))+pw2(max(abs(P[i].ff),abs(P[c].ff))) <= ansC) {
					ok =true;
					break;}
			}
		if(ok) ansB =ansC;
		else ansA =ansC;}

	cout << ansB << "\n";
	return 0;}

// look at my code
// my code is amazing