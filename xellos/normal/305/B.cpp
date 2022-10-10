// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 123456789012345678LL
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define uint unsigned int
#define ff first
#define ss second
#define abs(x) ((x < 0)?(-x):x)
#define exit() {printf("NO\n"); return 0;}
#define mod 1000000007
// mylittlepony
using namespace std;

int main() {
	int N;
	long long P,Q,a;
	cin >> P >> Q >> N;
	vector<long long> cf;
	while(Q > 0) {
		cf.push_back(P/Q);
		P %=Q;
		swap(P,Q);}

	vector<long long> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	while(N > 1) {
		if(A[N-1] != 1) break;
		A[N-2] +=1;
		N--;}
	A.resize(N);
	if(cf != A) printf("NO\n");
	else printf("YES\n");
	return 0;}
        
// look at my code
// my code is amazing