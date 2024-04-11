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
using namespace std::tr1;

int abs(int x) {return (x < 0)?(-x):x;}

int main() {
	int N,K;
	cin >> N >> K;
	int k =0;
	for(int i =0; i < N; i++) for(int j =i+1; j < N; j++) k++;
	if(k <= K) cout << "no solution\n";
	else for(int i =0; i < N; i++) cout << "0 " << i << "\n";
    return 0;}
        
// look at my code
// my code is amazing