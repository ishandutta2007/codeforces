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

bool ok(vector<int> &A, int c) {
	int N =A.size();
	if(c*2 > N) return false;
	for(int i =0; i < c; i++) if(A[N-c+i] < 2*A[i]) return false;
	return true;}

int main() {
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	sort(A.begin(),A.end());

	int a =0, b =N;
	while(b-a > 1) {
		int c =(a+b)/2;
		if(ok(A,c)) a =c;
		else b =c;}
	cout << N-a << "\n";
	return 0;}

// look at my code
// my code is amazing