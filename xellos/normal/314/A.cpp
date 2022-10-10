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
#define dibs reserve
#define OVER9000 123456789012345678LL
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define uint unsigned int
#define ff first
#define ss second
#define abs(x) ((x < 0)?(-x):x)
// mylittlepony
using namespace std;

int main() {
	int N,K;
	cin >> N >> K;
	vector<long long> R(N+1);
	for(int i =1; i <= N; i++) cin >> R[i];
	long long drA =0, rem =0;
	vector<int> Rem;
	for(int i =1; i <= N; i++) {
		long long dr =drA-(long long)(N-i)*R[i]*(i-rem-1);
//		cout << dr << "\n";
		if(dr < K) {
			rem++;
			Rem.push_back(i);}
		else drA +=R[i]*(i-rem-1);}
	for(int i =0; i < (int)Rem.size(); i++) cout << Rem[i] << "\n";
	return 0;}
        
// look at my code
// my code is amazing