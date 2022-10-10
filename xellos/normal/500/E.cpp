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
#define dibs reserve
#define OVER9000 223456789012345678LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

struct fin {
	vector<int> T;
	fin() {}
	fin(int N) {T.resize(N+1,0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] +=val;}

	int get(int pos) {
		int ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
		return ret;}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,Q;
	cin >> N;
	vector<int> X(N),D(N);
	map<int,int> P;
	vector<int> Pp;
	for(int i =0; i < N; i++) {
		cin >> X[i] >> D[i];
		P[X[i]] =0;
		P[X[i]+D[i]] =0;}
	int m =0;
	ALL_THE(P,it) {
		it->ss =m++;
		Pp.push_back(it->ff);}

	cin >> Q;
	vector< pair< pair<int,int>,int> > qu(Q);
	for(int i =0; i < Q; i++) {
		cin >> qu[i].ff.ff >> qu[i].ff.ss;
		qu[i].ff.ss--;
		qu[i].ff.ff--;
		qu[i].ss =i;}
	sort(qu.begin(),qu.end());
	vector<int> ans(Q);

	set<int> live;
	for(int i =0; i < m-1; i++) live.insert(i);
	int a =m-2, b =N-1;
	fin F(m-1);

	for(int q =Q-1; q >= 0; q--) {
		// pridaj segmenty
		while(a >= 0 && Pp[a] >= X[qu[q].ff.ff]) {
			F.put(a,Pp[a+1]-Pp[a]);
//			cout << Pp[a] << " " << Pp[a+1]-Pp[a] << "+\n";
			a--;}
		while(b >= qu[q].ff.ff) {
			// spadne domino, maz segmenty
			int x =X[b], y =X[b]+D[b];
			// maz segmenty so zaciatkom v [x,y)
			auto it =live.lower_bound(P[x]);
			while(it != live.end()) {
				if(Pp[*it] >= y) break;
				auto jt =it;
				it++;
				F.put(*jt,-(Pp[*jt+1]-Pp[*jt]));
//				cout << Pp[*jt] << " " << (Pp[*jt+1]-Pp[*jt]) << "-\n";
				live.erase(jt);}
			b--;}
		ans[qu[q].ss] =F.get(P[X[qu[q].ff.ss]]-1);}

	for(int i =0; i < Q; i++) cout << ans[i] << "\n";
	return 0;}

// look at my code
// my code is amazing