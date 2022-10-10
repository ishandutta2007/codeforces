// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N,M,K =2,a,b;
	cin >> N >> M;
	for(int i =0; i < N; i++) K *=2;
	vector<int> V(K);
	vector<int> typ(K,0);
	for(int i =1; i < K/2; i++) typ[2*i] =typ[2*i+1] =1-typ[i];
	for(int i =K/2; i < K; i++) cin >> V[i];
	for(int i =K/2-1; i > 0; i--) {
		if((typ[i]+N)%2 == 0) V[i] =V[2*i]^V[2*i+1];
		else V[i] =V[2*i]|V[2*i+1];}
	for(int i =0; i < M; i++) {
		cin >> a >> b;
		int akt =(K/2+a-1)>>1;
		V[K/2+a-1] =b;
		while(akt > 0) {
			if((typ[akt]+N)%2 == 0) V[akt] =V[2*akt]^V[2*akt+1];
			else V[akt] =V[2*akt]|V[2*akt+1];
			akt >>=1;}
		cout << V[1] << "\n";}
    return 0;}
        
// look at my code
// my code is amazing