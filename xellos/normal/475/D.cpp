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
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
using namespace std;
// mylittledoge

int gcd(int x, int y) {
	if(x > y) swap(x,y);
	while(x > 0) {
		int z =x;
		x =y%x;
		y =z;}
	return y;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,Q;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	vector< vector<int> > T(18,vector<int>(N,-1));
	T[0] =A;
	for(int i =1; i < 18; i++) for(int j =0; j < N; j++) if(j+(1<<i) <= N) 
		T[i][j] =gcd(T[i-1][j],T[i-1][j+(1<<(i-1))]);

	map<int,long long> M;
	int t =0;
	for(int i =0; i < N; i++) {
		int g =A[i], a =i;
		while(a < N) {
			t++;
			int b =a, k =17;
			while(k >= 0) {
//				if(b+(1<<k) <= N) cout << b << " " << k << " " << T[k][b] << ".\n";
				if(b+(1<<k) > N || T[k][b]%g != 0) {k--; continue;}
				b +=(1<<k);}
//			cout << i << " " << g << " " << a << " " << b << "\n";
			M[g] +=b-a;
			a =b;
			if(b < N) g =gcd(g,A[b]);}
		}

	cin >> Q;
	for(int q =0; q < Q; q++) {
		int x;
		cin >> x;
		if(M.find(x) == M.end()) cout << "0\n";
		else cout << M[x] << "\n";}
	return 0;}

// look at my code
// my code is amazing