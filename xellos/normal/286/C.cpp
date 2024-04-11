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
	int N;
	scanf(" %d",&N);
	vector<int> A(N);
	for(int i =0; i < N; i++) scanf(" %d",&A[i]);
	vector<bool> neg(N,false);
	int Q;
	scanf(" %d",&Q);
	for(int i =0; i < Q; i++) {
		int a;
		scanf(" %d",&a);
		neg[--a] =true;}
	if(neg[0]) {cout << "NO\n"; return 0;}

	vector<int> next(N,-1),prev(N,-1);
	for(int i =1; i < N; i++) next[i-1] =i, prev[i] =i-1;
	set<int> iden;
	vector<bool> used(N,false);

	for(int i =1; i < N; i++) {
		if(A[prev[i]] == A[i]) iden.insert(i);
		if(neg[i]) while(true) {
			if(iden.empty()) {cout << "NO\n"; return 0;}
			int x =*iden.rbegin();
			iden.erase(--iden.end());
			if(prev[x] == -1) {cout << "NO\n"; return 0;}
			iden.erase(prev[x]);
			bool fin =(x == i);
			neg[x] =true;
			used[prev[x]] =used[x] =true;
			int y =prev[prev[x]]; // spoj y, next[x]
			if(next[x] != -1) prev[next[x]] =y;
			if(y != -1) next[y] =next[x];
			if(next[x] != -1 && y != -1 && A[y] == A[next[x]] && next[x] <= i) iden.insert(next[x]);
			if(fin) break;}
		}

	int last =N-1;
	while(last >= 0) {
		if(used[last]) {last--; continue;}
		neg[last] =true;
		while(true) {
			if(iden.empty()) {cout << "NO\n"; return 0;}
			int x =*iden.rbegin();
			iden.erase(--iden.end());
			if(prev[x] == -1) {cout << "NO\n"; return 0;}
			iden.erase(prev[x]);
			bool fin =(x == last);
			neg[x] =true;
			used[prev[x]] =used[x] =true;
			int y =prev[prev[x]]; // spoj y, next[x]
			if(next[x] != -1) prev[next[x]] =y;
			if(y != -1) next[y] =next[x];
			if(next[x] != -1 && y != -1 && A[y] == A[next[x]] && next[x] <= last) iden.insert(next[x]);
			if(fin) break;}
		}

	cout << "YES\n";
	for(int i =0; i < N; i++) cout << (neg[i]?-A[i]:A[i]) << ((i == N-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing