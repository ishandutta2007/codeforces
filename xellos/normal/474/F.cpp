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
#define param vector<int>
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
	int N;
	cin >> N;
	vector< vector<int> > Sm(18,vector<int>(N));
	vector< vector<int> > Pm(18,vector<int>(N,0));
	for(int i =0; i < N; i++) {cin >> Sm[0][i]; Pm[0][i] =1;}
	vector< vector<int> > Sg =Sm;
	for(int i =1; i < 18; i++) for(int j =0; j < N; j++) if(j+(1<<i) <= N) {
		Sm[i][j] =min(Sm[i-1][j],Sm[i-1][j+(1<<(i-1))]);
		if(Sm[i-1][j] > Sm[i-1][j+(1<<(i-1))]) Pm[i][j] =Pm[i-1][j+(1<<(i-1))];
		if(Sm[i-1][j] < Sm[i-1][j+(1<<(i-1))]) Pm[i][j] =Pm[i-1][j];
		if(Sm[i-1][j] == Sm[i-1][j+(1<<(i-1))]) Pm[i][j] =Pm[i-1][j]+Pm[i-1][j+(1<<(i-1))];
		Sg[i][j] =gcd(Sg[i-1][j],Sg[i-1][j+(1<<(i-1))]);}

	int Q;
	cin >> Q;
	for(int q =0; q < Q; q++) {
		int L,R;
		cin >> L >> R;
		L--;

		int k =17, g =0, m =1000000000, p =0, a =L;
		while(k >= 0) {
			if(a+(1<<k) > R) {k--; continue;}
			g =gcd(g,Sg[k][a]);
			if(m == Sm[k][a]) p +=Pm[k][a];
			else if(m > Sm[k][a]) p =Pm[k][a];
			m =min(m,Sm[k][a]);
			a +=(1<<k);}
//		cout << g << " " << p << " " << m << " " << a << "\n";

		if(g == m) cout << R-L-p << "\n";
		else cout << R-L << "\n";}
	return 0;}

// look at my code
// my code is amazing