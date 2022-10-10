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
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define dbl double
// mylittlepony
using namespace std;

struct rec {
	int l,r;
	dbl p;
	
	bool operator<(const rec &R) const {
		if(r-l != R.r-R.l) return r-l < R.r-R.l;
		return r < R.r;}
	};

int main() {
    int N,Q;
    scanf(" %d %d",&N,&Q);
    vector<int> E(N);
    dbl ansT =0;
    for(int i =0; i < N; i++) {
    	scanf(" %d",&E[i]);
    	ansT =max(ansT,(dbl)E[i]);}
    vector<rec> R(Q+1);
    for(int i =0; i < Q; i++) {
    	scanf(" %d %d %lf",&R[i].l,&R[i].r,&R[i].p);}
    R[Q].l =1; R[Q].r =N; R[Q].p =0;
    Q++;
    vector<int> mAns(Q,0),maxAns(Q,0);
    vector< vector<dbl> > P(Q,vector<dbl>(Q+1,0));
    sort(R.begin(),R.end());
    set<int> U;
    for(int i =0; i < N; i++) U.insert(i);
    vector<bool> hasP(Q,false);
    
    for(int i =0; i < Q; i++) {
    	R[i].l--; R[i].r--;
    	while(true) {
    		auto it =U.lower_bound(R[i].l);
    		if(it == U.end() || *it > R[i].r) break;
    		mAns[i] =max(mAns[i],E[*it]);
    		U.erase(it);}
    	maxAns[i] =mAns[i];
    	vector<int> G;
    	for(int j =0; j < i; j++) if(!hasP[j] && R[j].l >= R[i].l && R[j].r <= R[i].r) {
    		mAns[i] =max(mAns[i],mAns[j]);
    		maxAns[i] =max(maxAns[i],maxAns[j]);
    		hasP[j] =true;
			G.push_back(j);}
		// P[k]: prav. ze bude odpoved min+k
		// l[i]+min[i]+(0/1) == min+k
		// prod(sum<=l[i](p[i][j]))
		vector<dbl> T(Q+1,1);
		ALL_THE(G,it) {
			dbl p =0;
			for(int j =0; j <= Q; j++) {
				p +=P[*it][j];
				int x =j+mAns[*it]-mAns[i];
				if(x >= 0) T[x] *=p;}
			}
		// od 0 po maxAns sa daju
		for(int j =0; j <= maxAns[i]-mAns[i]; j++) {
			P[i][j] +=(1-R[i].p)*((j == 0)?T[j]:(T[j]-T[j-1]));
			P[i][j+1] +=R[i].p*((j == 0)?T[j]:(T[j]-T[j-1]));}
		maxAns[i]++;
		dbl akt =0;
		for(int j =0; j <= Q; j++) akt +=(j+mAns[i])*P[i][j];
		ansT =max(ansT,akt);}
	
	printf("%.10lf\n",ansT);
    return 0;}
        
// look at my code
// my code is amazing