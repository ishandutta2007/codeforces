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
	int N,a;
	cin >> N;
	vector<int> A(N);
	vector< vector<int> > bit(N, vector<int>(32,0));
	for(int i =0; i < N; i++) {
		cin >> a; A[i] =a;
		for(int j =0; j < 32; j++) {
			bit[i][j] =(int)(a%2 != 0);
			a /=2;}}
		
	for(int i =32; i >= 0; i--) {
		vector<int> F(32,0);
		for(int j =0; j < N; j++) if(bit[j][i] == 1) 
			for(int k =i-1; k >= 0; k--) if(bit[j][k] == 0) F[k]++;
		bool ok =true;
		for(int k =i-1; k >= 0; k--) if(F[k] == 0) ok =false;
		if(ok) {
			vector<int> ans;
			for(int j =0; j < N; j++) if(bit[j][i] == 1) ans.push_back(A[j]);
			cout << (int)ans.size() << "\n";
			for(int j =0; j < ans.size(); j++) cout << ans[j] << ((j == ans.size()-1)?"\n":" ");
			return 0;}
		}
    return 0;}
        
// look at my code
// my code is amazing