// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
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
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
#define ull unsigned long long
// mylittlepony
using namespace std;
using namespace std::tr1;

vector< vector<int> > SG;
// typ 0: pri okraji, 1: rovnake na okrajoch, 2: rozne na okrajoch

int countSG(int typ, int L) {
	if(SG[typ][L] >= 0) return SG[typ][L];
	vector<bool> go(500+tisic,true);
	if(typ == 0) {
		for(int x =0; x < L; x++) go[min(500,countSG(0,x)^countSG(1,L-1-x))] =false;
		for(int x =0; x < L-1; x++) go[min(500,countSG(0,x)^countSG(2,L-1-x))] =false;}
	if(typ == 1) {
		for(int x =0; x < L; x++) go[min(500,countSG(1,x)^countSG(1,L-x-1))] =false;
		for(int x =1; x < L-1; x++) go[min(500,countSG(2,x)^countSG(2,L-x-1))] =false;}
	if(typ == 2) 
		for(int x =0; x < L-1; x++) go[min(500,countSG(1,x)^countSG(2,L-x-1))] =false;
	for(int i =0; i < 500; i++) if(go[i]) {
		SG[typ][L] =i;
		return i;}
	SG[typ][L] =0;
	return 0;}

int main() {
	SG.resize(3, vector<int> (101,-1));
	
	int R,N,a,b;
	cin >> R >> N;
	vector<int> V(R,0);
	for(int i =0; i < N; i++) {
		cin >> a >> b;
		V[a-1] =b;}
	if(N == 0) {
		int ans =1;
		for(int i =0; i < R; i++) ans =min(ans,countSG(0,i)^countSG(0,R-1-i));
		if(ans != 0) cout << "LOSE\n";
		else cout << "WIN\n";
		return 0;}
	
	int ans =0;
	a =0;
	while(a < R) {
		if(V[a] > 0) {a++; continue;}
		b =a;
		while(b < R) {
			if(V[b] == 0) b++;
			else break;}
		if(a == 0 || b == R) {
			ans ^=countSG(0,b-a);
			a =b;
			continue;}
		if(V[a-1] == V[b]) ans ^=countSG(1,b-a);
		else ans ^=countSG(2,b-a);
		a =b;}
	if(ans == 0) cout << "LOSE\n";
	else cout << "WIN\n";
	return 0;}
        
// look at my code
// my code is amazing