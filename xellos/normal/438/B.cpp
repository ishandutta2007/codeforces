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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector< pair<int,int> > V(N);
	for(int i =0; i < N; i++) {
		cin >> V[i].ff;
		V[i].ss =i;}
	sort(V.begin(),V.end());
	vector<int> inv(N);
	for(int i =0; i < N; i++) inv[V[i].ss] =i;
	vector< vector<int> > G(N);
	for(int i =0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);}

	vector< vector<int> > C(N);
	vector<int> isC(N);
	for(int i =0; i < N; i++) {
		C[i].push_back(i);
		isC[i] =i;}

	long long ans =0;
	for(int i =N-1; i >= 0; i--) {
		int s =1, c =V[i].ss;
		set<int> Cs;
		ALL_THE(G[V[i].ss],it) if(inv[*it] > i) {
			Cs.insert(isC[*it]);
			if(C[isC[*it]].size() > s) {
				c =isC[*it];
				s =C[isC[*it]].size();}
			}
		int Sn =1;
		ALL_THE(Cs,it) Sn +=C[*it].size();
		ALL_THE(Cs,it) ans +=1LL*C[*it].size()*(Sn-C[*it].size())*V[i].ff;
		ans +=1LL*(Sn-1)*V[i].ff;
		if(V[i].ss != c) {
			C[c].push_back(V[i].ss);
			isC[V[i].ss] =c;}
		ALL_THE(G[V[i].ss],it) if(inv[*it] > i) {
			int c2 =isC[*it];
			if(c2 == c) continue;
			ALL_THE(C[c2],jt) {
				C[c].push_back(*jt);
				isC[*jt] =c;}}
		}

	cout << fixed << setprecision(10) << 1.0*ans/N/(N-1) << "\n";
	return 0;}

// look at my code
// my code is amazing