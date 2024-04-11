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
using namespace std::tr1;

int main() {
	int N;
	cin >> N;
	N++;
/*	vector<int> P(N);
	for(int i =0; i < N; i++) P[i] =i;
	while(true) {
		int akt =0;
		for(int i =0; i < N; i++) akt +=(P[i]^i);
		if(akt == N*(N-1)) {
			for(int i =0; i < N; i++) cout << (P[i]^i) << " ";
			cout << endl;}
		if(!next_permutation(P.begin(),P.end())) break;}
*/
	cout << (long long)(N)*(long long)(N-1) << endl;
	vector<bool> uz(N,false);
	vector<int> P(N);
	int a =1;
	while(a < N) a *=2;
	for(int i =N-1; i >= 0; i--) {
		while(true) {
			if((i^(a-1)) < N) if(!uz[i^(a-1)]) {
				uz[(i^(a-1))] =true;
				P[i] =(i^(a-1));
				break;}
			a /=2;}
		}
	for(int i =0; i < N; i++) {
		if(i > 0) cout << " ";
		cout << P[i];}
	cout << endl;
    return 0;}
        
// look at my code
// my code is amazing