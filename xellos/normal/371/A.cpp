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
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-11
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N,K,a;
	cin >> N >> K;
	vector<int> A(K,0);
	for(int i =0; i < N; i++) {
		cin >> a;
		if(a == 1) A[i%K]++;}

	a =0;
	for(int i =0; i < K; i++) a +=min(A[i],N/K-A[i]);
	cout << a << "\n";
	return 0;}

// look at my code
// my code is amazing