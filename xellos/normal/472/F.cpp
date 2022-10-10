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
#define soclose 1e-9
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define lng long long
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> x0,y0;
	vector< vector<int> > X(N,vector<int>(30));
	vector< vector<int> > Y =X;
	for(int i =0; i < N; i++) {
		int x;
		cin >> x;
		x0.push_back(x);
		for(int j =0; j < 30; j++) X[i][j] =(x>>j)&1;}
	for(int i =0; i < N; i++) {
		int x;
		cin >> x;
		y0.push_back(x);
		for(int j =0; j < 30; j++) Y[i][j] =(x>>j)&1;}

	vector< pair<int,int> > ans;
	// base
	vector<int> B;
	vector<bool> isB(N,false);
	for(int i =0; i < 30; i++) {
		int x =-1;
		for(int j =0; j < N; j++) if(X[j][i] == 1 && !isB[j]) x =j;
		if(x == -1) continue;
		B.push_back(x); isB[x] =true;
		for(int k =0; k < N; k++) if(k != x && X[k][i] == 1) {
			ans.push_back(make_pair(k,x));
			for(int l =0; l < 30; l++) X[k][l] ^=X[x][l];}
		}

	for(int i =0; i < N; i++) {
		// is base?
		if(isB[i]) continue;
		for(int j =0; j < 30; j++) if(Y[i][j]^X[i][j]) {
			bool ok =false;
			ALL_THE(B,it) if(X[*it][j] == 1) {
				ans.push_back(make_pair(i,*it));
				for(int k =0; k < 30; k++) X[i][k] ^=X[*it][k];
				ok =true;}
			if(!ok) {cout << "-1\n"; return 0;}
			}
		}

	// base vectors
	// inverted
	vector< pair<int,int> > ans2;
	int m =B.size();
	vector< vector<int> > M(m,vector<int>(m,0));
	ALL_THE(B,it) {
		for(int i =0; i < m; i++) for(int j =0; j < 30; j++) if(X[B[i]][j]) {
			if(!Y[*it][j]) break;
			M[it-B.begin()][i] =1;
			for(int k =0; k < 30; k++) Y[*it][k] ^=X[B[i]][k];
			break;}
		for(int i =0; i < 30; i++) if(Y[*it][i]) {cout << "-1\n"; return 0;}
		}
//	for(int i =0; i < m; i++) for(int j =0; j < m; j++) cout << M[i][j] << ((j == m-1)?"\n":"");
	// GEM
	vector<bool> piv(m,false);
	for(int i =0; i < m; i++) {
		int x =-1;
		for(int j =0; j < m; j++) if(M[j][i] && !piv[j]) x =j;
		if(x == -1) continue;
		piv[x] =true;
		for(int j =0; j < m; j++) if(j != x && M[j][i]) {
			ans2.push_back(make_pair(B[j],B[x]));
			for(int k =0; k < m; k++) M[j][k] ^= M[x][k];}
		}
	for(int i =0; i < m; i++) {
		int x =-1;
		for(int j =i; j < m; j++) if(M[j][i]) x =j;
		if(x == -1 || x == i) continue;
		ans2.push_back(make_pair(B[i],B[x]));
		ans2.push_back(make_pair(B[x],B[i]));
		ans2.push_back(make_pair(B[i],B[x]));
		swap(M[i],M[x]);}
//	for(int i =0; i < m; i++) for(int j =0; j < m; j++) cout << M[i][j] << ((j == m-1)?"\n":"");
	for(int i =0; i < m; i++) {
		for(int j =0; j < i; j++) if(M[j][i]) ans.push_back(make_pair(B[j],B[i]));
		if(!M[i][i]) ans.push_back(make_pair(B[i],B[i]));}

	reverse(ans2.begin(),ans2.end());
	ALL_THE(ans2,it) ans.push_back(*it);
	cout << ans.size() << "\n";
	ALL_THE(ans,it) {
		cout << it->ff+1 << " " << it->ss+1 << "\n";
		x0[it->ff] ^=x0[it->ss];}
	return 0;}

// look at my code
// my code is amazing