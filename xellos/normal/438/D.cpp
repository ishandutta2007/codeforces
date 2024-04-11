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
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-3
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

struct fin {
	vector<long long> T;
	fin(int N) {T.resize(N+tisic,0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, long long val) {
		for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] +=val;}

	long long get(int pos) {
		long long ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
		return ret;}
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
		T[akt].val =max(T[n.son[0]].val,T[n.son[1]].val);}

	pair<int,int> get(int akt, int zac, int kon) { // poziciu s maximom
		node n =T[akt];
		if(n.k <= zac || kon <= n.z) return make_pair(-1,zac);
		if(n.z == n.k-1) return make_pair(n.val,n.z);
		if(n.z == zac && n.k == kon) {
			if(T[n.son[0]].val > T[n.son[1]].val) return get(n.son[0],zac,(zac+kon)/2);
			else return get(n.son[1],(zac+kon)/2,kon);}
		pair<int,int> p =get(n.son[0],zac,min(kon,T[n.son[0]].k));
		pair<int,int> r =get(n.son[1],max(zac,T[n.son[1]].z),kon);
		if(p.ff < r.ff) return r;
		else return p;}
	};


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	fin F(N);
	intervalac I(N);
	vector<long long> A(N);
	for(int i =0; i < N; i++) {
		cin >> A[i];
		F.put(i,A[i]);
		I.put(0,i,A[i]);}

	for(int i =0; i < M; i++) {
		int t;
		cin >> t;
		if(t == 1) {
			int l,r;
			cin >> l >> r;
			cout << F.get(r-1)-F.get(l-2) << "\n";
			continue;}
		if(t == 3) {
			int k,x;
			cin >> k >> x;
			k--;
			F.put(k,x-A[k]);
			A[k] =x;
			I.put(0,k,x);
			continue;}
		int l,r,m;
		cin >> l >> r >> m;
		l--;
		// [l,r)
		while(true) {
			pair<int,int> p =I.get(0,l,r);
			if(p.ff < m) break;
			p.ff %=m; if(p.ff < 0) p.ff +=m;
			I.put(0,p.ss,p.ff);
			F.put(p.ss,p.ff-A[p.ss]);
			A[p.ss] =p.ff;}
		}
	return 0;}

// look at my code
// my code is amazing