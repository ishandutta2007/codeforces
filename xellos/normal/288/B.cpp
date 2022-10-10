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
#define M 1000000007
// mylittlepony
using namespace std;
using namespace std::tr1;

int main() {
	int N,K;
	cin >> N >> K;
	long long ans =1;
	for(int i =K; i < N; i++) {
		ans =(ans*(N-K))%M;
		if(ans < 0) ans +=M;}
	for(int i =0; i < K-1; i++) {
		ans =(ans*K)%M;
		if(ans < 0) ans +=M;}
	cout << ans << endl;
    return 0;}
        
// look at my code
// my code is amazing