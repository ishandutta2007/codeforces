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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];

	if(A[N-1] == 1) {
		cout << "NO\n"; 
		return 0;}
	if(N == 1) {
		cout << "YES\n0\n";
		return 0;}

	int fZ =N-1;
	for(int i =0; i < N; i++) if(A[i] == 0) {
		fZ =i;
		break;}

	if(fZ == N-2) {
		cout << "NO\n";
		return 0;}
	if(fZ == N-1) {
		cout << "YES\n";
		for(int i =0; i < N; i++) cout << A[i] << ((i == N-1)?"\n":"->");
		return 0;}

	cout << "YES\n";
	for(int i =0; i < fZ; i++) cout << "1->";
	cout << "(0->(";
	for(int i =fZ+1; i < N-1; i++) cout << A[i] << (i < N-2?"->":")");
	cout << ")->0\n";
	return 0;}

// look at my code
// my code is amazing