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

long long pw(long long a, long long e, long long mod) {
	if(e <= 0) return 1;
	long long x =pw(a,e/2,mod);
	x =(x*x)%mod;
	if(x < 0) x +=mod;
	if(e%2 != 0) x =(x*a)%mod;
	if(x < 0) x +=mod;
	return x;}

int main() {
	long long mod =777777777;
	long long dmod[] ={9,7,37,333667};
	long long phi_dmod[] ={2*3,6,36,333666};
	long long inv_dmod[][4] ={
		{0,4,1,1}, // mod 9
		{4,0,4,3}, // mod 7
		{33,16,0,1}, // mod 37
		{296593,190667,324649,0}, // mod 333667
		};
	vector<long long> inv[4];
	for(int i =0; i < 4; i++) {
		inv[i].resize(dmod[i],1);
		for(int j =1; j < dmod[i]; j++) inv[i][j] =pw(j,phi_dmod[i]-1,dmod[i]);
		}

	int N,M;
	scanf(" %d %d",&N,&M);
	int W[3][3];
	for(int i =0; i < 9; i++) scanf(" %d",&W[i/3][i%3]);
	if(N == 1) {
		for(int i =0; i < M; i++) {
			int x,val;
			scanf(" %d %d",&x,&val);
			printf("%d\n",(val == 0)?3:1);}
		return 0;}

	vector<int> L[4][4][4];
	for(int p =0; p < 4; p++) {
		for(int i =0; i < 16; i++) L[p][i/4][i%4].resize(N+1,0);
		for(int i =1; i < 4; i++) {
			for(int j =1; j < 4; j++) if(W[i-1][j-1]) L[p][i][j][0] =1;
			for(int j =0; j < N; j++) for(int k =1; k < 4; k++) for(int l =1; l < 4; l++)
				if(W[k-1][l-1]) {
					L[p][i][l][j+1] +=L[p][i][k][j];
					if(L[p][i][l][j+1] >= dmod[p]) L[p][i][l][j+1] -=dmod[p];}
			}
		for(int i =1; i < 4; i++) L[p][0][i][0] =L[p][i][0][0] =1;
		for(int i =1; i < 4; i++) for(int j =1; j < 4; j++) for(int k =0; k < N; k++) {
			L[p][i][0][k+1] +=L[p][i][j][k];
			L[p][0][j][k+1] +=L[p][i][j][k];
			if(L[p][i][0][k+1] >= dmod[p]) L[p][i][0][k+1] -=dmod[p];
			if(L[p][0][j][k+1] >= dmod[p]) L[p][0][j][k+1] -=dmod[p];}
		for(int i =1; i < 4; i++) for(int j =2; j <= N; j++) {
			L[p][0][0][j] +=L[p][0][i][j-1];
			if(L[p][0][0][j] >= dmod[p]) L[p][0][0][j] -=dmod[p];}
		}
	long long ans[4];
	long long pz[4];
	for(int p =0; p < 4; p++) {
		pz[p] =0, ans[p] =1;
		if(p == 0) {
			if(L[p][0][0][N] == 0) pz[p] +=1000;
			else if(L[p][0][0][N]%3 == 0) ans[p] =L[p][0][0][N]/3, pz[p]++;
			else ans[p] =L[p][0][0][N];}
		else {
			if(L[p][0][0][N] == 0) pz[p] +=1000;
			else ans[p] =L[p][0][0][N];}
		}

	set< pair<int,int> > S;
	S.insert(make_pair(-1,N));
	vector<int> A(N,0);
	for(int q =0; q < M; q++) {
		int x,val;
		scanf(" %d %d",&x,&val);
		x--;
		vector< pair<int,int> > v;
		while(true) {
			auto it =S.lower_bound(make_pair(x+1,-1));
			if(it == S.begin()) break;
			it--;
			if(it->ss < x) break;
			v.push_back(*it);
			S.erase(it);}
		vector< pair<int,int> > v_nw;
		if(val == 0 && A[x] == 0) v_nw =v;
		else if(val > 0 && A[x] > 0) v_nw =v;
		else if(val == 0) {
			// merge
			int minp =N+1, maxp =-1;
			ALL_THE(v,it) minp =min(minp,it->ff);
			ALL_THE(v,it) maxp =max(maxp,it->ss);
			v_nw.push_back(make_pair(minp,maxp));}
		else {
			// split
			v_nw.push_back(make_pair(v[0].ff,x));
			v_nw.push_back(make_pair(x,v[0].ss));}
		for(int p =0; p < 4; p++) ALL_THE(v,it) {
			long long l =L[p][(it->ff < 0)?0:A[it->ff]][(it->ss == N)?0:A[it->ss]][it->ss-it->ff-1];
			if(p == 0) {
				if(l == 0) pz[p] -=1000;
				else if(l%3 == 0) ans[p] =(ans[p]*inv[p][l/3])%dmod[p], pz[p]--;
				else ans[p] =(ans[p]*inv[p][l])%dmod[p];}
			else {
				if(l == 0) pz[p] -=1000;
				else ans[p] =(ans[p]*inv[p][l])%dmod[p];}
			if(ans[p] < 0) ans[p] +=dmod[p];}
		A[x] =val;
		ALL_THE(v_nw,it) S.insert(*it);
		for(int p =0; p < 4; p++) ALL_THE(v_nw,it) {
			long long l =L[p][(it->ff < 0)?0:A[it->ff]][(it->ss == N)?0:A[it->ss]][it->ss-it->ff-1];
			if(p == 0) {
				if(l == 0) pz[p] +=1000;
				else if(l%3 == 0) ans[p] =(ans[p]*(l/3))%dmod[p], pz[p]++;
				else ans[p] =(ans[p]*l)%dmod[p];}
			else {
				if(l == 0) pz[p] +=1000;
				else ans[p] =(ans[p]*l)%dmod[p];}
			if(ans[p] < 0) ans[p] +=dmod[p];}
		long long ansF =0;
		for(int p =0; p < 4; p++) {
			long long r =ans[p];
			if(pz[p] == 1 && p == 0) r *=3;
			else if(pz[p] > 0) r =0;
			for(int k =0; k < 4; k++) if(k != p) {
				r =(r*dmod[k])%mod;
				if(r < 0) r +=mod;
				r =(r*inv_dmod[p][k])%mod;
				if(r < 0) r +=mod;}
			ansF +=r;}
		ansF %=mod;
		if(ansF < 0) ansF +=mod;
		printf("%I64d\n",ansF);}
	return 0;}

// look at my code
// my code is amazing