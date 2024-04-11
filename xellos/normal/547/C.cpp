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
using namespace std;
// mylittledoge

int gcd(int x, int y) {
	if(x > y) swap(x,y);
	return (x == 0)?y:gcd(y%x,x);}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,Q;
	cin >> N >> Q;
	vector<int> minD(500000+tisic,-1);
	for(int i =2; i <= 500000; i++) if(minD[i] == -1) {
		minD[i] =i;
		for(int j =i; j <= 500000/i; j++) 
			if(minD[i*j] == -1) minD[i*j] =i;
		}

	vector<int> D(500000+tisic,0);
	vector< vector<int> > P(N);
	for(int i =0; i < N; i++) {
		int a;
		cin >> a;
		while(a > 1) {
			int p =minD[a];
			P[i].push_back(p);
			while(a%p == 0) a /=p;}
		int n =P[i].size();
		for(int j =0; j < (1<<n); j++) {
			int p =1, sig =0;
			for(int k =0; k < n; k++) if((j>>k)&1) {
				p *=P[i][k];
				sig++;}
			}
//			D[p] +=(sig%2 == 0)?1:-1;}
		}


	long long ans =0;
//	for(int i =0; i <= 500000; i++) ans +=D[i]*(abs(D[i])-1)/2;
	vector<bool> live(N,false);
	for(int q =0; q < Q; q++) {
		int x;
		cin >> x;
		int n =P[--x].size();
		for(int j =0; j < (1<<n); j++) {
			int p =1, sig =live[x];
			for(int k =0; k < n; k++) if((j>>k)&1) {
				p *=P[x][k];
				sig++;}
			ans -=1LL*D[p]*(abs(D[p])-1)/2;
			D[p] +=(sig%2 == 0)?1:-1;
			ans +=1LL*D[p]*(abs(D[p])-1)/2;}
		live[x] =!live[x];
		cout << ans << "\n";}
	return 0;}

// look at my code
// my code is amazing