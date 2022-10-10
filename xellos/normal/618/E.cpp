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
#define soclose 1e-10
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

struct zc {
	dbl x,y;
	zc() {x =1; y =0;}
	};

zc prod(zc A, zc B) {
	zc ret;
	ret.x =A.x*B.x-A.y*B.y;
	ret.y =A.x*B.y+A.y*B.x;
	return ret;}

zc sum(zc A, zc B) {
	zc ret;
	ret.x =A.x+B.x;
	ret.y =A.y+B.y;
	return ret;}

struct node {
	int z,k;
	int son[2];
	bool mod;
	zc val,mul;
	};

struct intervalac {
	vector<node> T;

	void constI(int akt) {
		T[akt].val =T[akt].mul =zc();
		node n =T[akt];
		if(n.z == n.k-1) return;
		for(int i =0; i < 2; i++) {
			if(i == 0) n.k =(n.z+n.k)/2;
			else {n.z =n.k; n.k =T[akt].k;}
			T[akt].son[i] =T.size();
			T.push_back(n);
			constI(T.size()-1);}
		T[akt].val.x =T[akt].k-T[akt].z;
		}

	intervalac(int N) {
		T.resize(1);
		T[0].z =0;
		T[0].k =N;
		T[0].son[0] =T[0].son[1] =-1;
		T[0].mod =false;
		constI(0);}

	void upd(int akt) {
		if(!T[akt].mod) return;
		node n =T[akt];
		for(int i =0; i < 2; i++) if(n.son[i] != -1) {
			T[n.son[i]].mul =prod(T[n.son[i]].mul,n.mul);
			T[n.son[i]].mod =true;}
		T[akt].val =prod(T[akt].val,T[akt].mul);
		T[akt].mul =zc();
		T[akt].mod =false;}

	void put(int akt, int zac, int kon, zc val) {
		upd(akt);
		node n =T[akt];
		if(n.z >= kon || n.k <= zac) return;
		if(n.z == zac && n.k == kon) {
			T[akt].mul =prod(T[akt].mul,val);
			T[akt].mod =true;
			upd(akt);
			return;}
		put(n.son[0],zac,min(kon,(n.z+n.k)/2),val);
		put(n.son[1],max(zac,(n.z+n.k)/2),kon,val);
		T[akt].val =sum(get(n.son[0],n.z,(n.z+n.k)/2),get(n.son[1],(n.z+n.k)/2,n.k));
		}

	zc get(int akt, int zac, int kon) {
		upd(akt);
		node n =T[akt];
		if(n.z >= kon || n.k <= zac) {
			zc nul;
			nul.x =nul.y =0;
			return nul;}
		if(n.z == zac && n.k == kon) return n.val;
		return sum(get(n.son[0],zac,min(kon,(n.z+n.k)/2)),get(n.son[1],max(zac,(n.z+n.k)/2),kon));
		}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,M;
	cin >> N >> M;
	intervalac I(N);
	for(int i =0; i < M; i++) {
		int tp,y,z;
		cin >> tp >> y >> z;
		y--;
		if(tp == 1) {
			zc val =zc();
			zc a =I.get(0,y,y+1);
			dbl len =sqrt(a.x*a.x+a.y*a.y);
			val.x =(z+len)/len;
			I.put(0,y,y+1,val);}
		else {
			zc val =zc();
			val.x =cos(z/360.0*2*pi);
			val.y =-sin(z/360.0*2*pi);
			I.put(0,y,N,val);}
		zc ans =I.get(0,0,N);
		cout << ans.x << " " << ans.y << "\n";}
	return 0;}

// look at my code
// my code is amazing