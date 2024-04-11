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
using namespace std;
// mylittledoge

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

struct fin {
	vector<long long> T;
	fin() {}
	fin(int N) {T.resize(N+tisic,0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, long long val) {
		for(int i =pos+1; i < (int)T.size(); i +=lastone(i)) T[i] +=val;
		}

	long long get(int pos) {
		long long ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
		return ret;}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,Q;
	scanf(" %d %d",&N,&Q);
	vector< vector<int> > G(N);
	for(int i =0; i < N-1; i++) {
		int a,b;
		scanf(" %d %d",&a,&b);
		G[--a].push_back(--b);
		G[b].push_back(a);}

	vector<int> dep(N,-1),br(N);
	map<int,int> to_br;
	queue<int> q;
	q.push(0);
	dep[0] =0;
	while(!q.empty()) {
		ALL_THE(G[q.front()],it) if(dep[*it] == -1) {
			if(q.front() == 0) {
				br[*it] =to_br.size();
				to_br[*it] =br[*it];}
			else br[*it] =br[q.front()];
			dep[*it] =dep[q.front()]+1;
			q.push(*it);}
		q.pop();}

	int B =to_br.size();
	fin F[B];
	fin Ft(N);
	vector<int> maxD(B);
	for(int i =1; i < N; i++) maxD[br[i]] =max(maxD[br[i]],dep[i]);
	for(int i =0; i < B; i++) F[i] =fin(maxD[i]);
	long long ans0 =0;

	for(int q =0; q < Q; q++) {
		int tp,v;
		scanf(" %d %d",&tp,&v);
		v--;
		if(tp == 1) {
			if(v == 0) printf("%lld\n",ans0);
			else printf("%lld\n",Ft.get(N-dep[v])+F[br[v]].get(maxD[br[v]]-dep[v]));
			continue;}
		int x,d;
		scanf(" %d %d",&x,&d);
		if(dep[v] <= d) ans0 +=x;
		int d2 =min(N,max(0,d-dep[v]));
		Ft.put(N-d2,x);
		if(maxD[br[v]] > d2) {
			F[br[v]].put(maxD[br[v]]-d2,-x);
			F[br[v]].put(max(0,maxD[br[v]]-dep[v]-d),x);
			if(dep[v] > d) F[br[v]].put(max(0,maxD[br[v]]-dep[v]+d+1),-x);}
		}
	return 0;}

// look at my code
// my code is amazing