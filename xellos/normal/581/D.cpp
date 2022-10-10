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
	int L[3][2];
	for(int i =0; i < 3; i++) for(int j =0; j < 2; j++) scanf(" %d",&L[i][j]);

	int S =0;
	for(int i =0; i < 3; i++) S +=L[i][0]*L[i][1];
	int l =0;
	while(l*l < S) l++;
	if(l*l != S) {printf("-1\n"); return 0;}

	for(int a =0; a < 2; a++) {
		for(int b =0; b < 2; b++) {
			for(int c =0; c < 2; c++) {
				for(int k =0; k < 3; k++) if(L[k][1] == l) {
					int s =0;
					bool ok =true;
					for(int i =0; i < 3; i++) if(i != k) {
						if(L[i][0] != l-L[k][0]) ok =false;
						s +=L[i][1];} 
					if(!ok || s != l) continue;
					printf("%d\n",l);
					vector<string> V(l);
					for(int i =0; i < L[k][0]; i++) 
						for(int j =0; j < l; j++) V[i] +=('A'+k);
					for(int i =0; i < 3; i++) if(i != k)
						for(int j =0; j < l-L[k][0]; j++) 
							for(int n =0; n < L[i][1]; n++) V[j+L[k][0]] +=('A'+i);
					for(int i =0; i < l; i++) printf("%s\n",V[i].c_str());
					return 0;}
				if(L[0][1] == l && L[1][1] == l && L[2][1] == l) {
					printf("%d\n",l);
					vector<string> V;
					for(int k =0; k < 3; k++) for(int i =0; i < L[k][0]; i++) {
						string s;
						for(int j =0; j < l; j++) s +=('A'+k);
						V.push_back(s);}
					for(int i =0; i < l; i++) printf("%s\n",V[i].c_str());
					return 0;}
				swap(L[2][0],L[2][1]);}
			swap(L[1][0],L[1][1]);}
		swap(L[0][0],L[0][1]);}
	printf("-1\n");
	return 0;}

// look at my code
// my code is amazing