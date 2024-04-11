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

struct fin {
	vector<int> T;
	fin(int N) {T.resize(N+tisic,0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i =pos+1; i < (int)T.size(); i +=lastone(i)) T[i] =max(T[i],val);}

	int get(int pos) {
		int ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret =max(ret,T[i]);
		return ret;}
	};

int main() {
	int K,N,maxB,T;
	scanf(" %d %d %d %d",&K,&N,&maxB,&T);
	fin F(maxB);
	for(int k =0; k < K; k++) {
		vector<int> B(N);
		for(int i =0; i < N; i++) scanf(" %d",&B[i]);
		vector<int> ans(maxB+1,0);
		int last_full =0;
		for(int j =0; j < min(T,min(N,maxB)); j++) for(int i =0; i < N; i++) if(B[i] > last_full) {
			int x =F.get(B[i]-1)+1;
			if(x > ans[B[i]]) {
				ans[B[i]] =x;
				F.put(B[i],x);}
			while(last_full < maxB && ans[last_full+1] == last_full+1) last_full++;
			if(last_full == maxB) break;}
		int ansF =0;
		for(int i =0; i <= maxB; i++) ansF =max(ansF,ans[i]);
		printf("%d\n",ansF);
		F =fin(maxB);}
	return 0;}

// look at my code
// my code is amazing