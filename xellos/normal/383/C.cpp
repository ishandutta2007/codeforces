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
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

struct node {
	int z,k;
	int son[2];
	long long mod,val;};

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
			constI(T.size()-1);}
		}

	intervalac(int N) {
		node n;
		n.z =0, n.k =N;
		n.mod =n.val =0;
		n.son[0] =n.son[1] =-1;
		T.dibs(300000);
		T.push_back(n);
		constI(0);}

	void upd(int akt) {
		T[akt].val +=T[akt].mod;
		if(T[akt].son[0] == -1) {
			T[akt].mod =0;
			return;}
		for(int i =0; i < 2; i++) T[T[akt].son[i]].mod +=T[akt].mod;
		T[akt].mod =0;
		}

	void add(int akt, int zac, int kon, long long val) {
		node n =T[akt];
		if(n.z >= kon || n.k <= zac) return;
		if(n.z == zac && n.k == kon) {
			T[akt].mod +=val;
			return;}
		add(n.son[0],zac,min(kon,T[n.son[0]].k),val);
		add(n.son[1],max(zac,T[n.son[0]].k),kon,val);}

	long long get(int akt, int pos) {
		upd(akt);
		node n =T[akt];
		if(n.z == n.k-1) return n.val;
		if(T[n.son[0]].k > pos) return get(n.son[0],pos);
		else return get(n.son[1],pos);}
	};

void getI(int R, vector< vector<int> > &G, vector<int> &par, vector< pair<int,int> > &I) {
	ALL_THE(G[R],it) if(*it != par[R]) {
		I[*it] =make_pair(I[R].ss,I[R].ss+1);
		getI(*it,G,par,I);
		I[R].ss +=I[*it].ss-I[*it].ff;}
	}

int main() {
	cin.sync_with_stdio(0);
	int N,M;
	cin >> N >> M;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	vector< vector<int> > G(N);
	for(int i =1; i < N; i++) {
		int a,b;
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);}

	vector<int> par(N,-1);
	vector<int> dep(N,-1);
	par[0] =dep[0] =0;
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int a =q.front();
		ALL_THE(G[a],it) if(par[*it] == -1) {
			par[*it] =a;
			dep[*it] =dep[a]+1;
			q.push(*it);}
		q.pop();}

	vector< pair<int,int> > I(N);
	I[0] =make_pair(0,1);
	getI(0,G,par,I);

	intervalac Ie(N);
	intervalac Io(N);
	for(int i =0; i < N; i++) {
		if(dep[i]%2 == 0) Ie.add(0,I[i].ff,I[i].ff+1,A[i]);
		else Io.add(0,I[i].ff,I[i].ff+1,A[i]);}

	for(int i =0; i < M; i++) {
		int t,a,b;
		cin >> t >> a;
		a--;
		if(t == 2) {
			if(dep[a]%2 == 0) cout << Ie.get(0,I[a].ff) << "\n";
			else cout << Io.get(0,I[a].ff) << "\n";}
		else {
			cin >> b;
			if(dep[a]%2 == 0) {
				Ie.add(0,I[a].ff,I[a].ss,b);
				Io.add(0,I[a].ff,I[a].ss,-b);}
			else {
				Ie.add(0,I[a].ff,I[a].ss,-b);
				Io.add(0,I[a].ff,I[a].ss,b);}}
		}
	return 0;}

// look at my code
// my code is amazing