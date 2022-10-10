// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456789LL
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
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	int N,K;
	scanf(" %d %d",&N,&K);
	vector< vector<int> > eq(2*N,vector<int>(2*N,0));
	auto lt =eq; auto gt =eq; auto le =eq; auto ge =eq;
	for(int i =0; i < K; i++) {
		int a,b;
		char ch[5];
		scanf(" %d %s %d",&a,ch,&b);
		string s =(string)ch;
		if(s[0] == '=') eq[a-1][b-1] =eq[b-1][a-1] =1;
		if(s[0] == '<') {
			if(s.length() == 1) lt[a-1][b-1] =gt[b-1][a-1] =1;
			else le[a-1][b-1] =ge[b-1][a-1] =1;}
		if(s[0] == '>') {
			if(s.length() == 1) gt[a-1][b-1] =lt[b-1][a-1] =1;
			else ge[a-1][b-1] =le[b-1][a-1] =1;}
		}

	vector< vector<long long> > V(2*N,vector<long long>(2*N,0));
	for(int i =0; i < 2*N-1; i++) {
		V[i][i+1] =1;
		for(int j =0; j < 2*N; j++) {
			if(j != i && j != i+1 && (eq[i][j] || le[i][j] == 1 || lt[i][j] == 1)) V[i][i+1] =0;
			if(j != i && j != i+1 && (eq[i+1][j] || le[i+1][j] == 1 || lt[i+1][j] == 1)) V[i][i+1] =0;}
		if(lt[i][i+1] || gt[i][i+1]) V[i][i+1] =0;}

	for(int k =1; k < N; k++) 
		for(int i =0; i < 2*N; i++) for(int j =i+1; j < 2*N; j++) if(V[i][j] > 0 && j-i+1 == 2*k) {
			// vlavo
			if(i > 1) {
				bool ok =true;
				if(lt[i-1][i-2] || gt[i-1][i-2]) ok =false;
				for(int l =0; l < 2*N; l++) if(ok) {
					if(l != i-1 && l != i-2) if(eq[i-1][l] == 1 || eq[i-2][l]) {ok =false; break;}
					if(l < i-2 || l > j) if(le[i-1][l] || lt[i-1][l]) {ok =false; break;}
					if(l < i-2 || l > j) if(le[i-2][l] || lt[i-2][l]) {ok =false; break;}
					if(l >= i && l <= j) if(ge[i-1][l] || gt[i-1][l]) {ok =false; break;}
					if(l >= i && l <= j) if(ge[i-2][l] || gt[i-2][l]) {ok =false; break;}
					}
				if(ok) V[i-2][j] +=V[i][j];}
			// vpravo
			if(j+2 < 2*N) {
				bool ok =true;
				if(lt[j+1][j+2] || gt[j+1][j+2]) ok =false;
				for(int l =0; l < 2*N; l++) if(ok) {
					if(l != j+1 && l != j+2) if(eq[j+1][l] == 1 || eq[j+2][l]) {ok =false; break;}
					if(l < i || l > j+2) if(le[j+1][l] || lt[j+1][l]) {ok =false; break;}
					if(l < i || l > j+2) if(le[j+2][l] || lt[j+2][l]) {ok =false; break;}
					if(l >= i && l <= j) if(ge[j+1][l] || gt[j+1][l]) {ok =false; break;}
					if(l >= i && l <= j) if(ge[j+2][l] || gt[j+2][l]) {ok =false; break;}
					}
				if(ok) V[i][j+2] +=V[i][j];}
			// obe strany
			if(j+1 < 2*N && i > 0) {
				bool ok =true;
				if(lt[j+1][i-1] || gt[j+1][i-1]) ok =false;
				for(int l =0; l < 2*N; l++) if(ok) {
					if(l != i-1 && l != j+1) if(eq[j+1][l] == 1 || eq[i-1][l]) {ok =false; break;}
					if(l < i-1 || l > j+1) if(le[i-1][l] || lt[i-1][l]) {ok =false; break;}
					if(l < i-1 || l > j+1) if(le[j+1][l] || lt[j+1][l]) {ok =false; break;}
					if(l >= i && l <= j) if(ge[j+1][l] || gt[j+1][l]) {ok =false; break;}
					if(l >= i && l <= j) if(ge[i-1][l] || gt[i-1][l]) {ok =false; break;}
					}
				if(ok) V[i-1][j+1] +=V[i][j];}
			}

	printf("%I64d\n",V[0][2*N-1]);
	return 0;}

// look at my code
// my code is amazing