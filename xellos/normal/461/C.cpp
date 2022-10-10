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
#define soclose 1e-6
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

struct node {
	int son[2];
	int sum,z,k;};

struct intervalac {
	vector<node> T;

	void constI(int akt) {
		node n =T[akt];
		T[akt].sum =n.k-n.z;
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
		n.z =0, n.k =N;
		T.dibs(2*N);
		T.push_back(n);
		constI(0);}

	int get(int akt, int zac, int kon) {
		node n =T[akt];
		if(n.z >= kon || zac >= n.k) return 0;
		if(n.z == zac && n.k == kon) return n.sum;
		return get(n.son[0],zac,min(kon,(n.z+n.k)/2))+get(n.son[1],max(zac,(n.z+n.k)/2),kon);}

	void put(int akt, int pos, int val) {
		node n =T[akt];
		T[akt].sum +=val;
		if(n.z == n.k-1) return;
		if((n.z+n.k)/2 > pos) put(n.son[0],pos,val);
		else put(n.son[1],pos,val);}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,Q;
	cin >> N >> Q;
	bool inv =false;
	int Z =0, K =N-1;
	intervalac I(N);
	for(int q =0; q < Q; q++) {
		int t; cin >> t;
		if(t == 2) {
			int L,R;
			cin >> L >> R;
//			cout << "." << K-R << " " << K-L << " " << Z << " " << K << "\n";
			if(!inv) cout << I.get(0,Z+L,Z+R) << "\n";
			else cout << I.get(0,K+1-R,K+1-L) << "\n";
			continue;}
		int P, L =K-Z+1;
		cin >> P;
		if(!inv) {
			if(P <= L-P) {
				for(int i =Z; i < Z+P; i++) I.put(0,Z+P+(Z+P-1-i),I.get(0,i,i+1));
				Z +=P;}
			else {
				P =L-P;
				for(int i =K; i > K-P; i--) I.put(0,(K-P)-(i-(K-P+1)),I.get(0,i,i+1));
				K -=P;
				inv =true;}
			}
		else {
			if(P <= L-P) {
				for(int i =K; i > K-P; i--) I.put(0,(K-P)-(i-(K-P+1)),I.get(0,i,i+1));
				K -=P;}
			else {
				P =L-P;
				for(int i =Z; i < Z+P; i++) I.put(0,Z+P+(Z+P-1-i),I.get(0,i,i+1));
				Z +=P;
				inv =false;}
			}
		}
	return 0;}

// look at my code
// my code is amazing