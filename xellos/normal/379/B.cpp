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
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];

	while(true) {
		bool b =true;
		for(int i =0; i < N; i++) if(A[i] != 0) b =false;
		if(b) break;
		if(A[0] > 0) {cout << "P"; A[0]--;}
		for(int i =1; i < N; i++) {
			cout << "R";
			if(A[i] > 0) {A[i]--; cout << "P";}}
		for(int i =1; i < N; i++) cout << "L";}
	cout << "\n";
	return 0;}

// look at my code
// my code is amazing