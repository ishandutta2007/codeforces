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
#include <iomanip>
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

struct frac { // x/y
	int x,y,id;

	frac() {}
	frac(int a, int b, int c) {x =a, y =b, id =c;}
	
	bool operator<(const frac &F) const {
		return x*F.y > y*F.x;}
	};

int main() {
	int N;
	cin >> N;
	vector<int> L(N);
	vector<int> P(N);
	vector<frac> V(N);
	for(int i =0; i < N; i++) {
		cin >> L[i] >> P[i];
		V[i] =frac(L[i]*P[i],100-P[i],i);}
	
	sort(V.begin(),V.end());
	long long ans =0, s =0;
	for(int i =0; i < N; i++) {
		ans +=s*V[i].y;
		s +=V[i].x;}
	for(int i =0; i < N; i++) ans +=L[i]*10000;
	cout << fixed << setprecision(10) << (double)(ans)/10000.0 << "\n";
    return 0;}
        
// look at my code
// my code is amazing