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
	int N,M,H;
	scanf(" %d %d %d",&N,&M,&H);
	vector<int> B(M),A(N);
	for(int i =0; i < M; i++) scanf(" %d",&B[i]);
	for(int i =0; i < N; i++) scanf(" %d",&A[i]);
	sort(begin(B),end(B));
	vector<int> minp0(N); // najmensi povoleny pocet pred nim
	for(int i =0; i < N; i++) {
		int a =-1, b =M;
		while(b-a > 1) {
			if(B[(b+a)/2]+A[i] >= H) b =(b+a)/2;
			else a =(b+a)/2;}
		minp0[i] =M-1-b;}

	int K =min(M-1,500);
	set< pair<int,int> > S;
	for(int i =0; i < M-1; i++) S.insert(make_pair(A[i],i));
	vector< pair<int, pair<int,int> > > V;
	int ans =0, next =M-1;
	for(int i =M-1; i < N; i++) {
		if(i == next) {
			int next2 =min(next+K,N);
			for(int j =i; j < next2; j++) S.insert(make_pair(A[j],j));
			int p =0, minp =N+tisic, x =-1;
			V.clear();
			ALL_THE(S,it) {
				if(it->ss >= i || it->ss < next2-M) {
					if(p > 0) V.push_back(make_pair(x,make_pair(minp,p)));
					V.push_back(make_pair(it->ss,make_pair(minp0[it->ss],1)));
					minp =N+tisic;
					p =0;
					x =-1;}
				else {
					if(x == -1) x =it->ss;
					minp =min(minp,minp0[it->ss]-p);
					p++;}
				}
			if(p > 0) V.push_back(make_pair(x,make_pair(minp,p)));
			for(int j =i; j < next2; j++) S.erase(make_pair(A[j],j));
			next =next2;}
		if(i >= M) S.erase(make_pair(A[i-M],i-M));
		S.insert(make_pair(A[i],i));
		bool ok =true;
		int p =0;
		ALL_THE(V,it) if(it->ff <= i && it->ff > i-M) {
			if(p > it->ss.ff) {ok =false; break;}
			p +=it->ss.ss;}
		if(ok) ans++;}

	printf("%d\n",ans);
	return 0;}

// look at my code
// my code is amazing