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
#define ull unsigned long long
#include <time.h>
// mylittlepony
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string S[3];
	char ch[300000+tisic];
	string W;
	for(int i =0; i < 3; i++) {
		scanf(" %s",ch);
		S[i] =(string)ch;
		W +=S[i];
		W +=('a'-1);}
	int N =W.length();

	vector< vector<int> > V1(256);
	V1[0].push_back(N);
	for(int i =0; i < N; i++) V1[W[i]].push_back(i);
	int K =5;
	while(1<<(K-1) < N) K++;
	vector<int> isB(N+1+(1<<(K-1)),0);
	vector<int> SA(N+1,N); // order of suffixes
	vector<int> Bs(N+2,N+1); // bucket start
	Bs[0] =0;
	int Btot =-1, q =0; // buckets total
	for(int j =0; j < 256; j++) {
		if(!V1[j].empty()) Bs[++Btot] =q;
		for(uint i =0; i < V1[j].size(); i++) {
			SA[q] =V1[j][i];
			isB[V1[j][i]] =Btot;
			q++;}
		}

	vector< pair<int,int> > tmp(N+1);
	vector<int> Bs1(N+1,0); // bucket size (tmp)
	vector<int> nxtB(N+1,0), pos(N+1,0);
	for(int i =1; i < K; i++) {
		int q =1<<(i-1);
		for(int j =0; j <= Btot; j++) Bs1[j] =0; 									// t=1
		for(int j =0; j <= N; j++) nxtB[j] =isB[SA[j]+q];							// t=12
		for(int j =0; j <= Btot; j++) if(Bs[j+1]-Bs[j] > 1) for(int k =Bs[j]; k < Bs[j+1]; k++) 
			Bs1[nxtB[k]]++;									// t=9
		// transform Bs1 to bucket start (tmp)
		int s =0;
		for(int j =0; j <= Btot; j++) {												// t=1
			int s2 =Bs1[j]+s;
			Bs1[j] =s;
			s =s2;}
		for(int j =0; j <= Btot; j++) if(Bs[j+1]-Bs[j] > 1) for(int k =Bs[j]; k < Bs[j+1]; k++) 			// t=22
			pos[k] =Bs1[nxtB[k]]++;
		for(int j =0; j <= Btot; j++) if(Bs[j+1]-Bs[j] > 1) for(int k =Bs[j]; k < Bs[j+1]; k++) {			// t=14
			tmp[pos[k]].ff =SA[k];
			tmp[pos[k]].ss =j;}
		for(int j =0; j < s; j++) pos[j] =Bs[tmp[j].ss]++;							// t=14
		for(int j =0; j < s; j++) SA[pos[j]] =tmp[j].ff;							// t=7
		for(int j =0; j <= N; j++) nxtB[j] =isB[SA[j]+q];							// t=11
		// split buckets
		Btot =0;
		Bs[0] =0;
		for(int j =1; j <= N; j++) {
			if(isB[SA[j]] != isB[SA[j-1]] || nxtB[j] != nxtB[j-1]) pos[j] =++Btot;	// t=14
			else pos[j] =pos[j-1];
		}
//		clock_t ta =clock();
		int p =0;
		for(int j =1; j <= N; j++) {												// t=19
			if(p+1 == pos[j]) Bs[++p] =j;
			isB[SA[j]] =p;}
//		clock_t tb =clock();
//		cout << i << " " << (int)(tb-ta) << endl;
		}

	vector<int> LCP(N+1,0);
	int L =0;
	for(int i =0; i < N; i++) {
		int k =SA[isB[i]-1];
		while(i+L < N && k+L < N && W[i+L] == W[k+L]) L++;
		LCP[isB[i]] =L;
		if(L > 0) L--;}

	vector<int> in_str(N+1,-1);
	int Sl[3];
	for(int i =0; i < 3; i++) Sl[i] =S[i].length();
	for(int i =0; i <= N; i++) {
		if(SA[i] <= Sl[0]) in_str[i] =0;
		else if(SA[i] <= Sl[0]+1+Sl[1]) in_str[i] =1;
		else if(SA[i] <= Sl[0]+Sl[1]+2+Sl[2]) in_str[i] =2;}
	for(int i =0; i <= N; i++) if(in_str[i] >= 0) {
		int l =in_str[i];
		for(int j =0; j <= in_str[i]; j++) l +=Sl[j];
		l -=SA[i];
		if(i < N) LCP[i+1] =min(LCP[i+1],l);
		LCP[i] =min(LCP[i],l);}

	vector< vector<int> > merge(N+1);
	for(int i =2; i <= N; i++) merge[LCP[i]].push_back(i);
	long long mod =1000000007, akt =0;
	set<int> I_st;
	vector< vector<int> > occ(N+1,vector<int>(3,0));
	for(int i =1; i <= N; i++) {
		occ[i][in_str[i]]++;
		I_st.insert(i);}

	int minL =N;
	for(int i =0; i < 3; i++) minL =min(minL,Sl[i]);
	vector<long long> ans(minL);
	for(int i =N; i > 0; i--) {
		ALL_THE(merge[i],it) {
			auto jt =I_st.lower_bound(*it);
			jt--;
			long long l1 =1, l2 =1, l3 =1;
			for(int k =0; k < 3; k++) {
				l1 =(l1*occ[*it][k])%mod;
				l2 =(l2*occ[*jt][k])%mod;
				occ[*jt][k] +=occ[*it][k];
				l3 =(l3*occ[*jt][k])%mod;}
			akt =(akt+l3-l1-l2)%mod;
			if(akt < 0) akt +=mod;
			I_st.erase(*it);}
		if(i-1 < minL) ans[i-1] =akt;}

	for(int i =0; i < minL; i++) printf("%lld\n",ans[i]);
	return 0;}

// look at my code
// my code is amazing