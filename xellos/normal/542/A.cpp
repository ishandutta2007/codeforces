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

struct fin {
	vector<int> T;
	fin(int N) {T.resize(N+tisic,0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] =max(T[i],val);
		}

	int get(int pos) {
		int ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret =max(ret,T[i]);
		return ret;}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector< pair< pair<int,int>,int> > A(N);
	for(int i =0; i < N; i++) {cin >> A[i].ff.ss >> A[i].ff.ff; A[i].ss =i;}
	vector< pair< pair<int,int>,int> > B(M);
	vector<long long> C(M);
	for(int i =0; i < M; i++) {cin >> B[i].ff.ss >> B[i].ff.ff >> C[i]; B[i].ss =i;}
	sort(begin(A),end(A));
	sort(begin(B),end(B));
	for(int i =0; i < N; i++) swap(A[i].ff.ff,A[i].ff.ss);
	for(int i =0; i < M; i++) swap(B[i].ff.ff,B[i].ff.ss);

	map<int,int> mp;
	for(int i =0; i < M; i++) mp[B[i].ff.ff] =mp[B[i].ff.ss] =0;
	for(int i =0; i < N; i++) mp[A[i].ff.ff] =mp[A[i].ff.ss] =0;
	int m =0;
	ALL_THE(mp,it) it->ss =m++;

	long long ans =0;
	int a =0, ansA =-1, ansB =-1;
	set< pair<int,int> > right;
	set< pair<int,int> > rightS;
	for(int i =0; i < N; i++) {
		right.insert(make_pair(A[i].ff.ss,i));
		rightS.insert(make_pair(A[i].ff.ff,i));}
	fin Fin(m),Fleft(m);
	for(int i =0; i < M; i++) {
		while(a < N && A[a].ff.ss <= B[i].ff.ss) {
			rightS.erase(make_pair(A[a].ff.ff,a));
			right.erase(make_pair(A[a].ff.ss,a));
			Fin.put(m-mp[A[a].ff.ff],A[a].ff.ss-A[a].ff.ff);
			Fleft.put(mp[A[a].ff.ff],A[a].ff.ss);
			a++;}
		// vnutri
		long long akt =C[B[i].ss]*Fin.get(m-mp[B[i].ff.ff]);
		if(akt > ans) {ans =akt; ansA =-1; ansB =i;}
		// nad zlava
		akt =C[B[i].ss]*(Fleft.get(mp[B[i].ff.ff])-B[i].ff.ff);
		if(akt > ans) {ans =akt; ansA =-1; ansB =i;}
		// nad sprava
		// uplne nad
		if(!rightS.empty()) {
			auto it =rightS.begin();
			akt =C[B[i].ss]*(B[i].ff.ss-max(B[i].ff.ff,it->ff));
			if(akt > ans) {ans =akt; ansA =A[it->ss].ss; ansB =B[i].ss;}
			}
		}

	cout << ans << "\n";
	if(ans == 0) return 0;
	if(ansA == -1) {
		for(int i =0; i < N; i++) if(A[i].ff.ss <= B[ansB].ff.ss) {
			long long akt =C[B[ansB].ss]*(A[i].ff.ss-max(A[i].ff.ff,B[ansB].ff.ff));
			if(akt == ans) ansA =A[i].ss;}
		ansB =B[ansB].ss;}
	cout << ansA+1 << " " << ansB+1 << "\n";
	return 0;}

// look at my code
// my code is amazing