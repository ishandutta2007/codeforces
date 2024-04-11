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
#define dbl long double
#define pi 3.14159265359
using namespace std;
// mylittledoge

struct query {
	int x1,y1,x2,y2,id;

	bool operator<(const query &Q) const {
		return x2 < Q.x2;}
	};

struct node {
	int z,k,val;
	int son[2];
	};

struct intervalac {
	vector<node> T;

	void constI(int akt) {
		node n =T[akt];
		if(n.k-n.z == 1) return;
		for(int i =0; i < 2; i++) {
			if(i == 0) n.k =(n.z+n.k)/2;
			else {n.z =n.k; n.k =T[akt].k;}
			T[akt].son[i] =T.size();
			T.push_back(n);
			constI(T.size()-1);}
		}

	intervalac(int N) {
		node n;
		n.son[0] =n.son[1] =-1;
		n.z =0, n.k =N;
		n.val =-1;
		T.dibs(2*N);
		T.push_back(n);
		constI(0);}

	void put(int akt, int pos, int val) {
		node n =T[akt];
		if(n.z == n.k-1) {
			T[akt].val =val;
			return;}
		if(T[n.son[0]].k > pos) put(n.son[0],pos,val);
		else put(n.son[1],pos,val);
		T[akt].val =min(T[n.son[0]].val,T[n.son[1]].val);}

	int get(int akt, int zac, int kon) { // poziciu s minimom
		node n =T[akt];
		if(n.k <= zac || kon <= n.z) return OVER9000;
		if(n.z == zac && n.k == kon) return n.val;
		return min(get(n.son[0],zac,min(kon,T[n.son[0]].k)),get(n.son[1],max(zac,T[n.son[1]].z),kon));}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M,K,Q;
	cin >> N >> M >> K >> Q;
	map<int,int> Mx,My;
	vector< pair<int,int> > R(K);
	for(int i =0; i < K; i++) {
		cin >> R[i].ff >> R[i].ss;
		Mx[R[i].ff] =My[R[i].ss] =0;}
	vector<query> queries(Q);
	for(int i =0; i < Q; i++) {
		cin >> queries[i].x1 >> queries[i].y1 >> queries[i].x2 >> queries[i].y2;
		Mx[queries[i].x1] =Mx[queries[i].x2] =0;
		My[queries[i].y1] =My[queries[i].y2] =0;
		queries[i].id =i;}
	vector<int> ans(Q,0);

	int mx =0, my =0;
	ALL_THE(Mx,it) it->ss =mx++;
	ALL_THE(My,it) it->ss =my++;
	for(int i =0; i < K; i++) {
		R[i].ff =Mx[R[i].ff];
		R[i].ss =My[R[i].ss];}
	for(int i =0; i < Q; i++) {
		queries[i].x1 =Mx[queries[i].x1];
		queries[i].x2 =Mx[queries[i].x2];
		queries[i].y1 =My[queries[i].y1];
		queries[i].y2 =My[queries[i].y2];}

	for(int k =0; k < 2; k++) {
		for(int i =0; i < K; i++) swap(R[i].ff,R[i].ss);
		for(int i =0; i < Q; i++) {
			swap(queries[i].x1,queries[i].y1);
			swap(queries[i].x2,queries[i].y2);}
		swap(mx,my);
		sort(begin(R),end(R));
		sort(begin(queries),end(queries));
		intervalac I(my+tisic);
		int a =0;
		for(int q =0; q < Q; q++) {
			while(a < K && R[a].ff <= queries[q].x2) {
				I.put(0,R[a].ss,R[a].ff);
				a++;}
			if(I.get(0,queries[q].y1,queries[q].y2+1) >= queries[q].x1) ans[queries[q].id]++;
			}
		}

	for(int i =0; i < Q; i++) cout << ((ans[i] > 0)?"YES":"NO") << ((i == Q-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing