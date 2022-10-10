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
#define OVER9000 1234567890123456789LL
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
	int N,K,Q;
	long long A,B;
	scanf(" %d %d %lld %lld %d",&N,&K,&A,&B,&Q);
	vector<long long> ord(N,0);
	fin F1(N),F2(N);
	for(int q =0; q < Q; q++) {
		int tp;
		scanf(" %d",&tp);
		if(tp == 2) {
			int p;
			scanf(" %d",&p);
			p--;
			printf("%lld\n",F1.get(p-1)+F2.get(N-(p+K)));
			continue;}
		int d,a;
		scanf(" %d %d",&d,&a);
		d--;
		F1.put(d,-min(B,ord[d]));
		F2.put(N-d,-min(A,ord[d]));
		ord[d] +=a;
		F1.put(d,min(B,ord[d]));
		F2.put(N-d,min(A,ord[d]));}
	return 0;}

// look at my code
// my code is amazing