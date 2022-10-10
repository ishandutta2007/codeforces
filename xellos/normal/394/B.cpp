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
	int P,K;
	cin >> P >> K;

	vector<int> ans(P,9);
	for(int d =1; d < 10; d++) {
		vector<int> A(P,9*d);
		for(int i =0; i < P; i++) {
			if(A[i] < 10) continue;
			if(i+1 == A.size()) A.push_back(0);
			A[i+1] +=A[i]/10;
			A[i] %=10;}
		vector<int> B;
		int x =0;
		for(int i =A.size()-1; i >= 0; i--) {
			x =10*x+A[i];
			B.push_back(x/(10*K-1));
			x %=10*K-1;}
		if(x != 0) continue;
		reverse(B.begin(),B.end());
		while(B.size() >= P && B[B.size()-1] == 0) B.pop_back();
		if(B.size() != P) continue;
		reverse(B.begin(),B.end());
		ans =min(ans,B);}

	bool ok =false;
	ALL_THE(ans,it) if(*it != 9) ok =true;
	if(!ok) {cout << "Impossible\n"; return 0;}
	ALL_THE(ans,it) cout << *it;
	cout << "\n";
	return 0;}

// look at my code
// my code is amazing