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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int M,N;
	cin >> M >> N;
	vector<int> X(N);
	for(int i =0; i < N; i++) {
		cin >> X[i];
		X[i]--;}
	if(N == 1) {cout << M-1 << "\n"; return 0;}
	vector<int> L(N);
	for(int i =0; i < N-1; i++) L[i] =X[i+1]-X[i]-1;
	L[N-1] =X[0]-1+M-X[N-1];
	int maxt =M, mint =-1;
	while(maxt-mint > 1) {
		int T =(maxt+mint)/2;
		bool ok =false;
		if(L[0]+1 <= T) for(int k =0; k < 2; k++) {
			int a =2, x =1+T+X[0], y =X[0]-1;
			if(k == 0) y =min(y,X[1]-T-1);
			else x =max(x,1+T+X[1]);
			while(a < N) {
				if(x >= X[a]) {
					x =max(x,X[a]+T+1);
					a++;
					continue;}
				int b =a;
				while(b < N && X[b]-T <= x) b++;
				if(b-a == 0) break;
				if(b-a >= 3) {
					x =X[b-1]+T+1;
					a =b;
					continue;}
				if(b-a == 2) {
					if(X[b-1] == X[a]+1) x =X[b-1]+T+1;
					else x =X[a]+T+1;}
				else {
					if(X[a] == x) x =X[a]+T+1;
					else x =X[a]+1;}
				a =b;}
			if(x-y-1 >= M) ok =true;}
		for(int k =0; k < 1; k++) {
			int a =1, x =1+T+X[0], y =X[0]-1;
			while(a < N) {
				if(x >= X[a]) {
					x =max(x,X[a]+T+1);
					a++;
					continue;}
				int b =a;
				while(b < N && X[b]-T <= x) b++;
				if(b-a == 0) break;
				if(b-a >= 3) {
					x =X[b-1]+T+1;
					a =b;
					continue;}
				if(b-a == 2) {
					if(X[b-1] == X[a]+1) x =X[b-1]+T+1;
					else x =X[a]+T+1;}
				else {
					if(X[a] == x) x =X[a]+T+1;
					else x =X[a]+1;}
				a =b;}
			if(x-y-1 >= M) ok =true;}
		if(L[N-1]+1 <= T) for(int k =0; k < 2; k++) {
			int a =1, x =1+X[0], y =X[0]-1-T;
			if(k == 0) y =X[N-1]-M-T-1;
			else x =1+T+X[N-1]-M;
			while(a < N-1) {
				if(x >= X[a]) {
					x =max(x,X[a]+T+1);
					a++;
					continue;}
				int b =a;
				while(b < N-1 && X[b]-T <= x) b++;
				if(b-a == 0) break;
				if(b-a >= 3) {
					x =X[b-1]+T+1;
					a =b;
					continue;}
				if(b-a == 2) {
					if(X[b-1] == X[a]+1) x =X[b-1]+T+1;
					else x =X[a]+T+1;}
				else {
					if(X[a] == x) x =X[a]+T+1;
					else x =X[a]+1;}
				a =b;}
			if(x-y-1 >= M) ok =true;}
		for(int k =0; k < 1; k++) {
			int a =1, x =1+X[0], y =X[0]-1-T;
			while(a < N) {
				if(x >= X[a]) {
					x =max(x,X[a]+T+1);
					a++;
					continue;}
				int b =a;
				while(b < N && X[b]-T <= x) b++;
				if(b-a == 0) break;
				if(b-a >= 3) {
					x =X[b-1]+T+1;
					a =b;
					continue;}
				if(b-a == 2) {
					if(X[b-1] == X[a]+1) x =X[b-1]+T+1;
					else x =X[a]+T+1;}
				else {
					if(X[a] == x) x =X[a]+T+1;
					else x =X[a]+1;}
				a =b;}
			if(x-y-1 >= M) ok =true;}
		if(ok) maxt =T;
		else mint =T;}
	cout << maxt << "\n";
	return 0;}

// look at my code
// my code is amazing