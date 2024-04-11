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
#define exit(x) {cout << x; return 0;}
// mylittlepony
using namespace std;
using namespace std::tr1;

int main() {
	int N,K;
	cin >> N >> K;
	if(K > N) exit("-1\n");
	if(K == 1) {
		if(N > 1) cout << "-1\n";
		else cout << "a\n";
		return 0;}
	for(int i =0; i < N-K+2; i++) {
		if(i%2 == 0) cout << "a";
		else cout << "b";}
	for(int i =2; i < K; i++) cout << (char)('a'+i);
	cout << endl;	
    return 0;}
        
// look at my code
// my code is amazing