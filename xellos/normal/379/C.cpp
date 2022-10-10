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
	vector< pair<int,int> > A(N);
	for(int i =0; i < N; i++) {
		cin >> A[i].ff;
		A[i].ss =i;}
	sort(A.begin(),A.end());

	vector<int> R(N);
	vector<int> S(N);
	for(int i =0; i < N; i++) {
		R[i] =A[i].ff;
		if(i > 0) R[i] =max(R[i],R[i-1]+1);
		S[A[i].ss] =R[i];}

	for(int i =0; i < N; i++) cout << S[i] << ((i == N-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing