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
	int N,M;
	cin >> N >> M;
	if(N > M) {
		cout << M+1 << "\n";
		for(int i =0; i <= M; i++) cout << i << " " << M-i << "\n";}
	else {
		cout << N+1 << "\n";
		for(int i =0; i <= N; i++) cout << N-i << " " << i << "\n";}		
    return 0;}
        
// look at my code
// my code is amazing