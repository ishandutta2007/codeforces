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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	string VC;
	int N,M;
	cin >> VC >> N >> M;
	int L =VC.length();
	vector< vector<int> > G(4*N,vector<int>(4*N,0));
	for(int i =0; i < M; i++) {
		int p1,p2;
		string t1,t2;
		cin >> p1 >> t1 >> p2 >> t2;
		int u =((t1 == "V")?0:1)*N+p1-1, v =((t2 == "V")?0:1)*N+p2-1;
		G[u][v] =1;
		G[2*N+v][2*N+u] =1;}
	for(int i =0; i < N; i++) for(int j =0; j < 2; j++) G[j*N+i][2*N+(1-j)*N+i] =1;
	for(int i =0; i < N; i++) for(int j =0; j < 2; j++) G[2*N+j*N+i][(1-j)*N+i] =1;

	vector< vector<bool> > reach(4*N,vector<bool>(4*N,0));
	for(int i =0; i < 4*N; i++) for(int j =0; j < 4*N; j++) 
		if(G[i][j]) reach[i][j] =true;
	for(int k =0; k < 4*N; k++)
		for(int i =0; i < 4*N; i++) for(int j =0; j < 4*N; j++) 
			if(reach[i][k] && reach[k][j]) reach[i][j] =true;

	string S;
	cin >> S;
	int min_let[2];
	for(int j =0; j < 2; j++) min_let[j] =L;
	for(int i =L-1; i >= 0; i--) {
		if(VC[i] == 'V') min_let[0] =i;
		else min_let[1] =i;}

	vector<int> st(2*N,-1);
	int id =0, id_opt =-1;
	while(id < N) {
		// prvych id rovnakych, potom vacsie, potom hocico
		bool okVC[2] ={true,true};
		vector<int> st2[2];
		for(int k =0; k < 2; k++) { // pos. id
			st2[k] =st;
			for(int j =0; j < 4*N; j++) if(reach[k*N+id][j]) {
				if(st2[k][j%(2*N)] == -1) {st2[k][j%(2*N)] =j/(2*N); continue;}
				if(st2[k][j%(2*N)] != j/(2*N)) okVC[k] =false;}
			}
		bool ok =false;
		for(int k =S[id]-'a'+1; k < L; k++) if(okVC[(VC[k] == 'V')?0:1]) ok =true;

		if(ok) id_opt =id;

		ok =true;
		for(int i =id; i < id+1; i++) {
			int x =(VC[S[i]-'a'] == 'V')?0:1;
			for(int j =0; j < 4*N; j++) if(reach[x*N+i][j]) {
				if(st[j%(2*N)] == -1) {st[j%(2*N)] =j/(2*N); continue;}
				if(st[j%(2*N)] != j/(2*N)) ok =false;}
			}
		if(!ok) break;
		id++;}

	if(id == N) {cout << S << "\n"; return 0;}
	if(id_opt == -1) {cout << "-1\n"; return 0;}

	id =0;
	st.clear();
	st.resize(2*N,-1);
	while(id < N) {
		// prvych id rovnakych, potom vacsie, potom hocico
		bool okVC[2] ={true,true};
		vector<int> st2[2];
		for(int k =0; k < 2; k++) { // pos. id
			st2[k] =st;
			for(int j =0; j < 4*N; j++) if(reach[k*N+id][j]) {
				if(st2[k][j%(2*N)] == -1) {st2[k][j%(2*N)] =j/(2*N); continue;}
				if(st2[k][j%(2*N)] != j/(2*N)) okVC[k] =false;}
			}
		bool ok =false;
		for(int k =S[id]-'a'+1; k < L; k++) if(okVC[(VC[k] == 'V')?0:1]) ok =true;

		if(id_opt == id) {
			string ans =S;
			vector<int> st3;
			for(int k =S[id]-'a'+1; k < L; k++) if(okVC[(VC[k] == 'V')?0:1]) {
				st3 =st2[(VC[k] == 'V')?0:1];
				ans[id] =k+'a';
				break;}
			int fs[2] ={0,1};
			if(min_let[1] < min_let[0]) swap(fs[0],fs[1]);
			for(int i =id+1; i < N; i++) for(int j =0; j < 2; j++) if(min_let[fs[j]] < L) {
				vector<int> st1 =st3;
				ok =true;
				for(int k =0; k < 4*N; k++) if(reach[fs[j]*N+i][k]) {
					if(st1[k%(2*N)] == -1) {st1[k%(2*N)] =k/(2*N); continue;}
					if(st1[k%(2*N)] != k/(2*N)) ok =false;}
				if(ok) {
					ans[i] =min_let[fs[j]]+'a';
					st3 =st1;
					break;}
				if(j == 1 && !ok) {cout << "-1\n"; return 0;}
				if(j == 0 && !ok && min_let[fs[1]] == L) {cout << "-1\n"; return 0;}
				}
			cout << ans << "\n";
			return 0;}

		ok =true;
		for(int i =id; i < id+1; i++) {
			int x =(VC[S[i]-'a'] == 'V')?0:1;
			for(int j =0; j < 4*N; j++) if(reach[x*N+i][j]) {
				if(st[j%(2*N)] == -1) {st[j%(2*N)] =j/(2*N); continue;}
				if(st[j%(2*N)] != j/(2*N)) ok =false;}
			}
		if(!ok) break;
		id++;}
	return 0;}

// look at my code
// my code is amazing