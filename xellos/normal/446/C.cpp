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
#define OVER9000 1234567890123456780LL
#define patkan 9
#define tisic 47
#define soclose 1e-7
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittlepony
using namespace std;

long long mod =1000000009;

struct mat22 {
	long long M[2][2];

	mat22(int a) {M[0][0] =M[1][1] =1, M[0][1] =M[1][0] =0;}
	mat22() {M[0][0] =M[1][1] =0, M[0][1] =M[1][0] =0;}
	};

mat22 pw[500000];
mat22 Spw[500000];

struct node {
	int z,k;
	long long val,Aup,Bup;
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
		n.z =n.val =n.Aup =n.Bup =0, n.k =N;
		T.dibs(2*N+tisic);
		T.push_back(n);
		constI(0);}

	void upd(int akt) {
		node n =T[akt];
		if(n.Aup == 0 && n.Bup == 0) return;
		T[akt].val =(T[akt].val+Spw[n.k-n.z].M[1][0]*n.Bup+Spw[n.k-n.z].M[1][1]*n.Aup)%mod;
//		cout << n.Bup << " " << n.Aup << " " << n.k-n.z << " " << Spw[n.k-n.z].M[1][0] << " " << Spw[n.k-n.z].M[1][1] << "\n";
		if(n.son[0] != -1) {
			T[n.son[0]].Bup =(T[n.son[0]].Bup+n.Bup)%mod;
			if(T[n.son[0]].Bup < 0) T[n.son[0]].Bup +=mod;
			T[n.son[0]].Aup =(T[n.son[0]].Aup+n.Aup)%mod;
			if(T[n.son[0]].Aup < 0) T[n.son[0]].Aup +=mod;}
		if(n.son[1] != -1) {
			T[n.son[1]].Bup =(T[n.son[1]].Bup+pw[(n.k+n.z)/2-n.z].M[0][0]*n.Bup+pw[(n.k+n.z)/2-n.z].M[0][1]*n.Aup)%mod;
			if(T[n.son[1]].Bup < 0) T[n.son[1]].Bup +=mod;
			T[n.son[1]].Aup =(T[n.son[1]].Aup+pw[(n.k+n.z)/2-n.z].M[1][0]*n.Bup+pw[(n.k+n.z)/2-n.z].M[1][1]*n.Aup)%mod; // TODO
			if(T[n.son[1]].Aup < 0) T[n.son[1]].Aup +=mod;}
		T[akt].Aup =T[akt].Bup =0;}

	void put(int akt, int zac, int kon, long long a, long long b) {
		node n =T[akt];
		if(n.z >= kon || zac >= n.k) return;
		if(n.z == zac && n.k == kon) {
			T[akt].Aup =(T[akt].Aup+a)%mod;
			if(T[akt].Aup < 0) T[akt].Aup +=mod;
			T[akt].Bup =(T[akt].Bup+b)%mod;
			if(T[akt].Bup < 0) T[akt].Bup +=mod;
			return;}
		if(zac < T[n.son[0]].k) {
			put(n.son[0],zac,min(T[n.son[0]].k,kon),a,b);
			long long Bn =(pw[T[n.son[0]].k-zac].M[0][0]*b+pw[T[n.son[1]].z-zac].M[0][1]*a)%mod;
			if(Bn < 0) Bn +=mod;
			long long An =(pw[T[n.son[0]].k-zac].M[1][0]*b+pw[T[n.son[1]].z-zac].M[1][1]*a)%mod;
			if(An < 0) An +=mod;
			put(n.son[1],max(T[n.son[1]].z,zac),kon,An,Bn);}
		else put(n.son[1],max(T[n.son[1]].z,zac),kon,a,b);
		T[akt].val =(T[akt].val+Spw[kon-zac].M[1][0]*b+Spw[kon-zac].M[1][1]*a)%mod;
		} // TODO

	long long get(int akt, int zac, int kon) {
		node n =T[akt];
		if(n.k <= zac || kon <= n.z) return 0;
		upd(akt);
//		cout << zac << " " << kon << " " << n.z << " " << n.k << " " << T[akt].val << ".\n";
		if(n.z == zac && n.k == kon) return T[akt].val;
		return (get(n.son[0],zac,min(T[n.son[0]].k,kon))+get(n.son[1],max(T[n.son[1]].z,zac),kon))%mod;}
	};


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,Q;
	cin >> N >> Q;
	vector<int> A(N+1,0);
	for(int i =0; i < N; i++) cin >> A[i+1];
	for(int i =0; i < N; i++) A[i+1] =(A[i]+A[i+1])%mod;

	pw[0] =mat22(1);
	pw[1] =mat22(1); pw[1].M[0][1] =pw[1].M[1][0] =1, pw[1].M[1][1] =0;
	for(int i =2; i < 400000; i++) {
		for(int j =0; j < 2; j++) for(int k =0; k < 2; k++) {
			pw[i].M[j][k] =0;
			for(int l =0; l < 2; l++) pw[i].M[j][k] +=(pw[i-1].M[j][l]*pw[1].M[l][k])%mod;
			pw[i].M[j][k] %=mod;
			if(pw[i].M[j][k] < 0) pw[i].M[j][k] +=mod;}
		}

	Spw[0] =mat22();
	for(int i =1; i < 400000; i++) for(int j =0; j < 2; j++) for(int k =0; k < 2; k++) {
		Spw[i].M[j][k] =(Spw[i-1].M[j][k]+pw[i-1].M[j][k])%mod;
		if(Spw[i].M[j][k] < 0) Spw[i].M[j][k] +=mod;}

	intervalac I(N);

	for(int q =0; q < Q; q++) {
		int t,l,r;
		cin >> t >> l >> r;
		l--;
		if(t == 2) {
			long long ans =(A[r]-A[l]+I.get(0,l,r))%mod;
			if(ans < 0) ans +=mod;
			cout << ans << "\n";
			continue;}
		I.put(0,l,r,1,1);}
	return 0;}

// look at my code
// my code is amazing