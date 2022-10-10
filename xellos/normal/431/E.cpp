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
#define OVER9000 1034567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
// mylittlepony
using namespace std;

struct query {
	long long V;
	int type,p;
	};

struct fin {
	vector<long long> T;
	fin(int N) {T.resize(N+tisic,0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, long long val) {
		if(pos < 0) return;
		for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] +=val;}

	long long get(int pos) {
		long long ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
		return ret;}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,Q;
	cin >> N >> Q;

	vector<long long> H(N);
	vector<query> qu(Q);
	map<int,int> M;
	for(int i =0; i < N; i++) {
		cin >> H[i];
		M[H[i]] =0;}
	for(int i =0; i < Q; i++) {
		cin >> qu[i].type;
		if(qu[i].type == 1) {
			cin >> qu[i].p >> qu[i].V;
			qu[i].p--;
			M[qu[i].V] =0;}
		else cin >> qu[i].V;}

	int m =0;
	ALL_THE(M,it) it->ss =m++;
	vector<int> hts;
	ALL_THE(M,it) hts.push_back(it->ff);

	fin F(m),F2(m);
	for(int i =0; i < N; i++) F.put(M[H[i]],H[i]), F2.put(M[H[i]],1);

	for(int i =0; i < Q; i++) {
		if(qu[i].type == 1) {
			F.put(M[H[qu[i].p]],-H[qu[i].p]);
			F2.put(M[H[qu[i].p]],-1);
			H[qu[i].p] =qu[i].V;
 			F.put(M[H[qu[i].p]],H[qu[i].p]);
 			F2.put(M[H[qu[i].p]],1);
			continue;}
		int pA =-1, pB =m+3;
		dbl ans =1e18;
		while(pB-pA > 1) {
			int pC =(pA+pB)/2;
			long long s =F.get(pC-1), poc =F2.get(pC-1);
			ans =min(ans,1.0L*(qu[i].V+s)/poc);
			if(pC == m || hts[pC]*poc > qu[i].V+s) pB =pC;
			else pA =pC;}
		cout << fixed << setprecision(10) << ans << "\n";}
	return 0;}

// look at my code
// my code is amazing