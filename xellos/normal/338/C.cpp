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
#define OVER9000 1234567890123456789LL
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
	vector<long long> A(N);
	for(int i =0; i < N; i++) scanf(" %I64d",&A[i]);
	sort(begin(A),end(A));
	N =(unique(begin(A),end(A))-begin(A));

	vector<int> ans(1<<N,10000000);
	vector< map<long long,int> > P(N);
	for(int i =0; i < N; i++) {
		long long a =A[i];
		for(long long j =2; j*j <= a; j++) while(a%j == 0) {
			P[i][j]++;
			a /=j;}
		if(a > 1) P[i][a]++;}

	for(int i =1; i < (1<<N); i++) {
		int mx =0, M =0;
		vector<int> v;
		for(int j =0; j < N; j++) if((i>>j)&1) {
			mx =j;
			M++;
			v.push_back(j);}
		bool ok =true;
		for(int j =0; j < N; j++) if((i>>j)&1) 
			if(A[mx]%A[j] != 0) ok =false;
		if(!ok) continue;
		if(P[mx].size() == 1 && P[mx].begin()->ss == 1 && i == (1<<mx)) {
			ans[i] =1;
			continue;}
		vector<int> comp(1<<M,0),compI(1<<N);
		for(int j =0; j < (1<<N); j++) if((i&j) == j) {
			int x =0;
			for(int k =0; k < M; k++) if((j>>v[k])&1) x +=(1<<k);
			compI[j] =x;
			comp[x] =j;}
		vector< vector<long long> > ans0(1<<M,vector<long long>(1<<M,10000000));
		ans0[0][1<<(M-1)] =1;
		for(int j =0; j < (1<<M); j++) for(int k =0; k < (1<<M); k++) if((j&k) == j && ans0[j][k] < 10000000) {
			for(int l =1; l < (1<<M); l++) if((k&l) == 0) {
				int mx_akt =0;
				for(int m =0; m < M; m++) if((l>>m)&1) mx_akt =m;
				ans0[j|(1<<mx_akt)][l|k] =min(ans0[j|(1<<mx_akt)][l|k],ans0[j][k]+ans[comp[l]]);}
			if(k == (1<<M)-1) {
				map<long long,int> p =P[mx];
				for(int l =0; l < M; l++) if((j>>l)&1)
					ALL_THE(P[v[l]],it) p[it->ff] -=it->ss;
				bool ok =true;
				int s =ans0[j][k];
				ALL_THE(p,it) {
					if(it->ss < 0) ok =false;
					s +=it->ss;}
				if(ok) ans[i] =min(ans[i],s);}
			}
		}

	int ans0 =ans[(1<<N)-1];
	for(int i =1; i < (1<<N); i++) for(int j =1; j < (1<<N); j++) if((i&j) == 0)
		ans[i|j] =min(ans[i|j],ans[i]+ans[j]);
	printf("%d\n",min(ans0,ans[(1<<N)-1]+1));
	return 0;}

// look at my code
// my code is amazing