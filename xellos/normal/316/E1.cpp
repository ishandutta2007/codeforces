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

struct fin {
	vector<long long> T;

	fin(int N) {
		T.resize(N+1,0);}
	
	int lastone(int x) {
		return x&(x^(x-1));}
	
	long long get(int pos) {
		long long ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
		return ret;}
	
	void put(int pos, int val) {
		for(int i =pos+1; i < T.size(); i++) T[i] +=val;}
	};

int main() {
    int N,M;
    cin >> N >> M;
    
    vector<long long> fib(N,1);
    for(int i =2; i < N; i++) fib[i] =(fib[i-1]+fib[i-2])%1000000000;
    
    vector<long long> A(N);
    for(int i =0; i < N; i++) cin >> A[i];
	
	for(int i =0; i < M; i++) {
		int t,x,y;
		long long a;
		cin >> t;
		if(t == 2) {
			cin >> x >> y;
			long long ans =0;
			for(int j =x-1; j < y; j++) ans =(ans+fib[j-x+1]*A[j])%1000000000;
			cout << ans << "\n";
			continue;}
		cin >> x >> a;
		A[x-1] =a;}
	return 0;}
        
// look at my code
// my code is amazing