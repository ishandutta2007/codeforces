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
	int N,S;
	scanf(" %d %d",&N,&S);
	vector< pair<int,int> > A(N);
	for(int i =0; i < N; i++) {
		scanf(" %d",&A[i].ff);
		A[i].ss =i;}
	sort(begin(A),end(A));
	if(A[N-1].ff > S) {printf("-1\n"); return 0;}

	int K =10;
	vector< vector<uint> > intm((N-1)/K+2,vector<uint>(S/32+tisic,0));
	vector<uint> pos(S/K+tisic,0);
	pos[0] =1;
	intm[0] =pos;
	for(int i =0; i < N-1; i++) {
		for(int j =(S-A[i].ff)/32; j >= 0; j--) if(pos[j] > 0) {
			if(A[i].ff%32 > 0) pos[j+A[i].ff/32+1] |=pos[j]>>(32-A[i].ff%32);
			pos[j+A[i].ff/32] |=pos[j]<<(A[i].ff%32);}
		if((i+1)%K == 0) intm[(i+1)/K] =pos;}
	intm[(N-1)/K+1] =pos;

	if(((pos[(S-A[N-1].ff)/32]>>((S-A[N-1].ff)%32))&1) == 0) {printf("-1\n"); return 0;}
	int akt =S-A[N-1].ff;
	vector<bool> top(N,false);
	top[N-1] =true;
	for(int i =(N-1)/K; i >= 0; i--) {
		if((intm[i][akt/32]>>(akt%32))&1) continue;
		vector<int> v;
		for(int j =i*K; j < min(N-1,i*K+K); j++) v.push_back(A[j].ff);
		int m =v.size(), b =0;
		vector<int> sum(1<<m,0);
		for(int j =0; j < (1<<(m-1)); j++) {
			while((1<<b) <= j) b++;
			for(int k =b; k < m; k++) sum[j|(1<<k)] =sum[j]+v[k];}
		for(int j =0; j < (1<<m); j++) if(sum[j] <= akt && (intm[i][(akt-sum[j])/32]>>((akt-sum[j])%32))&1) {
			for(int k =0; k < m; k++) if((j>>k)&1) top[i*K+k] =true;
			akt -=sum[j];
			break;}
		}

	int lastC =0, lastB =-1;
	vector<int> C(N);
	vector<int> son(N,-1);
	for(int i =0; i < N; i++) {
		if(top[i] && i < N-1) C[A[i].ss] =A[i].ff;
		else {
			son[A[i].ss] =lastB;
			C[A[i].ss] =A[i].ff-lastC;
			lastC =A[i].ff, lastB =A[i].ss;}
		}

	for(int i =0; i < N; i++) {
		printf("%d %d",C[i],(son[i] != -1));
		if(son[i] != -1) printf(" %d\n",son[i]+1);
		else printf("\n");}
	return 0;}

// look at my code
// my code is amazing