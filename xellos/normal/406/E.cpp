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
#define OVER9000 1034567890
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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	map<int,int> C[2];
	int T[] ={0,0};
	for(int i =0; i < M; i++) {
		int t,a;
		cin >> t >> a;
		T[t]++;
		C[t][a] +=1;}

	int ansV =0;
	long long ansP =0;

	// rovnaky typ
	for(int i =0; i < 2; i++) if(!C[i].empty()) {
		int a =2*(C[i].rbegin()->ff-C[i].begin()->ff);
		int x =C[i].begin()->ss, y =C[i].rbegin()->ss;
		long long p =0;
		if(a == 0) p =1LL*x*(x-1)*(x-2)/6;
		else p =x*(x-1)/2*y+y*(y-1)*x/2+x*y*(M-x-y);
		if(ansV < a) {
			ansV =a;
			ansP =0;}
		if(ansV == a) ansP +=p;}

	// rozne typy
	// da sa 2N?
	for(int i =0; i < 2; i++) if(!C[i].empty()) {
		int a =C[i].begin()->ff, b =C[i].rbegin()->ff;
		bool win =false;
		ALL_THE(C[1-i],it) if(it->ff >= a && it->ff <= b)
			win =true;

		if(!win) {
			auto it =C[1-i].lower_bound(b), jt =C[1-i].lower_bound(a);
			if(jt != C[1-i].begin()) {
				jt--;
				if(2*N-2*(a-jt->ff) > ansV) {
					ansV =2*N-2*(a-jt->ff);
					ansP =0;}
				if(2*N-2*(a-jt->ff) == ansV) {
					ansP +=1LL*(jt->ss)*(C[i].begin()->ss)*(C[i].begin()->ss-1)/2;
					ansP +=1LL*(jt->ss)*(C[i].begin()->ss)*(T[i]-C[i].begin()->ss);}
				}
			if(it != C[1-i].end()) {
				if(2*N-2*(it->ff-b) > ansV) {
					ansV =2*N-2*(it->ff-b);
					ansP =0;}
				if(2*N-2*(it->ff-b) == ansV) {
					ansP +=1LL*(it->ss)*(C[i].rbegin()->ss)*(C[i].rbegin()->ss-1)/2;
					ansP +=1LL*(it->ss)*(C[i].rbegin()->ss)*(T[i]-C[i].rbegin()->ss);}
				}
			}

		else {
			if(2*N > ansV) {
				ansV =2*N;
				ansP =0;}
			auto it =C[i].begin();
			int p =0;
			ALL_THE(C[1-i],jt) {
				while(it != C[i].end() && it->ff < jt->ff) {
					p +=it->ss;
					it++;}
				if(it != C[i].end() && it->ff == jt->ff)
					ansP +=(1LL*it->ss*(T[i]-p-it->ss)+1LL*it->ss*(it->ss-1)/2)*jt->ss;
				ansP +=1LL*p*(T[i]-p)*jt->ss;}
			}
		}

	cout << ansP << "\n";
	return 0;}

// look at my code
// my code is amazing