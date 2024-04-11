// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 12345678901234567LL
#define patkan 9
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

int main() {
	int N,K;
	cin >> N >> K;
	vector<long long> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	
	vector<long long> sum(N-K+1,0);
	for(int i =0; i < K; i++) sum[N-K] +=A[N-1-i];
	for(int i =N-K-1; i >= 0; i--) sum[i] =sum[i+1]+A[i]-A[i+K];
	
	vector<long long> mx(N-K+2,0);
	for(int i =N-K; i >= 0; i--) mx[i] =max(mx[i+1],sum[i]);
	
	long long ans =0;
	for(int i =0; i <= N-2*K; i++) ans =max(ans,sum[i]+mx[i+K]);
	for(int i =0; i <= N-2*K; i++) if(ans == sum[i]+mx[i+K]) {
		cout << i+1 << " ";
		for(int j =i+K; j <= N-K; j++) if(ans-sum[i] == sum[j]) {
			cout << j+1 << "\n";
			return 0;}}
	return 0;}
        
// look at my code
// my code is amazing