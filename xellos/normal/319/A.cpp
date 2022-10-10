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
	string X;
	cin >> X;
	int N =X.length();
	
	long long ans =0;
	vector<long long> pow(2*N,1);
	for(int i =0; i < 2*N-1; i++) pow[i+1] =(pow[i]*2)%1000000007;
	
	for(int i =0; i < N; i++) {
		// i-ty bit a je 0, c je 1
		// X[i] == 1, vsetky pary (2^(2N-2-i))
		if(X[i] == '1') ans =(ans+pow[2*N-2-i])%1000000007;}
	cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing