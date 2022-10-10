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

struct node {
	int z,k,ones;
	bool rev;
	int son[2];
};

struct intervalac {
	vector<node> T;

	void constI(int akt) {
		node n =T[akt];
		if(n.z == n.k-1) return;
		for(int i =0; i < 2; i++) {
			if(i == 0) n.k =(n.z+n.k)/2;
			else {n.z =n.k; n.k =T[akt].k;}
			T[akt].son[i] =T.size();
			T.push_back(n);
			constI(T[akt].son[i]);}
		}

	intervalac(int N) {
		node n;
		n.son[0] =n.son[1] =-1;
		n.z =n.ones =0, n.k =N;
		n.rev =false;
		T.resize(1,n);
		constI(0);}

	void upd(int akt) {
		node n =T[akt];
		if(!n.rev) return;
		for(int i =0; i < 2; i++) if(n.son[i] != -1) 
			T[n.son[i]].rev =!T[n.son[i]].rev;
		T[akt].ones =n.k-n.z-n.ones;
		T[akt].rev =false;}

	void rev(int akt, int zac, int kon) {
		upd(akt);
		node n =T[akt];
		if(n.z >= kon || zac >= n.k) return;
		if(n.z == zac && n.k == kon) {
			T[akt].rev =!T[akt].rev;
			upd(akt);
			return;}
		rev(n.son[0],zac,min(kon,(n.z+n.k)/2));
		rev(n.son[1],max(zac,(n.z+n.k)/2),kon);
		T[akt].ones =T[n.son[0]].ones+T[n.son[1]].ones;}

	int get(int akt, int zac, int kon) {
		upd(akt);
		node n =T[akt];
		if(n.z >= kon || zac >= n.k) return 0;
		if(n.z == zac && n.k == kon) return n.ones;
		return get(n.son[0],zac,min(kon,(n.z+n.k)/2))+get(n.son[1],max(zac,(n.z+n.k)/2),kon);}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	scanf(" %d",&N);
	vector< vector<int> > A(N,vector<int>(20,0));
	for(int i =0; i < N; i++) {
		int a;
		scanf(" %d",&a);
		for(int j =0; j < 20; j++) A[i][j] =(a>>j)&1;}

	vector<intervalac> I(20,intervalac(N));
	for(int i =0; i < N; i++) for(int j =0; j < 20; j++) 
		if(A[i][j]) I[j].rev(0,i,i+1);

	int Q;
	scanf(" %d",&Q);
	for(int q =0; q < Q; q++) {
		int tp,l,r;
		scanf(" %d %d %d",&tp,&l,&r);
		l--;
		if(tp == 1) {
			long long ans =0;
			for(int i =19; i >= 0; i--) ans =ans*2+I[i].get(0,l,r);
			printf("%lld\n",ans);
			continue;}
		int x;
		scanf(" %d",&x);
		for(int i =0; i < 20; i++) if((x>>i)&1) I[i].rev(0,l,r);
		}
	return 0;}

// look at my code
// my code is amazing